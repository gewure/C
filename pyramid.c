#include <stdio.h>

// header for the printOddNum() function
int printOddNumb();

// -1 because -1 +2 = 1 .... 1+2 = 3 ... 3+2 = 5..
int oddcount = -1;

int main(int argc, char* argv[])
{
    int rows, number = 1;

    printf("Enter number of rows: ");
    fflush(stdout);
    scanf("%d",&rows);


    for(int i=1; i <= rows; i++)
    {
        for(int j=1; j <= i; j++)
        {
	    // we now only need to call printOddNumb()
            printf("%d ", printOddNumb());
        }
        printf("\n");
    }
    return 0;
}

// function which returns an odd number. oddcount is incremented by 2 each time it is called
// returns 1 on first run, 3 on second, 5 on third, 7 on fourth... 
int printOddNumb() {
     oddcount+=2;
    return oddcount;
}
