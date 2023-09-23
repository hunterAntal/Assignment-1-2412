//
//  main.c
//  Assignment-1-2412
//
//  Created by Hunter Antal on 2023-09-23.
//

#include <stdio.h>

#define INIT -128 // the queue should utilize -128 to signify empty queue elements.
#define UNDERFLOW (0x80 + 0x01) // when a dequeue operation encounters an underflow, it should return -127 to indicate this condition
#define OVERFLOW 0x80 + 0x02
#define BADPTR (0x80 + 0x03)
#define PQLIMIT (unsigned long) 1.20E2 // imagine this is a tatic cless member, used for some error checking

// data type Queue
struct Queue{
    unsigned long head;
    unsigned long tail;
    unsigned long length;
    unsigned long element_num;
};

struct Queue* build(unsigned long length){
    struct Queue* queue = NULL; //create a null pointer of type Queue
};








// main added from assignment
int main(int argc, const char * argv[]) {
    
    struct Queue *qptr = NULL;
    
    build(&qptr, 5);
    // ====== Beginn Test Case 1
    enqueue(qptr, 1);
    enqueue(qptr, 2);
    enqueue(qptr, 3);
    enqueue(qptr, 4);
    enqueue(qptr, 5);
    enqueue(qptr, 6);
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    printf("Dequeue() %d \n", dequeue(qptr));
    // ====== End Test Case 1
    
    // free anything that was created with malloc!
    if (qptr->data) free(qptr->data);
    if(qptr) free(qptr);
    printf("\n");
    return 0;
}
