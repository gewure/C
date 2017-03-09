#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1

#define SIZE 10

/* Structures */
typedef struct Matrix {
	int values[SIZE][SIZE];
	int n;
} Matrix;

/* Function Headers */
int isSymetric(const Matrix*);

/*#################### FUNCTION DEFINITONS ###################################*/

/*
Function returns TRUE if input Matrix is symetric

Parameters[IN] Matrix *pMatrix
Parameters[OUT] 

Returns: TRUE|FALSE
*/
int isSymetric(const Matrix* pMatrix) {

	int isSym = TRUE;

	for(int i = 0; i < pMatrix->n && isSym !=FALSE; i++) {
		for(int j = 0; j < pMatrix->n && isSym != FALSE; j++) {
			//bedingung für Unsymetrie
			if(pMatrix->values[i][j] != pMatrix->values[j][i]) {
				isSym = FALSE;
			}

		} //--end of inner FOR
	} // --end of FOR

	//return the pseudo-Boolean
	return isSym;
}

/*#######################     MAIN      ######################################*/

/*
 No Arguments taken
 */
int main(int argc, char** args) {

	//Testing Time!
	// first a symetric one consisting only of 0s
	Matrix* matr = malloc(sizeof(Matrix)); 
	matr->n = 10;
	//fill values with 0
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j <10; j++) {
			matr->values[i][j]=0;
			//print it
			printf("%d ",matr->values[i][j]);
		}
		printf("\n");
	}
	
	// call isSymetric() function and store result in testRes
	int testRes = isSymetric(matr);
	
	printf("is it symetric? %d \n",testRes);

	//.. and a UNsymetric one
	Matrix* matr2 = malloc(sizeof(Matrix)); 
        matr2->n = 10;

        //fill values with 0
        for(int i = 0; i < 10; i++) {
                for(int j = 0; j <10; j++) {
			//make it unsymetric somewhere random..
		        if(i == 3 && j == 2)
				matr2->values[3][2]=4;
			else  //else fill it with 0
                        	matr2->values[i][j]=0;
                        //print it
                        printf("%d ",matr2->values[i][j]);
                }
                printf("\n");
        }
	//make it unsymetric somewhere random..
	matr2->values[3][2]=4;

       	// call isSymetric() function and store result in testRes
        int testRes2 = isSymetric(matr2);

        printf("is it symetric now? %d \n",testRes2);

	
	return 0;
}
