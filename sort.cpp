#include "sort.h"

/* -------------------------------------------------------------------------------------*/
/*-----------------------Funkcje sortowania przez scalanie: */

/* Posortuj S algorytmem mergesort */
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

/* Podziel kolejkę S na kolejkę S1 zawierającą pierwsze n elementów oraz S2 zawierającą resztę */
void Divide(Queue *S, Queue *S1, Queue *S2, int n){         

    for(int i=0; i<n; i++){
        S1->InsertEnd(S->RemoveFirst());    //wstaw do S1
    }
    while(!S->IsEmpty()){
        S2->InsertEnd(S->RemoveFirst());    //reszte wstaw do S2
    }
}

/*Scal w sposób posortowany S1 i S2 do S (zakładamy że S1 i S2 są same w sobie posortowane*/
void Merge(Queue *S, Queue S1, Queue S2){

    while(!S1.IsEmpty() && !S2.IsEmpty()){      //wstawiaj po kolej mniejszy element z danej pary (S1 vs S2)
        if(S1.GetHead()->GetKey() <= S2.GetHead()->GetKey()){
            S->InsertEnd(S1.RemoveFirst());
        } else {
            S->InsertEnd(S2.RemoveFirst());
        }
    }
    while(!S1.IsEmpty()){                       //gdy S2 się pierwsze skończy to wstaw reszte z S1
            S->InsertEnd(S1.RemoveFirst()); 
    }
    while(!S2.IsEmpty()){
            S->InsertEnd(S2.RemoveFirst());     //gdy S1 się pierwsze skończy to wstaw reszte z S2
    }
}



/* -------------------------------------------------------------------------------------*/
/*-----------------------Funkcje sortowania szybkiego: */

/* Posortuj S algorytmem quicksort */
void QuickSort(Queue *S){

    srand(time(NULL));
    int size = S->Size();
    int p;
    Queue L,E,G;
    if (size > 1){
        p = rand() % size;      //weż losowy element z S
        Partition(S,p,&L,&E,&G);
        QuickSort(&L);
        QuickSort(&G);
        Add(S,&L,&E,&G);
    }
}

/* Podziel kolejkę S na elementy mniejsze (L), równe (E) i większe (G) od p-tego elementu kolejki S */
void Partition(Queue *S, int p, Queue *L, Queue *E, Queue *G){
    Package x,y;
    x = S->Remove(p);
    E->InsertEnd(x);
    while(!S->IsEmpty()){       //wstawianie do L/E/G
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

/* Połącz L, E i G do S (w takiej kolejności) */
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


/* -------------------------------------------------------------------------------------*/
/*-----------------------Funkcje sortowania kubełkowego: */

/* Posortuj S algorytmem kubełkowym (gdzie wartości mieszczą się w przedziale 1-N) */
void BucketSort(Queue *S, int N){
    
    Queue *B = new Queue[N+1];
    Package tmp;

    while(!S->IsEmpty()){                   //wstaw elementy z S do odpowiedniej komórki tablicy
        tmp = S->RemoveFirst();
        B[tmp.GetKey()].InsertEnd(tmp);
    }

    for(int i=0;i<=N;i++){                  //wstaw po kolejki elementy z tablicy do kolejki
        while(!B[i].IsEmpty()){
            S->InsertEnd(B[i].RemoveFirst());
        }
    }
}