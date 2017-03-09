#include <stdio.h>
void getBin(int num, char* str);

int main(int argc, char* args[]) {

int a = 0;
int b = 10;

for(int c = 0; c <= b; c++) {
	char str[6];
	a = c;
	printf("a is now: %i \n\n", a);
	getBin(a, str);
	printf("%i as INT \t %x as HEX \t %s as BIN \n", a,a,str);

	a<<=1;
        printf("shifted a left\n");
	getBin(a, str);
        printf("%i as INT \t %x as HEX \t %s as BIN \n", a,a,str);

	a<<=1;
        printf("shifted a left\n");

	getBin(a, str);
        printf("%i as INT \t %x as HEX \t %s as BIN \n", a,a,str);

	a<<=1;
        printf("shifted a left\n");

	getBin(a, str);
        printf("%i as INT \t %x as HEX \t %s as BIN \n", a,a,str);
	
printf("\n");
}
return 0;
}

void getBin(int num, char *str)
{
  *(str+5) = '\0';
  int mask = 0x10 << 1;
  while(mask >>= 1)
    *str++ = !!(mask & num) + '0';
}
