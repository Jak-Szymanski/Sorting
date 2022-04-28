#include "sort.h"

/* void SetUpMergeSort(Package *arr[]){
    MergeSort(arr,0,sizeof(*arr) - 1);
} */

void MergeSort(Package arr[], int start, int end){

    int pivot;
    if (start != end){
        //std::cout << "elo" << std::endl;
        pivot = (start + end)/2;
        MergeSort(arr, start, pivot);
        MergeSort(arr, pivot+1, end);
        Merge(arr, start, pivot, end);

    } else {
        //std::cout << "bruh" << std::endl;
    }

}

void Merge(Package arr[], int start, int pivot, int end){

    std::cout << "bruh" << std::endl;
    Package *tmp_arr = new Package[end - start];
    int i = start;
    int j = pivot;
    int k = 0;

    while (i <= pivot && j <= end){
        if (arr[i] < arr[j]){
            tmp_arr[k] = arr[j];
            tmp_arr[k].Print();
            j++;
        } else{
            tmp_arr[k] = arr[i];
            i++;
        }
        k++;
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
        arr[i].Print();
    }

    std::cout << "merge" << std::endl;

}