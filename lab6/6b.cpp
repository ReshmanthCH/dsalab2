#include<stdio.h>
#include<stdlib.h>

class Stack {
private:
struct Node {
    char data;
    Node* next;
};
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char);
    void pop();
    void peep();

};

int main() {
    Stack stack;
    int choice;
    char value;

    do {
        printf("\nMenu:\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Peep\n");
        printf("4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to push: ");
                scanf(" %c", &value);  // Adding space before %c to consume any leftover newline
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.peep();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

void Stack::push(char value) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

void Stack::pop() {
    if (top == nullptr) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::peep() {
    if (top == nullptr) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %c\n", top->data);
    }
}
