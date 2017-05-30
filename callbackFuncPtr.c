//gcc 5.4.0

#include  <stdio.h>

/* headers */
char toUnderLine(char c); 
char countUp(char c);
void map(char *s, char (*f)(char));

char countUp(char c) {
    return c+1;
}

char toUnderLine(char c) {
    if( c == ' ')
        return '_';
    else 
        return c;

}
/* callback-functionality using function-pointers */
void map(char *s, char (*f)(char)) {
    while(*s != '\0') {
        *s = f(*s); //call function pointer for this character of string 
        s++; //ptr arithmetics .. jump to next pos in string
    }
}

int main(void)
{
    char arr[] = "Hello Gewure";
    printf("%s \n", arr);
    map(arr, toUnderLine); //callback by function-ptr
    printf("%s \n", arr);
    map(arr, countUp); //callback by function-ptr
    printf("%s \n", arr);
    
}
