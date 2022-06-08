#pragma once
#include "dequeue.h"

/* ----------------------------------------
Sortowanie przez scalanie: */
void Merge(Dequeue *S, Dequeue S1, Dequeue S2);
void MergeSort(Dequeue *S);
void Divide(Dequeue *S, Dequeue *S1, Dequeue *S2, int n);


/* ----------------------------------------
Sortowanie szybkie: */
void QuickSort(Dequeue *S);
void Partition(Dequeue *S, int p,Dequeue *L, Dequeue *E, Dequeue *G);
void Add(Dequeue *S, Dequeue *L, Dequeue *E, Dequeue *G);

/* ----------------------------------------
Sortowanie kubełkowe: */
void BucketSort(Dequeue *S, int N);