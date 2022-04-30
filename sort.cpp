#include "sort.h"


/* void bruh(Queue S, Queue *S1){
    Package tmp;
    tmp = S.RemoveFirst();
    S1->InsertEnd(tmp);
} */

void Divide(Queue *S, Queue *S1, Queue *S2, int n){         

    if(n > S->Size()) return;

    for(int i=0; i<n; i++){
        S1->InsertEnd(S->RemoveFirst());
    }
    while(!S->IsEmpty()){
        S2->InsertEnd(S->RemoveFirst());
    }
}

void MergeSort(Queue *S){

    Queue S1, S2;
    int n = S->Size();
    if (n > 1){
        Divide(S, &S1, &S2, n/2);
        MergeSort(&S1);
        MergeSort(&S2);
        Merge(S, S1, S2);
    } 

}


void Merge(Queue *S, Queue S1, Queue S2){

    while(!S1.IsEmpty() && !S2.IsEmpty()){
        if(S1.GetHead()->GetKey() <= S2.GetHead()->GetKey()){
            S->InsertEnd(S1.RemoveFirst());
        } else {
            S->InsertEnd(S2.RemoveFirst());
        }
    }
    while(!S1.IsEmpty()){
            S->InsertEnd(S1.RemoveFirst()); 
    }
    while(!S2.IsEmpty()){
            S->InsertEnd(S2.RemoveFirst());
    }
}

void Partition(Queue *S, int p,Queue *L, Queue *E, Queue *G){
    Package x,y;
    x = S->Remove(p);
    E->InsertEnd(x);
    while(!S->IsEmpty()){
        y = S->RemoveFirst();
        if(y < x){
            L->InsertEnd(y);
        } else if(y == x) {
            E->InsertEnd(y);
        } else if(y > x) {
            G->InsertEnd(y);
        }
    }
}

void Add(Queue *S, Queue *L, Queue *E, Queue *G){
    while(!L->IsEmpty()){
        S->InsertEnd(L->RemoveFirst());
    }
    while(!E->IsEmpty()){
        S->InsertEnd(E->RemoveFirst());
    }
    while(!G->IsEmpty()){
        S->InsertEnd(G->RemoveFirst());
    }
}

void QuickSort(Queue *S){

    srand(time(NULL));
    int size = S->Size();
    int p;
    Queue L,E,G;
    if (size > 1){
        p = rand() % size;
        Partition(S,p,&L,&E,&G);
        QuickSort(&L);
        QuickSort(&G);
        Add(S,&L,&E,&G);
    }
}

void BucketSort(Queue *S, int N){
    
    Queue *B = new Queue[N];
    Package tmp;

    while(!S->IsEmpty()){
        tmp = S->RemoveFirst();
        B[tmp.GetKey()].InsertEnd(tmp);
    }
    for(int i=0;i<=N-1;i++){
        while(!B[i].IsEmpty()){
            S->InsertEnd(B[i].RemoveFirst());
        }
    }
}