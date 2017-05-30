# C
KISS C application examples

Basically some popular tiny challenges that people struggle with when starting to learn C.
Can be described as 'didactic examples'. 

# ptrToPtrFree.c
  Example shows how to free (and securely free) a List-struct by freeing its pointer,
  which is handed over by call-by-reference,  thus a pointer to a pointer. 

# callbackFuncPtr.c
  Shows how to utilize function-pointers to get callback-functionality in C

# functionPtr.c
  Implements a map-function that calls functions via function-pointers on an array,
  explains how function-pointers are used and what they are good for
  
# recursiveMultiply.c
  How to implement multiplication of two numbers using recursion

# linkedList.c
  Example-Implementation of a singly linkedList in c existing on the heap. 
  supported functions: 
        LinkedList* init_list();
        void insert_end(LinkedList *list, int key, char string[]);
        void insert_beginning(LinkedList *list, int key, char string[]);
        int remove_end(LinkedList *list);
        int remove_beginning(LinkedList *list);
        int print_list(LinkedList *list);
        void free_list(LinkedList *list);
        char * get_string(LinkedList *list, int key);
# matrix.c
  example application for an simple Matrix-struct and a function that evaluates if a given Matrix is symetric
# pyramid.c
  asks for number of rows, prints all odd numbers in a pyramid
  
# bitToggle.c
  example of how to toggle, invert, set, get bits in a bitfield
 
# hexDump.c
  cool tool to analyze the memory of string in c, very didactic :)
  
# intHexBin.c
  tool that helps in understanding the different representations of values: dez, hex, bin

# retCharPtr.c
  This example shows why in C one can't simply return an dynamicaly long string from a function
  it explains call-by-reference, dynamical allocation with malloc, and defunct returning utilizing the popular local-scope mistake

# intToBin.c
  Simple reading of programm argument, parsing it from char ptr to int using itoa(..), then converting it to a binary-string with a  function by call-by-reference. 
  
# arrSumPtrArithmetic.c
  Simple example showing how to sum up a array 1) using 'normal' array indexing and 2) using pointer arithmetic
  
# callByReference.c
  Simple example showing call-by-reference

# callByRefSwap.c
  Simple example showing how to swap two variables using call-by-reference

# heapMemVsStackMem.c
  Example showing what happens if you incorrectly malloc memory. After a function exits, the Stack is GONE, and so are values allocated in it.
  
# stupidLinkedList.c
  A very simple linked list example
  
# structOffset.c
  Shows with pointer arithmetic how the byte-offsets of a struct work in C
  
# arrayType.c
  how to define and use a typedef "Array" which knows its size and does bounds-checking when accessing it.
  It is allocated on the heap and freed after usage. Good example of call-by-reference,
  Heap-memory allocation and how to use types in a effective manner. 
  
# shlemielThePainter.c
  this example was motivated by this ancient(2001) blogpost by Joel Spolsky
  https://www.joelonsoftware.com/2001/12/11/back-to-basics/
  
# bitField.c
  What and how to do something using bitfields

  
