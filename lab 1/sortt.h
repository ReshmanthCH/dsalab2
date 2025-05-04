#include<stdio.h>

#ifndef SORT_H
#define SORT_H

void bubbleSort(int arr[],int n){
    int i,j,temp;
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            //swap the two numbers if the previous index is greater
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
        }
    }
}
}

//using selection sort
void selectionSort(int arr[], int n){
    int i,j,minIndex,temp;
    for(i=0;i<n-1;i++){
        minIndex = i;
    for(j=i+1;j<n;j++){
        if(arr[j]<arr[minIndex]){
            minIndex = j;
        }
    }
    if(arr[minIndex]=arr[i]){
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
}

//using insertion sort
void insertionSort(int arr[], int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key = arr[i];
        j=i-1;
      while(j>=0&&arr[j]>key){
        arr[j+1] = arr[j];
        j=i-1;
       }
       arr[j+1]=key;
    }
}

void printArray(int arr[],int size){
for(int i=0;i<size;i++){
    printf("%d ", arr[i]);
}
printf("\n");
}

#endif