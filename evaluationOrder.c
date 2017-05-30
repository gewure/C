//clang 3.8.0

#include  <stdio.h>

int main(void)
{
    /**************** FIRST EXAMPLE ****************/
    int i = 0;
    i = ++i + i++; // what do you expect here?

    /* TWO possibilities:
    
    1)  i = 2, because:
    
        ++i is evaluated. i = 1 and the expression is 1 + i++
        i++ is evaluated. i = 1 and the expression is 1 + 1 
     
    2)  i = 1, because:
    
        i++ is evaluated. i =1 and the expression is ++i + 1;
        ++i is evaluated. i = 2 and the expressoion is 1 + 0 
    
    According to the C standard, the expression i = ++i + i++ is undefined!
    
    */
    
    printf("First Example, i on your Machine/compiler/architecture = %d \n", i);
    
    
    /*************** SECOND EXAMPLE ****************/
    int a[10];
    int y = 0;
    a[y] = y++; // what do you expect here?
    
    /* TWO possibilities:
    
    1) We write 0 at memory address a[0]:

        i is evaluated. i = 0 and the expression is a[0] = i++
        i++ is evaluated. i = 1 and the expression is a[0] = 0
    
    2) We write 0 at memory address a[1].
    
        i++ is evaluated. i = 1 and the expression is a[i] = 0
        i is evaluated. i = 1 and the expression is a[1] = 0
    
    According to the C standard, the expression a[i] = i++ is undefined!
    
    */
    printf("Second Example, a[y] on your Machine/compiler/architecture = %d \n", a[y]);
    
    
    /**************** THEORY ********************/
    /* Q: how to avoid this undefined behaviour?
    
       A: So called 'sequence points' guaranteed that all side effects of previous commands are already dispatched:
           -- &&, ||, condition ins while, if, switch..
           -- all three parts of a for-loop
           -- the ? in ternary operator (e.g.: a = =2 ? 0 : a;)
           -- return
           -- commas in printf
    */
    
    /* in practice it is not that common that things like this happen, 
       unless you want to write really clever code all the time.
       => keep it simple and stupid. KISS! */   
}
