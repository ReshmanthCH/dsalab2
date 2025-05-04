//Program to use Stack ADT using Singly Linked List to convert from infix to postfix notation and do postfix evaluation
#include"6h.h"
#include<cstdio>
#include<cstdlib>
//FUNCTION TO CHECK IF THE CHARACTER IS AN OPERATOR 
bool isoperator(char ch){
    return(ch == '+' || ch == '-' || ch == '%' ||ch == '/' || ch == '*' || ch == '=');
}
struct variable{
    char name;
    int value;
}variables[26];
void setvariable(char var,int val){
    variables[var-'a'].name = var;
    variables[var - 'a'].value=val;
}
int getvariable(char var){
    return variables[var-'a'].value;
}
int precedence(char ch){
    if(ch == '='){
        return 1;
    }
    if(ch == '+' || ch == '-'){
        return 2;
    }
    if(ch == '%' || ch == '/' || ch == '*'){
        return 3;
    }
    return 0;
}
//FUNCTION TO CONVERT INFIX EXPRESSION TO POSTFIX EXPRESSION
void infixtopostfix(char* infix,char* postfix){
    stack st;
    int j = 0;
    for(int i = 0;infix[i]!='\0';i++){
        if(infix[i]>='0'&&infix[i]<='9'||infix[i]>='a'&&infix[i]<='z'){
            while(infix[i]>='0'&&infix[i]<='9'||infix[i]>='a'&&infix[i]<='z'){
            postfix[j++]=infix[i++];
            }
            postfix[j++]=' ';
            i--;
        }else if(infix[i] == '('){
            st.push(infix[i]);
        }else if(infix[i]==')'){
            while(!st.isempty() && st.peek()!='('){
                postfix[j++]=st.pop();
                
            }
            st.pop();
        }else if(isoperator(infix[i])){
            if(!st.isempty() && precedence(st.peek())>=precedence(infix[i])){
                postfix[j++] = st.pop();
                
            }
            st.push(infix[i]); 
        }
    }
    while(!st.isempty()){
        postfix[j++]=st.pop();
        
    }
    postfix[j]='\0';
}
//EVALUATE POSTFIX EXPRESSION
int postfixevaluation(char* postfix){
    char varname;
    stack st;
    for(int i= 0;postfix[i]!='\0';i++){
        if(postfix[i]>='0'&&postfix[i]<='9'){
            int num = 0;
            while(postfix[i]!=' '){
                num = num*10+(postfix[i]-'0');
                i++;
            }
            st.push(num);
        }else if(postfix[i]>='a'&&postfix[i]<='z'){
            varname = postfix[i];
            st.push(getvariable(varname));
        }else if(postfix[i]!=' '){
                if(postfix[i]=='='){
                    int val = st.pop();
                    setvariable(varname,val);
                    st.push(val);
                }else{
                  int val2 = st.pop();
                  int val1 = st.pop();
                  switch(postfix[i]){
                        case '+' :
                        st.push(val1 + val2);
                        break;
                        case '-' :
                        st.push(val1 - val2);
                        break;
                        case '*' :
                        st.push(val1 * val2);
                        break;
                        case '%' :
                        st.push(val1 % val2);
                        break;
                        case '/' :
                        st.push(val1 / val2);
                        break;
                    }
                }
        }
    }
    return st.pop();
}
//DRIVER CODE 
int main(){
    char infix[100],postfix[100];
    int choice;
    do{
       printf("MENU\n");
       printf("1.GET INFIX\n""2.GET POSTFIX\n""3.POSTFIX EVALUATION\n""4.EXIT\n");
       printf("ENTER YOUR CHOICE : ");
       scanf("%d",&choice);
       switch(choice){
        case 1 :
        printf("ENTER THE INFIX NOTATION : ");
        scanf("%s",infix);
        break;
        case 2 :
        infixtopostfix(infix,postfix);
        printf("POSTFIX CONVERSION = %s\n",postfix);
        break;
        case 3 :
        printf("THE POSTFIX EVALUATION = %d\n",postfixevaluation(postfix));
        break;
        case 4 :
        printf("SUCCESSFULLY EXITED :) \n");
        break;
        default :
        printf("INVALID CHOICE TRY AGAIN \n");
       }
    }while(choice!=4);
    return 0;
}