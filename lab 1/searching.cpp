#include<cstdio>
#include<windows.h>
#include"sortt.h"
void BinarySearch(int arr[],int n,int a);

void LinearSearch(int arr[],int n,int a)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==a)
        {
            printf("\nThe element is found at %dth index of array\n",i);
            return;
        }
    } 
      printf("\nElement not found\n");
}
void BinarySearch(int arr[],int n,int a)
{
  int low=0;
  int high=n-1;
  while(low<=high)
  {
    int mid=low+(high-low)/2;
     if(arr[mid]==a)
     {
        printf("\nThe index of the element from sorted array is %d\n",mid);
        return;
     }
     if(arr[mid]<a)
     {low=mid+1;}
     else {
        high=mid-1;
     }
  }
  printf("\n%d is not found in the array\n",a);
}
int main()
{
    int n;
   do{ 
    printf("Enter the size of the array:");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Size of the array cannot be negative ,Please enter valid number");
    }
   }while(n<=0);
     int arr[n];
     printf("\nNow start entering the elements of the array\n");
    for(int i=0;i<n;i++)
     {
      printf("\nEnter element%d of array:",i+1);
      scanf("%d",&arr[i]);
     }
        
    printf("\nThe arrray you entered is:\n");
    printArray(arr,n);

int a;

int choosesearch;
do{
    printf("\nChoose any number from the following menu: ");
    printf("\n1 for LinearSearch\n2 for BinarySearch\n3 to Exit\n");
    scanf("%d",&choosesearch);
    switch(choosesearch){
        case 1:
            printf("\nEnter element you wanted to search in the given data: ");
            scanf("%d",&a);
            LinearSearch(arr,n,a);
            break;
        case 2:
            int choose;

            printf("\nChoose any number from the following menu to sort the array: ");
            printf("\n1 for Bubble sort\n2 for Selection sort\n3 for Insertion sort\n4 to Exit\n");
            scanf("%d",&choose);
        
            switch(choose)
            {
                case 1:
                    bubbleSort(arr,n);
                    printf("The sorted array using Bubblesort  ");
                    printArray(arr,n);
                    break;
                case 2:
                    selectionSort(arr,n);
                    printf("The sorted array using Selectionsort  ");
                    printArray(arr,n);
                    break;
                case 3:
                    insertionSort(arr,n);
                    printf("The sorted array using Insertionsort  ");
                    printArray(arr,n);
                    break;
                case 4:
                    printf("EXITING...");
                    break;
            }
                printf("\nEnter element you wanted to search in the given data: ");
                scanf("%d",&a);
                BinarySearch(arr,n,a);
                break;
        case 3:
            printf("\nExiting...");
            break;
 }

}while(choosesearch!=3);
return 0;
}