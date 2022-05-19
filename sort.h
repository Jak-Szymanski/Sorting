#pragma once
#include "queue.h"

/* ----------------------------------------
Sortowanie przez scalanie: */
void MergeSort(Queue *S);
void Divide(Queue *S, Queue *S1, Queue *S2, int n);
void Merge(Queue *S, Queue S1, Queue S2);

/* ----------------------------------------
Sortowanie szybkie: */
void QuickSort(Queue *S);
void Partition(Queue *S, int p,Queue *L, Queue *E, Queue *G);
void Add(Queue *S, Queue *L, Queue *E, Queue *G);

/* ----------------------------------------
Sortowanie kubełkowe: */
void BucketSort(Queue *S, int N);