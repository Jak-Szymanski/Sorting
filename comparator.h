#pragma once

#include "package.h"

class Comparator{
    public:
        bool operator()(Package a, Package b);
};