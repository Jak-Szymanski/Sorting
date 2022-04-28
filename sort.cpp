#include "sort.h"


/* void SetUpMergeSort(Package *arr[]){
    MergeSort(arr,0,sizeof(*arr) - 1);
} */

void MergeSort(Package arr[], int start, int end, Comparator cmp){


    int pivot;
    if (start < end){
        //std::cout << "elo" << std::endl;
        pivot = (start + end)/2;
      //  std::cout << pivot << std::endl;
        MergeSort(arr, start, pivot, cmp);
        MergeSort(arr, pivot+1, end, cmp);
        Merge(arr, start, pivot, end, cmp);
    }
}

/* void Merge(Package arr[], int start, int pivot, int end){

    std::cout << "bruh" << std::endl;
    Package *tmp_arr = new Package[(end - start)];
    int i = start;
    int j = pivot+1;
    int k = 0;

    while (i <= pivot && j <= end){
        if (arr[i] < arr[j]){
            tmp_arr[k] = arr[j];
            std::cout << tmp_arr[k];
            j++;
        } else{
            tmp_arr[k] = arr[i];
            std::cout << tmp_arr[k];
            i++;
        }
        k++;            arr[k] = M[j];
            j++;
    }

    if(i <= pivot){
        while(i <= pivot){
            tmp_arr[k] = arr[i];
            i++;
            k++;
        }
    } else {
        while(j <= end){
            tmp_arr[k] = arr[j];
            j++;
            k++;
        }
    }

    for(i = 0; i <= end-start; i++){
        arr[i] = tmp_arr[i];
        std::cout << arr[i];
    }

    std::cout << "merge" << std::endl;

} */

void Merge(Package arr[], int start, int pivot, int end, Comparator cmp){
    int n1 = pivot - start +1;
    int n2 = end - pivot;

    Package *L = new Package[n1];
    Package *M = new Package [n2];

    for (int i=0; i<n1; i++){
        L[i] = arr[start + i];
    }
    for(int j=0; j<n2; j++){
        M[j] = arr[pivot + 1 +j];
    }

    int i=0;
    int j=0;
    int k=start;

    while(i<n1 && j<n2){
        if(cmp(L[i], M[j])){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = M[j];
        j++;
        k++;
    }
}