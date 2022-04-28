#pragma once

#include "package.h"
#include <string>
#include <fstream> 
#include <iostream>

class Node{

  private:

    Package Elem;

    Node *Next;

    Node *Prev;
  
  public:

    Node();

    Node(Package new_elem);

    int GetKey() const{return Elem.Key;};

    std::string GetMessage() const{return Elem.Message;};

    Node * const GetNext() const{return Next;};

    Node * const GetPrev() const{return Prev;};

    Package GetElem() const{return Elem;};

    void SetNext(Node *new_next){Next = new_next;};

    void SetPrev(Node *new_prev){Prev = new_prev;};

    //void ClearNext(){Next = NULL;};


    friend class Queue;


};




