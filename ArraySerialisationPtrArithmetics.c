//clang 3.8.0

#include  <stdio.h>

int main(void)
{
    char a[3][2];
    for(int y = 0; y <3; y++) 
        for(int x = 0; x <2; x++) 
            a[y][x] = x*y;
        
    char *p = a;
    for(int i = 0; i< 2*3; i++) {
        printf("elem #%d of Array = %d\n",i, *p);  // get the value of the 2d-array by pointer arithmetics
        p++; //increase ptr -> point to next elem in 2d array (now 'serialized', basically)
    }
}
