//gcc 5.4.0
#include  <stdio.h>

/* a linked list of int*/
struct Node {
    int val;
    struct Node *next;  // pointer to next node
};

int main(void)
{
    struct Node n1;
    struct Node n2;
    struct Node n3;
    struct Node n4;
    
    n1.val = 3;
    n2.val = 6;
    n3.val = 9;
    n1.next = &n2;  // reference to next node
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;  //closing note
    
    struct Node* current = &n1;
    
    while(current->next != NULL){
        printf("%d \n",current->val);
        current = current->next;
    }
    
}
