#include<stdio.h>


//using bubble sort
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

//function to print the array
void printArray(int arr[],int size){
for(int i=0;i<size;i++){
    printf("%d ", arr[i]);
}
printf("\n");
}

int main(){
    int n, choice;
    printf("enter the number of elements of array:");
    scanf("%d", &n);

    int arr[n];
    printf("enter %d elements of the array: ", n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }


   n = sizeof(arr)/sizeof(arr[0]);

   printf("Menu:\n");
    printf("1)Bubble Sort\n");
    printf("2)Selection Sort\n");
    printf("3)Insertion Sort\n");
    printf("4)exit\n");


    do{
         
    printf("enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            bubbleSort(arr,n);
            printf("the array sorted using bubble sort: ");
            printArray(arr,n);
            break;

        case 2:
            selectionSort(arr,n);
            printf("the array sorted using selection sort: ");
            printArray(arr,n);
            break;

        case 3:
            insertionSort(arr,n);
            printf("the array sorted using insertion sort: ");
            printArray(arr,n);
            break;

        case 4:
            printf("exiting the program.");
            break;

        default:
        printf("enter a valid choice");
        }
    
    
    } while(choice!=4);

        


   // printf("original array: ");
    //printArray(arr,n);

  //  bubbleSort(arr,n);

  //  printf("Sorted array: ");
  //  printArray(arr,n);


    return 0;
}