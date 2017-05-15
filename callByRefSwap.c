//gcc 5.4.0

#include  <stdio.h>

/* function header */
void swap(int *a, int* b);

/* swap implemented using call-by-reference */
void swap(int *a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

/* main */
int main(void) {
   
    int a = 1111;
    int b = 9999;
    
    printf("%d \n", a);
    printf("%d \n", b);
    
    printf("swapping..\n");
    swap(&a, &b);
    
    printf("%d \n", a);
    printf("%d \n", b);
   
}
