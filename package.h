#pragma once

#include <iostream>
#include <string>

class Package{

    private:

        std::string Message;

        int Key;        

    public:

        Package();

        Package(std::string message, int key);

        int GetKey(){return Key;};

        void Print();

        bool operator < (Package pack){return this->Key < pack.Key;};
};