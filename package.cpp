#include "package.h"

Package::Package(){
    Key = 0;
    Message = "";
}

Package::Package(std::string message, int key){
    Message = message;
    Key = key;
}

void Package::Print(){

  std::cout << "Tytul: " << Message << " Ranking: " << Key << std::endl;
}