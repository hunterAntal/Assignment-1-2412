//
//  main.c
//  Assignment-1-2412
//
//  Created by Hunter Antal on 2023-09-23.
//

#include <stdio.h>
#include <stdlib.h>
//#include "dequeue.h"




#define QUEUELIMIT 200 // imagine this is a tatic cless member, used for some error checking

// data type Queue
struct Queue{
    unsigned long head;
    unsigned long tail;
    unsigned long length;
    unsigned long element_num;
    int *data; // array
};

void build(struct Queue** queue, unsigned long length){
    if((length>0)&&(length<=QUEUELIMIT)){// error checking for length val
        *queue = (struct Queue*) malloc(sizeof(struct Queue)); //allocate and typecast 1 Queue
        
        if(*queue){ // error checking if queue is null
            (*queue)->length=length;
            (*queue)->head = 1;
            (*queue)->tail = 1;
            (*queue)->element_num = 0;
            (*queue)->data = (int*) malloc(length * sizeof(int));
            printf("Queue built sucessfully with length %ld. \n", length);
        }
    }
};

int dequeue(struct Queue *q){
    if(q->element_num == 0){ // check to see if the queue is empty
        printf("Queue Underflow!");
        return 0;
    }
    int val = q->data[q->head];
    q->head = (q->head + 1)%q->length; // if head = length then set head = 0
    q->element_num--;
    printf("Element %c dequeued\n", val);
    return val;
}


//void enqueue(struct Queue *q, int x){
//    if(q->element_num>=q->length){
//        printf("Queue overflow!\n");
//        return;
//}
//    q->data[q->tail] = x;
//    q->tail = (q->tail + 1)%q->length; // increment tail, if tail = length then set tail = 0
//    q->element_num++;
//    printf("Element %d enqueued.\n", x);
//}


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

