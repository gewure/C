#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//header
char* getString();  //<- with malloc (good practice)
char * getStringNoMalloc();  //<- without malloc (fails! don't do this!)
void getStringCallByRef(char* reference); //<- callbyref (good practice)

// main
int main(int argc, char*argv[]) {

	//######### calling with malloc
	char * a = getString();
	printf("MALLOC ### a = %s \n", a);	
	free(a);

	//######### calling without malloc
	char * b = getStringNoMalloc();
	printf("NO MALLOC ### b = %s \n", b); //this doesnt work, question to sebi: WHY?
	//HINT: the warning says that a local reference is returned. ??!
	//NO free
	
	//######### call-by-reference
	char c[100];
	getStringCallByRef(c);
	printf("CALLBYREF ### c = %s \n", c);

	return 0;
}

//WITH malloc
char* getString() {

	char * string;
	string = malloc(sizeof(char)*100);

	strcat(string, "bla");
	strcat(string, "/");
	strcat(string, "blub");

	printf("string : '%s'\n", string);

	return string;
}

//WITHOUT malloc (watch how it does not work this time)
char* getStringNoMalloc() {

	char string[100] = {};

        strcat(string, "bla");
        strcat(string, "/");
        strcat(string, "blub");
	//INSIDE this function "string" is OK
        printf("string : '%s'\n", string);

        return string; //but after returning.. it is NULL? :)

}

// ..and the call-by-reference way to do it (prefered)
void getStringCallByRef(char* reference) {

	strcat(reference, "bla");
        strcat(reference, "/");
        strcat(reference, "blub");
        //INSIDE this function "string" is OK
        printf("string : '%s'\n", reference);
	//OUTSIDE it is also OK because we hand over a reference defined in MAIN
	// and not defined in this scope (local), which is destroyed after the function finished

}
