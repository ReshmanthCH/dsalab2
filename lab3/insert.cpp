#include<stdio.h>

#define SIZE 5

class listADT {
    int arr[SIZE];
    int length;

    public:
        listADT(): length(0) {}

    void insertbeg(int value){
        if(length == SIZE){
            printf("List is full!\n");
            return;
        }
        for(int i = length; i>0 ; i--)
            arr[i] = arr[i-1];
            arr[0] = value;
            length++;
        }

    void insertend(int value){
        if(length == SIZE){
            printf("LIst is full!\n");
            return;
        }
        arr[length++] = value;
    }

   void insertposition(int position, int value){
    if(length == SIZE){
        printf("List is full!\n");
        return;
    }
    if(position<0 || position>length){
        printf("Invalid postion.\n");
        return;
    }
    for(int i = length; i>position;i--)
    arr[i] = arr[i-1];
    arr[position] = value;
    length++;
   }

   void deletebeg(){
    if(length == 0){
        printf("List is empty!\n");
        return;
    }
    for(int i = 0; i<length-1;i++)
    arr[i]=arr[i+1];
    length--;
   }

   void deleteend(){
    if(length==0){
        printf("List is empty!\n");
        return;
    }
    length--;
   }

   void deleteposition(int position){
    if(length==0){
        printf("List is empty!\n");
        return;
    }
    for (int i = position; i<length-1;i++)
        arr[i]=arr[i+1];
        length--;
   }

   void search(int value){
    for(int i=0;i<length;i++){
        if(arr[i]==value){
            printf("element found at postion %d\n", i);
            return;
        }
    }
    printf("Element not found.\n");
   }

   void display(){
    if(length==0){
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    for(int i=0;i<length;i++)
        printf("%d", arr[i]);
        printf("\n");
   }

   void rotate(int k){
    if(length=0){
        printf("list is empty!\n");
        return;
    }
    k = k % length;
    int temp[SIZE];
    for(int i=0;i<length;i++)
        temp[(i+k)%length]=arr[i];
    for (int i=0; i<length;i++)
        arr[i] = temp[i];
   }
};

int main() {
    listADT list;
    int choice, value, position, k;
    while (true) {
        printf("\nMenu:\n");
        printf("1) Insert Beginning\n2) Insert End\n3) Insert Position\n");
        printf("4) Delete Beginning\n5) Delete End\n6) Delete Position\n");
        printf("7) Search\n8) Display\n9) Rotate\n10) Exit\n");
        printf("Enter your choice:" );
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                list.insertbeg(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                list.insertend(value);
                break;
            case 3:
                printf("Enter position and value: ");
                 scanf("%d %d", &position, &value);
                list.insertposition(position, value);
                break;
            case 4:
                list.deletebeg();
                break;
            case 5:
                list.deleteend();
                break;
            case 6:
                printf("Enter position (0-based index) to delete: ");
                scanf("%d", &position);
                list.deleteposition(position);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                list.search(value);
                break;
            case 8:
                list.display();
                break;
            case 9:
                printf("Enter k: ");
                scanf("%d", &k);
                list.rotate(k);
                break;
            case 10:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}