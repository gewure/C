#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getNumberAsBin(int n, char** binBuff);

void getNumberAsBin(int n,char** binBuff) {
    	int c, k;
	int typeLength = 32;
	*binBuff = malloc(sizeof(int)<<4);
	for (c = 31; c >= 0; c--) {
		k = n >> c;
                if (k & 1)
                	strcat(*binBuff,"1");
                else
                        strcat(*binBuff,"0");
        }
        printf("%d(dez) = %s(bin) \n", n, *binBuff);
}

int main(int argc, char* args[]) {

int n;
if(argc)
 n = atoi(args[1]);

char *binBuff;

getNumberAsBin(n, &binBuff);

}
