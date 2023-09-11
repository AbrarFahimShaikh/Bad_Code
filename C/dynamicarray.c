//dynamic array using pointers practice
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *arr;
    int size;
    int capacity;
}DynamicArray;

void initDynamicArray(DynamicArray *dynArr, int capacity)
{
    dynArr->arr = (int *)malloc(capacity * sizeof(int));
    dynArr->size = 0;
    dynArr->capacity = capacity;
}
void append(DynamicArray *dynArr, int element){
    if(dynArr->size == dynArr->capacity){
        dynArr->capacity*=2;
        dynArr->arr = (int *)realloc(dynArr->arr,dynArr->capacity * sizeof(int));
    }
    dynArr->arr[dynArr->size++] = element;
}

void removeElement(DynamicArray *dynArr, int index)
{
    if(index < 0 || index >= dynArr->size){
        printf("Invalid index\n");
        return;
    }
    
    for (int i = index; i<dynArr->size -1; i++){
        dynArr->arr[i] = dynArr->arr[i+1];
    }
    dynArr->size--;
    
    if(dynArr->size <= dynArr->capacity/2)
    {
        dynArr ->capacity /= 2;
        dynArr->arr =(int*)realloc(dynArr->arr,dynArr->capacity*sizeof(int));
    }
}

int getElement(DynamicArray *dynArr, int index){
    if (index <0 || index >= dynArr->size){
        printf("Invalid Number!");
        return -1;
    }
    return dynArr ->arr[index];
}

void freeDynamicArray(DynamicArray *dynArr){
    free(dynArr->arr);
    dynArr->size = 0;
    dynArr->capacity = 0;
    
}

int main (){
    DynamicArray myArray;
    initDynamicArray(&myArray,5);
    
    append(&myArray,10);
    append(&myArray,20);
    append(&myArray,30);
    
    printf("Element at index 1: %d \n",getElement(&myArray,1));
    removeElement(&myArray,1);
    printf("Element at index 1 after removal: %d \n",getElement(&myArray,1));
    freeDynamicArray(&myArray);
    return 0;
}
    
