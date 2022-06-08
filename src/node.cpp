#include "../inc/node.h"

Node::Node(){
  Elem = Package();
  Next = NULL;
  Prev = NULL;
}

Node::Node(Package new_elem){
  Elem = new_elem;
  Next = NULL;
  Prev = NULL;
}