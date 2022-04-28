#pragma once
#include "package.h"
#include "comparator.h"

void MergeSort(Package arr[], int start, int end, Comparator cmp);
void Merge(Package arr[], int start, int pivot, int end, Comparator cmp);