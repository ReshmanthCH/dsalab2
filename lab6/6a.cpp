#include<stdio.h>

#define SIZE 5

class stack{
    private:
        char arr[SIZE];
        int top;

    public:
        stack(){
            top = -1;
        }

    void push(char);
    void pop();
    void peek();
};

int main(){
    stack s;
    int choice;
    char ch;
    
    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Peep\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a character to push: ");
                scanf(" %c", &ch);
                s.push(ch);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

void stack::push(char ch) {
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push %c\n", ch);
    } else {
        arr[++top] = ch;
        printf("%c pushed into stack\n", ch);
    }
}

void stack::pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {
        printf("%c popped from stack\n", arr[top--]);
    }
}

void stack::peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is %c\n", arr[top]);
    }
}