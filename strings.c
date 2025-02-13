#include <stdio.h>

int main(){

    char c;

    printf("Give a character: \n");
    c = getchar();
    printf("Here is your char: \t");
    putchar(c);

    return 0;
}