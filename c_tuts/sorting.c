#include <stdio.h>

void sort(int array_size,int arr[]);

int main(){
    int marks[] = {40, 90,55,43,35,80};
    size_t array_size = (sizeof(marks)/sizeof(marks[0]));
    puts("Marks before sorting");
    for(int i = 0; i < array_size;i++){
        printf("%4d\t",marks[i]);

    }

printf("\n\n");

sort(array_size,marks);

puts("Marks After sorting");
    for(int i = 0; i < (sizeof(marks)/sizeof(marks[0]));i++){
        printf("%4d\t",marks[i]);

    }
    
}

void sort(int array_size, int arr[]){
    for(int i = 1; i<= array_size - 1; i++){
        for (int j = 1; j <= array_size-1; j++){
            if (arr[j-1] >= arr[j])
            {
                /* code */
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
            
        }
    }
}