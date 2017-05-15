//gcc 5.4.0

#include  <stdio.h>

/* function header*/
int sum(int a[], int len);
int sumWptr(int a[], int len);

/* normal, using arrayindex */
int sum(int a[],int len) {
    int sum = 0;
    
    while(len > 0) {
        sum+=a[len-1];  //array indexing
        len--;
    }
    
    return sum;
}

/* using pointer */
int sumWptr(int a[], int len) {
    int sum = 0;
    for(int i = 0; i< len; i++) {
       sum += *(a+i); //pointer arithmetic
       //sum += *(a++); // same but cooler
    }
    return sum;
}

/* main */
int main(void) {
    int arr[100];
        
    for (int i = 0; i < 100; i++)
        arr[i] = i;
    
    int s =  sum(arr, 100);  //array indexing
    printf("%d \n", s);
    
        
    int s2 =  sumWptr(arr, 100); //pointer arithmetic
    printf("%d \n", s2);
}
