//gcc 5.4.0

#include  <stdio.h>

/* function header */
void call_by_ref(int *p);

void call_by_ref(int *p) {
    printf("In function: Address of p = %p\n", &p);
    printf("In function: Address p is pointing to = %p\n", p);
}


/* main */
int main(void) {
   
    int a = 0;
    int *p = &a;
    printf("In main: Address of p = %p\n", &p);
    printf("In main: Address p is pointing to = %p\n", p);
    call_by_ref(p);
}

// as we see, the content of a actually changed!
// also note: since the pointers are copied,
// just as exspected the addresses of the pointers are different in function(stack) and in main(heap)
