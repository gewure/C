//gcc 5.4.0

#include  <stdio.h>
#include <stdlib.h>
    
typedef struct List {
    int a,b,c;
} List;

/* headers */
void free_list(List**l);
void free_secure( void **p);

/* pointer to pointer freeing */
void free_list(List**l) {
        (**l).a = 0;  // (**l) because * binds lower than . binds
        (**l).b = 0;
        (*l)->c = 0;  // (*l)->c    IS THE SAME AS    (**l).c
        *l = NULL;    //.. and set the actual pointer to null
}

/* secure free: nulls the pointer after freeing */
void free_secure(void **p) {
    free(*p);
    *p = NULL;
}

int main(void)
{
    List l;
    List *lp = &l; 
    free_list(&lp); 
    printf("pointer after free (should be NULL) and is: %p\n",lp);
    
    return 0;
}
