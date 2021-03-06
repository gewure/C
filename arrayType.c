//gcc 5.4.0
#include  <stdio.h>
#include <stdlib.h>

/* struct definition */
typedef struct Array {
    int size;
    int *arr;
} Array;

/* init function for Array type */
void init_Array(int size, Array *arr) {
    
    int *ar = malloc(sizeof(int) * size);
    
    arr->size = size;
    arr->arr = ar;
    
}

/* destroy function for Array type */
void destroy_Array(Array *arr) {
    free(arr->arr); // only the malloc'd part of Array must be freed
    arr = NULL;  //defensive programming style
}

/* access function for Array type */
int* access_Array(Array* arr, int index) {
    if(index >= arr->size || index < 0) {  //check if index is in bounds (unsigned and < size)
        printf("%p[%d] out of bounds \n", arr, index);
        return 0;
    } else { // everything ok
        // return pointer to element of array ( this way we can manipulate the array)
        // if it was just a int, not a int* we would have only a copy of the element -
        // thus we would not be able to set/manipulate this element
        return &(arr->arr[index]);
    }
      
}

/* main */
int main(void)
{
    
    Array ar; // declare Array-type
    init_Array(8, &ar); // fill arraytype (mallocs!)
    
     //fill array
    for(int i = 0; i< ar.size; i++) {
        *(access_Array(&ar, i)) = i;  
    }
    //print contents
    for(int i = 0; i< ar.size; i++) {
        printf("ar.arr[i] = %d \n", *(access_Array(&ar, i)));
    }
    
    
    printf("access_Array(%ptr, %d) = %d \n",&ar,2, *(access_Array(&ar, 2)));
    
    destroy_Array(&ar); //frees the malloc'd part of the Array-type

}
