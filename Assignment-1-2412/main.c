// Kamran Yaghoubian
// Hunter Antal

#include <stdio.h>
#include <stdlib.h>

#define QUEUELIMIT 200 // Maximum allowed size of the queue for error checking

// Declare a struct for the Queue
struct Queue{
    unsigned long head;
    unsigned long tail;
    unsigned long length;
    unsigned long element_num; // Number of elements in the queue
    char *data; // Array to hold the queue elements
};

// Function prototypes
void enqueue(struct Queue *q, char x);

// Function to initialize the queue
void build(struct Queue** queue, unsigned long length){
    if((length>0)&&(length<=QUEUELIMIT)){ // Check if the provided length is within the limit
        *queue = (struct Queue*) malloc(sizeof(struct Queue)); // Allocate memory for the queue
        if(*queue){ // Check if the memory was allocated successfully
            (*queue)->length = length;
            (*queue)->head = 0;
            (*queue)->tail = 0;
            (*queue)->element_num = 0;
            (*queue)->data = (char*) malloc(length * sizeof(char)); // Allocate memory for the data array
            printf("Queue built successfully with length %ld. \n", length);
        }
    }
}

// Function to dequeue an element
char dequeue(struct Queue *q){
    if (q != NULL) { // checks if queue exists
        if(q->element_num == 0){ // Check for underflow
            printf("Queue Underflow!\n");
            return 0;
        }
        int val = q->data[q->head]; // Save the value to be dequeued
        q->head = (q->head + 1) % q->length; // Update the head index
        q->element_num--; // Decrement the number of elements
        //printf("Element %d dequeued\n", val);
        return val;
    }
    else {
        printf("Build queue before dequeing\n");
    }
    return 0;
}

// Main function
int main(int argc, const char * argv[]) {
    struct Queue *qptr = NULL;
    
    dequeue(qptr);
    enqueue(qptr, 3);

    build(&qptr, 5); // Initialize the queue with size 5

    // Test Case 1
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

    // Free allocated memory
    if (qptr->data) free(qptr->data);
    if(qptr) free(qptr);
    
    return 0;
}

// Function to enqueue an element
void enqueue(struct Queue *q, char x) {
    if (q != NULL) { // checks if queue exists
        if (q->element_num >= q->length) { // Check for overflow
            printf("Overflow encountered\n");
            return;
        }
        q->data[q->tail] = x; // Insert the element at the tail
        q->tail++; // Update the tail index
        q->element_num++; // Increment the number of elements
        printf("Element %d queued.\n", x);
    }
    else {
        printf("Build queue before enqueuing\n");
    }
}
