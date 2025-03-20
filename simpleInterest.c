// Program to calculate the simple interest 

// simple interest = (P*R*T)/100

#include <stdio.h>

int main(){

    float principal, rate, time, simple_interest;
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the rate of interest: ");
    scanf("%f", &rate);
    printf("Enter the time in years: ");
    scanf("%f", &time);
    simple_interest = (principal * rate * time) / 100;
    printf("\nSimple interest is: %.2f", simple_interest);
    getchar();
    return 0;
}