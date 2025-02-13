#include <stdio.h> 
int main() {
char name[50];
int age;
     // Input
        printf("Enter your name: ");
	scanf("%s", name);
	printf ("Enter your age: "); 
	scanf("%d", &age);
	
	// Output
	printf("Hello, %s. You are %d years old.\n", name, age);
	
	return 0;
}

