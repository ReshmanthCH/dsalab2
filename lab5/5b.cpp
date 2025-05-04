// Program to create List ADT using Circular linked list

#include<cstdio>
#include<cstdlib>
class list{
    struct node {
        int data;
        node * next;
    };
    node *head;
    public: 

    list(){
    head = NULL; 
}
// Function prototypes
    void insertBegin(int);
    void insertend(int);
    void insertpos(int,int);
    int deleteBegin();
    int deleteEnd();
    int deletepos(int);
    void display();
    int search(int);


};
int main(){
    list obj; 
    int choice,value,target,result,pos;
    do{
        printf("\nMENU CARD\n");
        printf("Enter 1: To insert the element at the Beginning\n");
        printf("Enter 2: To insert the element at the Ending\n");
        printf("Enter 3: To insert the element at the Specific Position\n");
        printf("Enter 4: To Delete the element at the Beginning\n");
        printf("Enter 5: To Delete the element at the Ending\n");
        printf("Enter 6: To Delete the element at the Specific Position\n");
        printf("Enter 7: To Search the element in the List\n");
        printf("Enter 8: To Display the elements of the List\n");
        printf("Enter 9: To End the Program\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to insert in the list : ");
            scanf("%d",&value);
            obj.insertBegin(value);
            break;
            case 2:
            printf("Enter the value to insert in the list : ");
            scanf("%d",&value);
            obj.insertend(value);
            break;
            case 3:
            printf("Enter the value to insert in the list : ");
            scanf("%d",&value);
            printf("Enter the position of the element: ");
            scanf("%d",&pos);
            obj.insertpos(pos,value);
            break;
            case 4:
            result = obj.deleteBegin();
            if(result!=0){
                printf("The element Deleted is : %d\n",result);
            }
            break;
            case 5:
            result = obj.deleteEnd();
            if(result!=0){
                printf("The element Deleted is : %d\n",result);
            }
            break;
            case 6:
            printf("Enter the position of the element: ");
            scanf("%d",&pos);
            result = obj.deletepos(pos);
            if(result!=0){
                printf("The element Deleted is : %d\n",result);
            }
            break;
            case 7:
            printf("Enter the target to Search in the list: ");
            scanf("%d",&target);
            result = obj.search(target);
            if(result!=-1 && result!=0){
                printf("The Target found in the List\n");
                printf("The position of the target in the list is : %d\n",result);
            }
            else if(result==-1){
                printf("The Target is not found in the List\n");
            }

            break;
            case 8:
            obj.display();
            break;
            case 9:
            printf("Progarm Ended\n");
            break;
            default:
            printf("Invalid choice\n");
            printf("Enter the choice between 1 to 9\n");
            break;
        }

    }
    while(choice!=9);
}
// Function to Insert the element at the Beginning of the list
void list :: insertBegin(int value){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    if(head==NULL){
        newnode->next = newnode;
        head = newnode;
        return ;}
    newnode ->next = head;
    node *temp = head;
    while(temp->next!= head){
        temp = temp->next;
    }
    temp->next = newnode;
    head = newnode;
}

// Function to display the elements in the list

void list :: display(){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    printf("The elements in the list are:");
    node *temp = head;
    while(temp->next != head){
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
    return;
}
// Function to Insert the element at the End of the list
void list :: insertend(int value){
    if(head == NULL){
        insertBegin(value);
        return;
    }
    node *newnode = (node*)malloc (sizeof(node));
    newnode->data = value;
    newnode->next = head;
    node *temp = head;
    // There is only one node in the list
    if(head==temp->next){ 
    head->next = newnode;
    return;
    }
    while(temp->next!=head){
        temp= temp->next;
    }
    temp->next = newnode;
}
// Function to insert the at a specific position of the node
void list :: insertpos(int pos,int value){
    if(head == NULL){
        insertBegin(value);
        return;
    }
    if(pos<1){
        printf("Invalid position \n");
        printf("Enter valid position \n");
        return ;
    }
    if(pos==1){
        insertBegin(value);
        return ;
    }
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    int i =1;
    node *temp = head;
    while(i<pos-1 && temp->next!= head){
        temp = temp->next;
        i++;
    }
    // if the position is not within the list
    if(temp->next==head && i+1<pos){ 
        printf("Position is out of the list\n");
        printf("Enter valid position\n");
        return ;
    }
    if(temp->next == head && i+1 == pos){
        insertend(value);
        free(newnode);
        return ;
    }
    newnode->next = temp->next;
    temp->next = newnode;

}

// Function to delete the node at the Beginning of the list
int list :: deleteBegin(){
    if (head==NULL){
        printf("The list is empty");
        return 0;
    }
    if(head==head->next){
        node *del = head;
        int result = head->data;
        head = NULL;
        printf("All the elements in the list are deleted\n");
        printf("The list is empty\n");
        free(del);
        return result;
    }
    node *del = head;
    int result = del->data;
    head = del->next;
    node *temp = head;
    while(temp->next!=del){
        temp = temp->next;
    }
    temp->next = head;
    free(del);
    return result;
}

// Function to Search the element in the List
int list :: search(int target){
    if(head==NULL){
        printf("The list is empty");
        return 0;
    }
    node *temp = head;
    int count =1;
    while(temp->next!=head){ 
        if(temp->data==target){
            return count;
        }
        count++;
        temp = temp->next;}
    return -1;
}

// Function to Delete the Element at the End of the list
int list :: deleteEnd(){
    if(head==NULL){
        printf("The list is empty");
        return 0;
    }
    // if there is only one node in the List
    if(head == head->next){
        int result = head->data;
        deleteBegin();
        return result;

    }
    node *temp = head;
    while(temp->next->next!=head){
        temp =temp->next;
    }
    node *del = temp->next;
    int result = del->data; 
    temp->next = head;
    free(del);
    return result;

}

// Function to delete the node at a Specific Position
int list :: deletepos(int pos){
     if(head == NULL){
        printf("The list is empty\n");
        return 0;
    }
    if(pos<1){
        printf("Invalid position \n");
        printf("Enter valid position \n");
        return 0;
    }
    if(pos==1){
        int result = head->data;
        deleteBegin();
        return result;
    }
    int i =1;
        node *temp = head;
    while(i<pos-1 && temp->next!=head){
        temp = temp->next;
        i++;
    }

     if(temp->next==head){ 
        printf("Position is out of the list\n");
        printf("Enter valid position\n");
        return 0;
    }
    node *del = temp->next;
    int result = del->data;
    temp->next = del->next;
    free(del);
    return result;
    
}