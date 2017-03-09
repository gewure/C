#include <stdio.h>

void getBin(int num, char* str);

int main(int argc, char* args[]) {

  char str[10];
  long number = 0;

  getBin(number, str);
  printf("num is now: %s \n\n", str);

  //Setting a bit
  //Use the bitwise OR operator (|) to set a bit.

  number |= 1 << 4;
  //That will set bit x.

  printf("4.th bit setted using |=");
  getBin(number, str);
  printf("num is now: %s \n\n", str);

  //Clearing a bit
  //Use the bitwise AND operator (&) to clear a bit.

  number &= ~(1 << 4);
  //That will clear bit x. You must invert the bit string with the bitwise NOT operator (~), then AND it.

  printf("4.th bit cleared using &=");
  getBin(number, str);
  printf("num is now: %s \n\n", str);

  //Toggling a bit
  //The XOR operator (^) can be used to toggle a bit.

  number ^= 1 << 6;
  //That will toggle bit x.

  printf("6.th bit toggled using ^=");
  getBin(number, str);
  printf("num is now: %s \n\n", str);

  //Checking a bit
  //You didn't ask for this but I might as well add it.
  //To check a bit, shift the number x to the right, then bitwise AND it:

  //bit = (number >> x) & 1;
  //That will put the value of bit x into the variable bit.
  //printf("4.th bit checked ");
  //getBin(number, str);
  //printf("num is now: %s \n\n", str);

  //Changing the nth bit to x
  //Setting the nth bit to either 1 or 0 can be achieved with the following:

  //number ^= (-x ^ number) & (1 << n);

  //Bit n will be set if x is 1, and cleared if x is 0.
  //printf("4.th bit setted using |=");
  //getBin(number, str);
  //printf("num is now: %s \n\n", str);

  
  return 0;

  }

void getBin(int num, char *str)
{
  *(str+5) = '\0';
  int mask = 0x10 << 1;
  while(mask >>= 1)
    *str++ = !!(mask & num) + '0';
}
