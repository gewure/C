//gcc 5.4.0
#include  <stdio.h>

struct Message {
unsigned int isConnected : 1;
unsigned int activePort : 4;
unsigned int timestamp : 11;
unsigned int data : 16;
};

int main(void) {

    struct Message m = {1, 3, 1035, 23000};
    int i = *((int *)&m); // Save all in 4 byte value
    
    //here you could send i over the network..

    struct Message n = *((struct Message *)&i); //..and here you cast it back into a Message
    
    printf("Content of i = %d\n", i);
    printf("%d %d %d %d", n.isConnected, n.activePort, n.timestamp, n.data);
    
}
