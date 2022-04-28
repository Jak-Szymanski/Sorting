#include "comparator.h"

bool Comparator::operator()(Package a, Package b){
    return a.GetKey() > b.GetKey();
}