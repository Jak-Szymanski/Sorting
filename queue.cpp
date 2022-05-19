#include "queue.h"


Queue::Queue(){
  Head = NULL;  
  Tail = NULL;
}

/* Wstaw nowy element na początek kolejki*/
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

/* Wstaw nowy element na koniec kolejki */
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

/* Zwróć rozmiar kolejki */
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

/* Wyświetlanie kolejki */
std::ostream &operator << (std::ostream &out, Queue const &queue){

  if(queue.IsEmpty()){
    out << "Kolejka jest pusta" << std::endl;
    return out;
  }

  Node *ptr = queue.GetHead();
  while(ptr->GetNext() != NULL){
    out << ptr->GetElem();
    ptr = ptr->GetNext();
  }
  out << ptr->GetElem(); 
  return out;
}

/* Usuń i zwróć pierwszy element */
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
  return first;
}

/* Usuń i zwróć ostatni element */
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
  return last;
}

/* Usuń i zwróć n-ty element */
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

/* Wyczyść całą kolejkę */
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

/* Wyświetl całą kolejkę idąc od końca
(funkcja była używana jedynie do testów poprawności działania kolejki w obu kierunkach) */
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

/* Operator kopiowania */
Queue &Queue::operator = (const Queue &other){

  if (this == &other) return *this;

  Delete();

  Node *tmp = other.GetHead();
 while(tmp->Next != NULL) {
    InsertEnd(tmp->Elem);
    tmp = tmp->Next;
  } 
  InsertEnd(tmp->Elem);
  return *this;
}

/* Czy kolejka jest posortowana */
bool Queue::IsSorted() const {
  if (IsEmpty()) return true;

  Node *ptr = Head;
  int tmp = ptr->GetKey();
  while(ptr->Next != NULL){
    if (ptr->Next->GetKey() < tmp) return false;
    ptr = ptr->Next;
    tmp = ptr->GetKey();
  }
  return true;
}

/* Zwróć średnią wartość ocen w kolejce */
double Queue::Average() const{

  if (IsEmpty()) return 0.0;
  Node *ptr = Head;
  double avg = 0.0;
  int size = 0;
  

  while(ptr != NULL){
    avg += ptr->GetKey();
    size++;
    ptr = ptr->GetNext();
    
  }
  return avg/size;
}

/* Zwróć medianę wartości ocen w kolejce */
double Queue::Median() const{

  if (IsEmpty()) return 0; 

  Node *ptr;
  int size = Size();

  if(size == 1) return Head->GetKey();
  int n = size/2;

  if(!IsSorted()){
    Queue tmp;
    tmp = *this;
    BucketSort(&tmp,10);
    ptr = tmp.GetHead();
  } else {
    ptr = GetHead();
  }
 
  for(int i=0;i<n-1;i++){
    ptr = ptr->Next;
  }

  if(size%2 == 0) return (ptr->GetKey() + ptr->Next->GetKey())/2.0;
  else return ptr->Next->GetKey();
}
