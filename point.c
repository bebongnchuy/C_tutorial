#include <stdio.h>

int main(){
	int var1 = 10;
	int var2[] = {20,10,11};

	printf("var1 is: %d, its address is %x\n",var1,&var1);
	printf("var2 = %x, address =  %x",var2,&var2);

	return 0;

}
