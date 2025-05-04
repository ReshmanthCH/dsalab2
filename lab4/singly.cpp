
#include <stdio.h>
#include <stdlib.h>

class SinglyLinkedList {
private:
struct Node {
    int data;
    Node* next;
};
    Node* head;

public:
    SinglyLinkedList(){
        head = NULL;
    }

    void insert_beginning(int);
    void insert_end(int);
    void insert_position(int, int);
    void delete_beginning();
    void delete_end();
    void delete_position(int);
    void search(int);
    void display();
    void display_reverse();
    void reverse();
};


int main() {
    SinglyLinkedList sll;
    int choice, data, position;

    while (true) {
        printf("\nSingly Linked List Menu\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Display in Reverse\n");
        printf("10. Reverse the List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                sll.insert_beginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                sll.insert_end(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                sll.insert_position(data, position);
                break;
            case 4:
                sll.delete_beginning();
                break;
            case 5:
                sll.delete_end();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                sll.delete_position(position);
                break;
            case 7:
                printf("Enter data to search: ");
                scanf("%d", &data);
                sll.search(data);
                break;
            case 8:
                sll.display();
                break;
            case 9:
                sll.display_reverse();
                break;
            case 10:
                sll.reverse();
                break;
            case 11:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Insert at the beginning
void SinglyLinkedList::insert_beginning(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// Insert at the end
void SinglyLinkedList::insert_end(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = nullptr;

    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Insert at a position
void SinglyLinkedList::insert_position(int data, int position) {
    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    if (position == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        printf("Position out of bounds!\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Delete from the beginning
void SinglyLinkedList::delete_beginning() {
    if (head == nullptr) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from the end
void SinglyLinkedList::delete_end() {
    if (head == nullptr) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == nullptr) {
        free(head);
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->next != nullptr) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
}

// Delete from a position
void SinglyLinkedList::delete_position(int position) {
    if (head == nullptr) {
        printf("List is empty!\n");
        return;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        printf("Position out of bounds!\n");
        return;
    }

    Node* delete_node = temp->next;
    temp->next = temp->next->next;
    free(delete_node);
}

// Search for an element
void SinglyLinkedList::search(int data) {
    Node* temp = head;
    int position = 1;
    while (temp != nullptr) {
        if (temp->data == data) {
            printf("Element %d found at position %d.\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found.\n", data);
}

// Display list
void SinglyLinkedList::display() {
    if (head == nullptr) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("None\n");
}

// Display the list in reverse order without changing the structure
void SinglyLinkedList::display_reverse() {
    int count=0;
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp=head;
    while(temp!=nullptr)
    {
       count++;
       temp=temp->next; 
    }
    for(int i=count;i>0;i--)
    {
        temp=head;
        for(int j=i-1;j>0;j--)
        {
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
 printf("\n");
}

// Reverse the list
void SinglyLinkedList::reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next_node = nullptr;
    while (current != nullptr) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    head = prev;
}