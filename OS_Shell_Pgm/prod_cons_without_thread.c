#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

int buffer[BUFFER_SIZE];
int counter, in, out; 

// counter -> presently number of items in buffer
// in -> position to produce
// out -> position from where you need to consume

// counter -> register -> register + 1 -> counter
// counter -> register -> register - 1 -> counter

void *producer(void *arg) {
    while (1) {
        /* produce an item in nextProduced */
        while (counter == BUFFER_SIZE); 
        buffer[in] = 1;
        in = (in + 1) % BUFFER_SIZE;
        counter++;
        printf("%d :: producer\n", counter);
    }
}
void *consumer(void *arg) {
    while (1) {
        /* consume an produced item */
        while (counter == 0);
        buffer[out] = 0;
        out = (out + 1) % BUFFER_SIZE;
        counter--; 
        printf("%d :: consumer\n", counter);
    }
}
int main(int argc, char *argv[]) { 
    pthread_t tp, tc; // thread for producer and consumer respectively 
    pthread_attr_t attr;  
    pthread_attr_init(&attr); // used to set the default attributes	
    
    pthread_create(&tp, &attr, producer, NULL); // producer thread
    pthread_create(&tc, &attr, consumer, NULL); // consumer thread
    
    pthread_join(tp, NULL);
    pthread_join(tc, NULL); 
    return 0;
}                               