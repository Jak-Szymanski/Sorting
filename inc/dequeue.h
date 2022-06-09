#pragma once

#include "node.h"
#define PACK_LENGTH 5

class Dequeue{

  private:
  
    Node *Head;

    Node *Tail;

  public:

    Dequeue();

    //~Dequeue() {if(!IsEmpty()) Delete();};

    void InsertFront(Package new_pack);

    void InsertEnd(Package new_pack);

    Package RemoveFirst();

    Package RemoveLast();

    Package Remove(int n);

    int Size() const;

    void Delete();

    bool IsEmpty() const {return !Head;};

    bool IsSorted() const;

    Node * const GetHead() const{return Head;};

    Node * const GetTail() const{return Tail;};

    void SetHead(Node *new_head){Head = new_head;};

    void SetTail(Node *new_tail){Tail = new_tail;};

    void PrintEnd();

    Dequeue &operator = (const Dequeue &other);

    double Average() const;

    double Median() const;
};

void BucketSort(Dequeue *S, int N);

std::ostream &operator << (std::ostream &out, Dequeue const &queue);

