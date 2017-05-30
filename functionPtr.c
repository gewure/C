//clang 3.8.0

#include  <stdio.h>

/* function headers */
double square(double p);
double timestwo(double p);
void map(int *array, int len, double (*function)(double));

/* main */
int main(void){
    int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    map(arr1, 10, square);  // call function-ptr square on all vals in arr1
    map(arr2, 10, timestwo); //call function-ptr timestwo an all vals in arr2
    
    for (int i = 0; i < 10; i++)
        printf("%d ", arr1[i]);
    
    printf("\n");
    
    for (int i = 0; i < 10; i++)
        printf("%d ", arr2[i]);
}

/* map function - using a function-pointer */
void map(int *array, int len, double (*function)(double)) {
    for(int i = 0; i< len; i++) {
        array[i] = function(array[i]);
    }
}

double square(double p) {
    return p*p;
}

double timestwo(double p) {
    return p*2;
}
