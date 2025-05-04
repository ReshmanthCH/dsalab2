#include <stdio.h>
#include <iostream>
using namespace std;

class area {
public:
    float squareArea(float length) {
        return length * length;
    }
    float cubeArea(float length) {
        return 6 * length * length;
    }
    float rectangleArea(float length, float breadth) {
        return length * breadth;
    }
    float cuboidArea(float length, float breadth, float height) {
        return 2 * (length * breadth + breadth * height + length * height);
    }
};

int main() {
    int choice;
    area Area;

    do {
        printf("\nchoose from the five shapes: \n");
        printf("Menu:\n");
        printf("1.square\n");
        printf("2.cube\n");
        printf("3.rectangle\n");
        printf("4.cuboid\n");
        printf("5.exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        float l, b, h; 
        switch (choice) {
            case 1:
                printf("Enter the value of the side length: ");
                scanf("%f", &l);
                printf("Area of the square is: %.2f\n", Area.squareArea(l));
                break;
            case 2:
                printf("Enter the value of the side length: ");
                scanf("%f", &l);
                printf("Surface Area of the cube is: %.2f\n", Area.cubeArea(l));
                break;
            case 3:
                printf("Enter the value of length: ");
                scanf("%f", &l);
                printf("Enter the value of breadth: ");
                scanf("%f", &b);
                printf("Area of the rectangle is: %.2f\n", Area.rectangleArea(l, b));
                break;
            case 4:
                printf("Enter the value of length: ");
                scanf("%f", &l);
                printf("Enter the value of breadth: ");
                scanf("%f", &b);
                printf("Enter the value of height: ");
                scanf("%f", &h);
                printf("Area of the cuboid is: %.2f\n", Area.cuboidArea(l, b, h));
                break;
            case 5:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}