int *get_init_memory_heap(int size) {
int *p = malloc(size * sizeof(int)); // This is on the heap
for (int i = 0; i < size; i++)
p[i] = size - i;
return p;
}
int *get_init_memory_stack(int size) {
int arr[size]; // This is on the stack
int *p = arr;  //if you would'nt wrapp arr into a pointer, this would give a compiler warning "function returns address of local variable")
for (int i = 0; i < size; i++)
p[i] = size - i;
return p;  //WONT WORK! (
}
int main() {
int *ps = get_init_memory_stack(20);
int *ph = get_init_memory_heap(20);
printf("ph[5] = %d\n", ph[5]);  //prints a correct value
printf("ps[5] = %d\n", ps[5]);  //prints a wrong value (stack is long gone, this value is undefined behaviour)
}
