#include <stdio.h>

int main(){
	int num, i,isPrime = 1;

	printf("Enter a number: \n");
	scanf("%d", &num);

	if (num <= 1){
		printf("Not a Prime number\n");

	}
	else{
	for (i=2; i<num;i++){
		if((num % i) == 0){
			isPrime = 0;
			break;
		}
	}
		
	}

	if(isPrime){
		printf("%d is a Prime number\n",num);
	}

}
