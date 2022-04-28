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

        int GetKey() const{return Key;};

        std::string GetMessage() const{return Message;};

        bool operator <= (Package pack){return this->Key <= pack.Key;};

        friend class Node;
};

std::ostream &operator << (std::ostream &out, Package const &pack);