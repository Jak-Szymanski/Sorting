#include "queue.h"


Queue::Queue(){
  Head = NULL;  
  Tail = NULL;
}

void Queue::InsertFront(Package new_pack){

  Node *tmp = new Node(new_pack);

  
  tmp->Next = Head;
  if (IsEmpty()){ 
    Tail = tmp;
  } else {
    tmp->Next->Prev = tmp;
  }
  Head = tmp;

}

void Queue::InsertEnd(Package new_pack){

  Node *tmp = new Node(new_pack);

  tmp->Prev = Tail;
  if (IsEmpty()){
    Head = tmp;
  } else {
    tmp->Prev->Next = tmp;
  }
  Tail = tmp;
}

int Queue::Size() const{

  if(IsEmpty()) return 0;

  int size = 1;
  Node *tmp = Head;
  
  while(tmp->Next != NULL){
    tmp = tmp->Next;
    size++;
  }

  return size;
}


std::ostream &operator << (std::ostream &out, Queue const &queue){

  if(queue.IsEmpty()){
    out << "Kolejka jest pusta" << std::endl;
    return out;
  }

  Node *tmp = queue.GetHead();
  while(tmp->GetNext() != NULL){
    out << tmp->GetElem();
    tmp = tmp->GetNext();
  }
  out << tmp->GetElem(); 
  return out;
}

Package Queue::RemoveFirst(){

  if(IsEmpty()){
    throw "Proba usuniecia elementu z pustej kolejki!";
  }

  Node *ptr = Head;
  Package first = ptr->Elem;
  Head = Head->Next;
  if(Head){
    Head->Prev = NULL;
  } else {
    Tail = NULL;
  }
  delete ptr;
  return first;
}

Package Queue::RemoveLast(){

  if(IsEmpty()){
    throw "Proba usuniecia elementu z pustej kolejki!";
  }

  Node *ptr = Tail;
  Package last = ptr->Elem;
  Tail = Tail->Prev;
  if(Tail){
    Tail->Next = NULL;
  } else {
    Head = NULL;
  }

  delete ptr;
  return last;
}

Package Queue::Remove(int n){
  if(IsEmpty()){
    throw "Próba usunięcia elementu z pustej kolejki!";
  }
  if(n < 0){
    throw "Próba usunięcia nieistniejącego elementu!";
  }
  if (n==0){
    return RemoveFirst();
  }

  Node *ptr = Head;
  for(int i=0; i<n-1; i++){
    if(ptr->Next == NULL){
      throw "Próba usunięcia nieistniejącego elementu!";
    }
    ptr = ptr->Next;
  }
  Package pack = ptr->Next->Elem;
  if(ptr->Next->Next == NULL){
    Tail = ptr;
    ptr->Next = NULL;
  } else {
  ptr->Next->Next->Prev = ptr->Next;
  ptr->Next = ptr->Next->Next;
  }
  return pack;
}

void Queue::Delete(){

  Node *ptr = Head;
  Node *next;
  Head = NULL;

  while(ptr != NULL){
    next = ptr->Next;
    free(ptr);
    ptr = next;
  }
}

void Queue::PrintEnd(){

  if(IsEmpty()){
    std::cout << "Kolejka jest pusta" << std::endl;
    return;
  }

  Node *tmp = GetTail();
  while(tmp->GetPrev() != NULL){
    std::cout << tmp->GetElem();
    tmp = tmp->GetPrev();
  }
  std::cout << tmp->GetElem(); 
}
