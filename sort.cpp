#include "sort.h"


/* void bruh(Queue *S){
    S->RemoveFirst();
} */

void Divide(Queue S, Queue *S1, Queue *S2, int n){         

    if(n > S.Size()) return;
    Package tmp;

    for(int i=0; i<n; i++){
        tmp = S.RemoveFirst();
        //std::cout << "1    " << tmp;
        S1->InsertEnd(tmp);
    }
    while(!S.IsEmpty()){
        tmp = S.RemoveFirst();
        //std::cout << "2     " << tmp;
        S2->InsertEnd(tmp);
    }
}

void MergeSort(Queue *S, Comparator C){

    Queue S1, S2;
    int n = S->Size();
    if (n > 1){
        Divide(*S, &S1, &S2, n/2);
        MergeSort(&S1, C);
        MergeSort(&S2, C);
        Merge(S, S1, S2);
    } 

}

/* void QuickSort(Package arr[], int start, int end, Comparator cmp){

    srand(time(NULL));
    if(start < end){
        int pivot = rand() % (end - start);
        std::cout << pivot << std::endl;
        QuickSort(arr, start, start+pivot, cmp);
        QuickSort(arr, start+pivot+1, end, cmp);
        Merge(arr, start, pivot, end, cmp); 
    }   
}

void Partition(Package arr[], int pivot){

} */


void Merge(Queue *S, Queue S1, Queue S2){

    Package tmp;
    while(!S1.IsEmpty() && !S2.IsEmpty()){
        if(S1.GetHead()->GetKey() <= S2.GetHead()->GetKey()){
            tmp = S1.RemoveFirst();
            std::cout << "1:   " << tmp;
            S->InsertEnd(tmp);
        } else {
            tmp = S2.RemoveFirst();
            std::cout << "2:   " << tmp;
            S->InsertEnd(tmp);
        }
    }
    while(!S1.IsEmpty()){
            tmp = S1.RemoveFirst();
            std::cout << "1:   " << tmp;
            S->InsertEnd(tmp); 
    }
    while(!S2.IsEmpty()){
            tmp = S2.RemoveFirst();
            std::cout << "2:   " << tmp;
            S->InsertEnd(tmp);
    }
}