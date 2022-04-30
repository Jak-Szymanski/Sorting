#include "queue.h"
#include "sort.h"
#include "comparator.h"
#include <fstream>
#include <iostream>
#include <sstream> 
#include <chrono>



int sort(int type, int n){

    const int tab_size = n;
    std::string line;
    std::ifstream file("dane.csv");
    if(!file.is_open()) throw std::runtime_error("Could not open file");

    std::getline(file, line);
    std::string name;
    int rank;
    std::string temp;
    Queue data;
    char tmp_char;

    for(int i = 0 ; i < tab_size ; i++){
        getline(file, line);
        std::istringstream iss(line);

        std::getline(iss, temp, ',');
         //std::cout << temp;
        tmp_char = iss.get();
        if(tmp_char == '"'){
            std::getline(iss,name,'"');
            tmp_char = iss.get();
            if(tmp_char == '"'){
                std::getline(iss,temp, '"');
                iss.get();
                name = '"' + name + '"' + '"' + temp + '"' + '"';
                std::getline(iss,temp,'"');
                name = name + temp + '"';
                iss.get();
            } else {
            name = '"' + name + '"';
            }
        } else {
            std::getline(iss, name, ',');
            name = tmp_char + name;
            
        }
        
        
        std::getline(iss, temp);
        //std::cout << "\t" << temp << std::endl;
        if(temp == "") continue;
        rank = stoi(temp);

        data.InsertEnd(Package(name, rank));
       
        
    }
    //std::cout << data;

        auto start = std::chrono::steady_clock::now();
        switch(type){
            case 1:
                MergeSort(&data);
            break;

            case 2:
                QuickSort(&data);
            break;

            case 3:
                BucketSort(&data, 11);
            break;
        }
        auto end = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();


 }

 
int main(){

    std::ofstream merge, quick, bucket;
    merge.open("merge.csv");
    for(int i=4000; i<=400000;i+=4000){
            merge << i << "," << sort(1,i) << std::endl;
    }
    //sort(1,52000);
}