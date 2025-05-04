#ifndef STACK_H 
#define STACK_H 

#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std ;

class Stack 
{
    private:
        struct Node
        {
            double data ;
            struct Node *next ; 
        }; 
        struct Node *top ;
    public:
        Stack() 
    { 
       top = NULL ;
    }
    void Push(double ele) ;
    double Pop() ;
    double Peek() ;
    bool isEmpty() ;

};

void Stack::Push(double ele) 
{  
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node)) ;
    newnode->data = ele ;
    newnode->next = top ;
    top = newnode ;
    // cout << "pushed "<< ele << " into stack " ;
}

double Stack::Pop() 
{
    if (isEmpty()) return '\0';
    double temp = top->data;
    Node* toDelete = top;
    top = top->next;
    delete toDelete;
    return temp;
}

double Stack::Peek() 
{
    return (isEmpty()) ? '\0' : top->data;
}

bool Stack::isEmpty()
{
    return (top == nullptr) ;
}
#endif