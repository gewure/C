//gcc 5.4.0
#include  <stdio.h>

struct Message {
    unsigned int isConnected : 1;
    unsigned int activePort : 4;
    unsigned int timestamp : 11;
    unsigned int data : 16;
};

union Msgdecode {
    int datablob;
    struct Message components;
};

int main(void) {

    int datablob = 1507361127;  // equals a Message with {1, 3, 1035, 23000}
    union Msgdecode m;
    m.datablob = datablob;
    
    printf("%d %d %d %d \n", m.components.isConnected, m.components.activePort,
    m.components.timestamp, m.components.data); //this way we save casting
    
    union Msgdecode m2;
    m2.components.isConnected = 0;
    m2.components.activePort = 12;
    m2.components.timestamp = 1203;
    m2.components.data = 23000;
    
    printf("%d\n", m2.datablob); //magic!
    printf("%d %d %d %d \n", m2.components.isConnected, m2.components.activePort,
    m2.components.timestamp, m2.components.data);
}
