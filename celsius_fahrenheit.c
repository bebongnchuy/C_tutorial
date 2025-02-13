#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void fahr_cel(int);

int main(){
fahr_cel(500);
    return 0;
}

void fahr_cel(int max){
    float fahr = 0;
    float cel;
    while (fahr < max)
    {
        /* code */
        cel = 5 * (fahr-32) / 9;
        printf("%-6.2f\t%-6.2f\n",fahr,  cel);
        fahr+=20;
    }

    
}