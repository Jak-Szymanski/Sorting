#pragma once
#include "queue.h"
#include "comparator.h"

void MergeSort(Queue *S);
void Divide(Queue *S, Queue *S1, Queue *S2, int n);
void Merge(Queue *S, Queue S1, Queue S2);

void Partition(Queue *S, int p,Queue *L, Queue *E, Queue *G);
void QuickSort(Queue *S);
void Add(Queue *S, Queue *L, Queue *E, Queue *G);

void BucketSort(Queue *S, int N);