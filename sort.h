#pragma once
#include "queue.h"
#include "comparator.h"

void MergeSort(Queue *S, Comparator C);
void Divide(Queue S, Queue *S1, Queue *S2, int n);
/* void QuickSort(Package arr[], int start, int end, Comparator cmp);
void Partition(Package arr[], int pivot); */
void Merge(Queue *S, Queue S1, Queue S2);
//void bruh(Queue *S);