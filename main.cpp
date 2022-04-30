#include "queue.h"
#include "sort.h"
#include "comparator.h"
#include <fstream>
#include <iostream>
#include <sstream> 



int main(){

    Comparator cmp;
    const int tab_size = 13;
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

        QuickSort(&data);
        std::cout << "data" << std::endl << data;

/*         Queue L,E,G;
        Partition(&data,12,&L,&E,&G);
        std::cout << "data" << std::endl << data;
        std::cout << "L" << std::endl << L;
        std::cout << "E" << std::endl << E;
        std::cout << "G" << std::endl << G;
        Add(&data,&L,&E,&G);
        std::cout << "data" << std::endl << data; */


 }