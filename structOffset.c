//gcc 5.4.0
#include  <stdio.h>
#include <stddef.h> // Needed for offsetof(..)

struct Date {
int day;
int month;
int year;
};


int main(void)
{

    printf("Offset of day : %ld\n", offsetof(struct Date, day));
    printf("Offset of month : %ld\n", offsetof(struct Date, month));
    printf("Offset of year : %ld\n", offsetof(struct Date, year));
    
    struct Date d = {28, 6, 1981};
    char *p = (char *) &d; // Char pointer so we do pointer arithmetic with bytes
    
    printf("Int at offset 0: %d\n", *((int *)(p + 0)));
    printf("Int at offset 4: %d\n", *((int *)(p + 4)));
    printf("Int at offset 8: %d\n", *((int *)(p + 8)));

}
