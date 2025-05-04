#include<stdio.h>
#include "header.h"


int main(){
    cll l1;
    int shatime;
    printf("Enter Share time:");
    scanf("%d", &shatime);
    int num,loop=1;
    while (loop==1){
        int ch;
        printf("1.Insert process\n2.Execute\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                printf("Enter the number:");
                scanf("%d",&num);
                l1.insertprocess(num);
                break;
            case 2:
                l1.execute(shatime);
                break;
            case 3:
                l1.display();
                break;
            case 4:
                loop=0;
                break;
            default:
                printf("\nInvalid Entry\n\n");
        }
    }
}