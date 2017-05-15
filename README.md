# C
KISS C application examples

Basically some popular tiny challenges that people struggle with when starting to learn C.
Can be described as 'didactic examples'. 

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
