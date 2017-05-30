//clang 3.8.0

#include  <stdio.h>

/* function header */
double multRec(double a, double b);

/* main */
int main(void){
    for(int i = 0; i<=10; i++) {
        for(int y = 0; y <=10; y++) {
            printf("%d*%d = %g \n",i,y,multRec(i, y));
            printf("\n");
            printf("%d*%d = %g \n",i,y,multRec(y,i));
        }
    }
}


/* Recursive multiplication of two numbers (basically functional programming)*/
double multRec(double a, double b) {
    
    if(a == 1) 
        return b;
    if(b==1)
        return a;
    if(b == 0 || a == 0)
        return 0;
    
    return a + multRec(a, b-1);  //recursion happens here
}
