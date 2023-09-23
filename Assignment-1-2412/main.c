//
//  main.c
//  Assignment-1-2412
//
//  Created by Hunter Antal on 2023-09-23.
//

#include <stdio.h>
#include <stdlib.h>
// #include "dequeue.h"


#define INIT -128 // the queue should utilize -128 to signify empty queue elements.
#define UNDERFLOW (0x80 + 0x01) // when a dequeue operation encounters an underflow, it should return -127 to indicate this condition
#define OVERFLOW 0x80 + 0x02
#define BADPTR (0x80 + 0x03)
#define QUEUELIMIT (unsigned long) 1.20E2 // imagine this is a tatic cless member, used for some error checking

// data type Queue
struct Queue{
    unsigned long head;
    unsigned long tail;
    unsigned long length;
    unsigned long element_num;
    char *data;
};

void enqueue(struct Queue *q, int x); // prototype

void build(struct Queue** queue, unsigned long length){
    if((length>0)&&(length<=QUEUELIMIT)){// error checking for length val
        *queue = (struct Queue*) malloc(sizeof(struct Queue)); //allocate and typecast 1 Queue
        
        if(*queue){ // error checking if queue is null
            (*queue)->length=length;
            (*queue)->head = 1;
            (*queue)->tail = 1;
            (*queue)->element_num = 0;
            (*queue)->data = (char*) malloc(length * sizeof(char));
            printf("Queue built sucessfully with length %ld. \n", length);
        }
    }
};

char dequeue(struct Queue *q){
    if(q->element_num == 0) // check to see if the queue is empty
        printf("Queue Underflow!");
    
    char val = q->data[q->head];
    q->head = (q->head + 1)%q->length; // if head = length then set head = 0
    q->element_num--;
    printf("Element %c dequeued\n", val);
    return val;
}





// main added from assignment
int main(int argc, const char * argv[]) {
    
    struct Queue *qptr = NULL;

   
    
    build(&qptr, 5);

    // printf("%ld", qptr->element_num);
    // printf("%ld", qptr->length);

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

void enqueue(struct Queue *q, int x) {

    if (q->element_num >= q->length) { // checks if there are an equal amount of elements as there is room for them
        q->tail = 0;
        q->element_num = 0;
        printf("overflow\n");
        return;
    }

    // if (q->tail == q->length) {
    //     q->tail = 1; // initialises tail when enqueue first used
    // }  

    q->data[q->tail] = x; // sets value at tail equal to val x     
    q->tail++; // increments tail by one
    q->element_num++;    
    printf("element %d queued\n", x);
}