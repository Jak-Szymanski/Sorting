#pragma once

#include "node.h"
#define PACK_LENGTH 5

class Queue{

  private:
  
    Node *Head;

    Node *Tail;

  public:

    Queue();

    void InsertFront(Package new_pack);

    void InsertEnd(Package new_pack);

    Package RemoveFirst();

    Package RemoveLast();

    Package Remove(int n);

    int Size() const;

    void Delete();

    bool IsEmpty() const {return !Head;};

    Node * const GetHead() const{return Head;};

    Node * const GetTail() const{return Tail;};

    void SetHead(Node *new_head){Head = new_head;};

    void SetTail(Node *new_tail){Tail = new_tail;};

    void PrintEnd();
};

std::ostream &operator << (std::ostream &out, Queue const &queue);

