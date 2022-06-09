#include "../inc/sort.h"

/* -------------------------------------------------------------------------------------*/
/*-----------------------Funkcje sortowania przez scalanie: */



/* Podziel kolejkę S na kolejkę S1 zawierającą pierwsze n elementów oraz S2 zawierającą resztę */
void Divide(Dequeue *S, Dequeue *S1, Dequeue *S2, int n){         

    for(int i=0; i<n; i++){
        S1->InsertEnd(S->RemoveFirst());    //wstaw do S1
    }
    while(!S->IsEmpty()){
        S2->InsertEnd(S->RemoveFirst());    //reszte wstaw do S2
    }
}

/*Scal w sposób posortowany S1 i S2 do S (zakładamy że S1 i S2 są same w sobie posortowane*/
void Merge(Dequeue *S, Dequeue S1, Dequeue S2){

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

/* Posortuj S algorytmem mergesort */
void MergeSort(Dequeue *S){
    Dequeue S1, S2;
    int n = S->Size();
    if (n > 1){
        Divide(S, &S1, &S2, n/2);
        MergeSort(&S1);
        MergeSort(&S2);
        Merge(S, S1, S2);
    } 
}



/* -------------------------------------------------------------------------------------*/
/*-----------------------Funkcje sortowania szybkiego: */

/* Posortuj S algorytmem quicksort */
void QuickSort(Dequeue *S){

    Dequeue L,E,G;
    if (!S->IsEmpty()){
        Partition(S,0,&L,&E,&G);
        QuickSort(&L);
        QuickSort(&G);
        Add(S,&L,&E,&G);
    }
}

/* Podziel kolejkę S na elementy mniejsze (L), równe (E) i większe (G) od p-tego elementu kolejki S */
void Partition(Dequeue *S, int p, Dequeue *L, Dequeue *E, Dequeue *G){
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
void Add(Dequeue *S, Dequeue *L, Dequeue *E, Dequeue *G){
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
void BucketSort(Dequeue *S, int N){
    
    Dequeue *B = new Dequeue[N+1];
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
    
    delete[] B;
}