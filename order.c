//  Program to write three numbers in ascending and descending order
//  Author: [Your Name]
//  Date: [Today's Date]

#include <stdio.h>
int main() {
    int num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("In ascending order: %d %d %d\n", num1, num2, num3);
    printf("In descending order: %d %d %d\n", num3, num2, num1);
    return 0;
}

// Output:
void descendingOrder(int num1, int num2, int num3) {
    if (num1 < num2 && num2 < num3) {
        if (num2 < num3){
            printf("In descending order: %d %d %d\n", num1, num2, num3);
        }
        else{
            printf("In descending order: %d %d %d\n", num1, num3, num2);

        }
    }
    else if (num2 < num3 && num3 < num1)
    {
        if (num3 < num1)
        {
            printf("In descending order: %d %d %d\n", num2, num3, num1);
        }
        else
        {
            printf("In descending order: %d %d %d",num2,num1,num3);
        }
    }
}