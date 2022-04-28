#include "queue.h"
#include "sort.h"
#include "comparator.h"
#include <fstream>
#include <iostream>
#include <sstream> 



int main(){

    Comparator cmp;
    const int tab_size = 10;
    std::string line;
    std::ifstream file("dane.csv");
    if(!file.is_open()) throw std::runtime_error("Could not open file");

    std::getline(file, line);
    std::string name;
    int rank;
    std::string temp;
    Queue data;

    for(int i = 0 ; i < tab_size ; i++){
        getline(file, line);
        std::istringstream iss(line);

        std::getline(iss, temp, ',');
        std::getline(iss, name, ',');
        std::getline(iss, temp);
        rank = stoi(temp);

        data.InsertEnd(Package(name, rank));
        
    }
        Queue S1, S2;
        Divide(data,&S1,&S2,6);
/*         std::cout << "S1" << std::endl << S1;
        std::cout << "S2" << std::endl << S2; */
        Merge(&data,S1,S2);

        //MergeSort(&data, cmp);
        std::cout << "S1" << std::endl << S1;
        std::cout << data;
        std::cout << data.Size();
 }