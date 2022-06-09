#include "../inc/sort.h"
#include <fstream>
#include <iostream> 
#include <chrono>
#include <iomanip> 


/* Wgrywanie danych z pliku csv z tytułami filmów i ich ocenami do kolejki
Argumenty:
filename - nazwa pliku csv
n - ilość filmów które mają być wczytane
data - docelowa kolejka
Zwraca:
Czas w jakim funkcja się wykonała w milisekundach */
int LoadFromFile(std::string filename, int n, Dequeue *data){

    auto start = std::chrono::steady_clock::now();
    std::string line;
    std::ifstream file;
    file.open(filename);
    std::string name;
    int rank;
    std::string temp;
    int i = 0;
    int start_pos,end_pos;
    std::getline(file,line);
    while(i<n && !file.eof()){
        getline(file,line);
        start_pos = line.find(',');
        end_pos = line.rfind(',');
        if(start_pos ==  -1|| end_pos == -1 || start_pos == end_pos)  continue;
        name = line.substr(start_pos+1, end_pos-start_pos-1);
        temp = line.substr(end_pos+1,2);
        if(temp.empty()) continue;
        rank = stoi(temp);

        data->InsertEnd(Package(name, rank));
        i++;
    }
   
    auto end = std::chrono::steady_clock::now();
    file.close();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
}


/* Posortuj dane z kolejki odpowiednim algorytmem
Argumenty:
type - rodzaj algorytmu sortowania (1/2/3)
data - kolejka z danymi do sortowania
Zwraca:
Czas w jakim funkcja się wykonała w milisekundach */
int Sort(int type, Dequeue *data){

        auto start = std::chrono::steady_clock::now();
        switch(type){
            case 1:
                MergeSort(data);
            break;

            case 2:
                QuickSort(data);
            break;

            case 3:
                BucketSort(data, 10);   //zakładamy że wartości się mieszczą w zakresie 1-10 więc funkcja Sort nie jest uniwersalna
            break;
        }
        auto end = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
 }

 
int main(){

    Dequeue data, tmp;
    std::ofstream outputfile;
    std::string outputfile_name = "./dane/test.csv";
    std::string inputfile_name = "./dane/dane.csv";


    outputfile.open(outputfile_name);
    outputfile << "n,wczytywanie danych[ms],mergesort[ms],quicksort[ms],bucketsort[ms],średnia ocena, mediana ocen" << std::endl;
    int tab[6] = {10000,50000,100000,200000,300000,400000};
    for(int i=0; i<6;i++){
	outputfile << tab[i] << ",";
	outputfile << LoadFromFile(inputfile_name,tab[i],&data) << ",";
        tmp = data;
	outputfile << Sort(1,&tmp) << ",";
        tmp = data;
       	outputfile << Sort(2,&tmp) << ",";
        tmp = data;
	outputfile << Sort(3,&tmp) << "," ;
        tmp = data;
	outputfile << std::setprecision(3) << tmp.Average()<< "," ;
       	outputfile << tmp.Median() << std::endl; 
        data.Delete();
        tmp.Delete();
    }
    outputfile.close();
}
