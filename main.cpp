#include "package.h"
#include "sort.h"
#include <fstream>
#include <iostream>
#include <sstream> 



int main(){

    const int tab_size = 10;
    std::string line;
    std::ifstream file("dane.csv");
    if(!file.is_open()) throw std::runtime_error("Could not open file");

    std::getline(file, line);
    std::string name;
    int rank;
    std::string temp;
    Package *data = new Package[tab_size];

    for(int i = 0 ; i < tab_size ; i++){
        getline(file, line);
        std::istringstream iss(line);

        std::getline(iss, temp, ',');
        std::getline(iss, name, ',');
        std::getline(iss, temp);
        rank = stoi(temp);

        data[i] = Package(name, rank);
        
    }

    MergeSort(data, 0, tab_size-1);
    //bruh(data);
    for(int i=0; i<tab_size; i++){
        std::cout << data[i];
    }
}