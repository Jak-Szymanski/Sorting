#include "dequeue.h"
#include "sort.h"
#include <fstream>
#include <iostream>
#include <sstream> 
#include <chrono>
#include <iomanip> 


/* Wgrywanie danych z pliku csv z tytułami filmów i ich ocenami do kolejki
Argumenty:
filename - nazwa pliku csv
n - ilość filmów które mają być wczytane
data - docelowa kolejka
Zwraca:
Czas w jakim funkcja się wykonała w microsekundach */
int LoadFromFile(std::string filename, int n, Dequeue *data){

    auto start = std::chrono::steady_clock::now();
    std::string line;
    std::ifstream file(filename);
    std::string name;
    int rank;
    std::string temp;
    char tmp_char;
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
    return std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
}


/* Posortuj dane z kolejki odpowiednim algorytmem
Argumenty:
type - rodzaj algorytmu sortowania (1/2/3)
data - kolejka z danymi do sortowania
Zwraca:
Czas w jakim funkcja się wykonała w microsekundach */
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
        return std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
 }

 
int main(){

    Dequeue data, tmp;
    std::ofstream outputfile;
    
    //----TEST O() MERGESORT------

/*     outputfile.open("merge2.csv");
    for(int i=4000; i<=400000;i+=4000){
            LoadFromFile("dane.csv", i, &data);
            outputfile << i << "," << Sort(1,&data) << std::endl;
            data.Delete();
    } */


    //----TEST O() QUICKSORT------

/*     outputfile.open("quick.csv");
    for(int i=4000; i<=400000;i+=4000){
            LoadFromFile("dane.csv", i, &data);
            outputfile << i << "," << Sort(2,&data) << std::endl;
            data.Delete();
    } */

    //----DOKŁADNIEJSZY TEST O() QUICKSORT------

/*     outputfile.open("quick2.csv");
    Dequeue tmp;
    for(int i=40000; i<=40000;i+=8000){
        LoadFromFile("dane.csv", i, &data);
        for(int j=0; j<50; j++){
            tmp = data;
            outputfile << i << "," << Sort(2,&tmp) << std::endl;
            tmp.Delete();
            }
        data.Delete();
    } */

    //----TEST O() BUCKETSORT------

/*     outputfile.open("bucket.csv");
    for(int i=4000; i<=400000;i+=4000){
            LoadFromFile("dane.csv", i, &data);
            outputfile << i << "," << Sort(3,&data) << std::endl;
            data.Delete();
    }
 */

    //----TEST WCZYTYWANIA STRUKTURY------

/*     outputfile.open("loading.csv");
    outputfile << 10000 << "," << LoadFromFile("dane.csv",10000,&data) << std::endl;
    data.Delete();
    outputfile << 50000 << "," << LoadFromFile("dane.csv",50000,&data) << std::endl;
    data.Delete(); 
    outputfile << 100000 << "," << LoadFromFile("dane.csv",100000,&data) << std::endl;
    data.Delete(); 
    outputfile << 200000 << "," << LoadFromFile("dane.csv",200000,&data) << std::endl;
    data.Delete(); 
    outputfile << 300000 << "," << LoadFromFile("dane.csv",300000,&data) << std::endl;
    data.Delete(); 
    outputfile << 400000 << "," << LoadFromFile("dane.csv",400000,&data) << std::endl;
    data.Delete();  */

/*     outputfile.open("test.csv");
    outputfile << "n,wczytywanie danych[us],mergesort[us],quicksort[us],bucketsort[us],średnia ocena, mediana ocen" << std::endl;
    int tab[6] = {10000,50000,100000,200000,300000,400000};
    for(int j=0; j<6;j++){
        outputfile << tab[j] << "," << LoadFromFile("dane.csv",tab[j],&data) << ",";
        tmp = data;
        outputfile << Sort(2,&tmp) << ",";
        tmp = data;
        outputfile << Sort(1,&tmp) << ",";
        tmp = data;
        outputfile << Sort(3,&tmp) << "," ;
        outputfile << std::setprecision(3) << tmp.Average()<< "," ;
        outputfile << tmp.Median() << std::endl;
        data.Delete();
       tmp.Delete();
    }
    outputfile.close(); */

    LoadFromFile("dane.csv", 400000, &data);
    std::cout << data.GetHead()->GetElem() << data.GetTail()->GetElem() << std::endl;
    tmp = data;

    std::cout << Sort(1,&tmp) << std::endl;


/*     LoadFromFile("dane.csv", 400000, &data);
    ;
    tmp = data;
    tmp.InsertFront(Package("bruh",2));
    std::cout << data.GetHead()->GetElem() << data.GetTail()->GetElem();
    std::cout << tmp.GetHead()->GetElem() << tmp.GetTail()->GetElem();

    std::cout << data << std::endl;
    Sort(1,&tmp);
    
   std::cout << data.IsSorted() << std::endl;
    data.Delete();

    LoadFromFile("dane.csv", 400000, &data);
    std::cout << data.GetHead()->GetElem() << data.GetTail()->GetElem();
    tmp = data;
    std::cout << tmp.GetHead()->GetElem() << tmp.GetTail()->GetElem(); */
}
