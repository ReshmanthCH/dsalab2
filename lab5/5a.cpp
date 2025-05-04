#include <stdio.h>
#include <stdlib.h>

class doublylinkedlist {
    private:
        struct node {
            int data;
            node* prev;
            node* next;
        };
        node* head;
        node* tail;
    public:
        doublylinkedlist() {
            head = NULL;
            tail = NULL;
        }
    
    void insert_beginning(int);
    void insert_end(int);
    void insert_position(int, int);
    int delete_beginning();
    int delete_end();
    int delete_position(int);
    void search(int);
    void display();
};

int main() {
    doublylinkedlist dll;
    int choice, number, position;

    do {
        printf("Menu for doubly linked list:\n");
        printf("1) Insert at beginning\n");
        printf("2) Insert at end\n");
        printf("3) Insert at a position\n");
        printf("4) Delete from beginning\n");
        printf("5) Delete from end\n");
        printf("6) Delete from a position\n");
        printf("7) Search\n");
        printf("8) Display\n");
        printf("9) Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &number);
                dll.insert_beginning(number);
                break;
            case 2:
                printf("Enter the number: ");
                scanf("%d", &number);
                dll.insert_end(number);
                break;
            case 3:
                printf("Enter the number: ");
                scanf("%d", &number);
                printf("Enter the position at which it should be inserted: ");
                scanf("%d", &position);
                dll.insert_position(number, position);
                break;
            case 4:
                dll.delete_beginning();
                break;
            case 5:
                dll.delete_end();
                break;
            case 6:
                printf("Enter the position from which it should be deleted: ");
                scanf("%d", &position);
                dll.delete_position(position);
                break;
            case 7:
                printf("Enter the number to be searched: ");
                scanf("%d", &number);
                dll.search(number);
                break;
            case 8:
                dll.display();
                break;
            case 9:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (choice != 9);

    return 0;
}

void doublylinkedlist::insert_beginning(int number) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = number;  // Set the data

    if (head == NULL) {
        head = tail = newnode;
        newnode->prev = newnode->next = NULL;
    } else {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
    }
}

void doublylinkedlist::insert_end(int number) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = number;  // Set the data
    newnode->next = NULL;

    if (tail == NULL) {
        head = tail = newnode;
        newnode->prev = NULL;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void doublylinkedlist::insert_position(int number, int position) {
    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insert_beginning(number);
        return;
    }

    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = number;  // Set the data
    node* temp = head;
    int count = 1;

    while (temp && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newnode);  // Free the new node if it's not inserted
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next) {
        temp->next->prev = newnode;
    } else {
        tail = newnode;
    }

    temp->next = newnode;
}

int doublylinkedlist::delete_beginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return -1;  // Indicate that the list is empty
    }

    node* temp = head;
    head = head->next;

    if (head) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }

    free(temp);  // Use free() since malloc() was used for allocation
    return 0;  // Indicate successful deletion
}

int doublylinkedlist::delete_end() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return -1;  // Indicate that the list is empty
    }

    node* temp = tail;
    tail = tail->prev;

    if (tail) {
        tail->next = NULL;
    } else {
        head = NULL;
    }

    free(temp);  // Use free() since malloc() was used for allocation
    return 0;  // Indicate successful deletion
}

int doublylinkedlist::delete_position(int position) {
    if (position <= 0 || !head) {
        printf("Invalid position or empty list!\n");
        return -1;  // Indicate that the position is invalid or list is empty
    }

    if (position == 1) {
        delete_beginning();
        return 0;
    }

    node* temp = head;
    int count = 1;

    while (temp && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return -1;  // Indicate that the position is out of range
    }

    if (temp->prev) {
        temp->prev->next = temp->next;
    }
    if (temp->next) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }

    free(temp);  // Use free() since malloc() was used for allocation
    return 0;  // Indicate successful deletion
}

void doublylinkedlist::search(int number) {
    node* temp = head;
    int position = 1;

    while (temp) {
        if (temp->data == number) {
            printf("Element %d found at position %d\n", number, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Element %d not found in the list.\n", number);
}

void doublylinkedlist::display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List elements: ");
    node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("None\n");
}