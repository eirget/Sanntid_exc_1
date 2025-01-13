// Compile with `gcc foo.c -Wall -std=gnu99 -lpthread`, or use the makefile
// The executable will be named `foo` if you use the makefile, or `a.out` if you use gcc directly

#include <pthread.h>
#include <stdio.h>

int i = 0;

pthread_mutex_t lock;

// Note the return type: void*
void* incrementingThreadFunction(){
    // TODO: increment i 1_000_000 times
    for(int j = 0; j < 1000000; j++) {
        pthread_mutex_lock(&lock);
        i++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* decrementingThreadFunction(){
    // TODO: decrement i 1_000_000 times
    for(int j = 0; j < 999999; j++) {
        pthread_mutex_lock(&lock);
        i--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

//MUTEX: using mutex lock will synchronize access to the shared variable, best to use mutex scince there is only one shared resource here
//mutex locks are often used when it is important that only one thread at a time should access the resource
//
//semaphores are more used for other purposes when several threads can access a resource concurrently


int main(){
    // TODO: 
    // start the two functions as their own threads using `pthread_create`
    // Hint: search the web! Maybe try "pthread_create example"?
    pthread_t iThread;
    pthread_t dThread;
    
    pthread_mutex_init(&lock, NULL);

    if(pthread_create(&iThread, NULL, incrementingThreadFunction, NULL) != 0) {
        perror("pthread_create() error");
    }
    if(pthread_create(&dThread, NULL, decrementingThreadFunction, NULL) != 0) {
        perror("pthread_create() error");
    }
    
    // TODO:
    // wait for the two threads to be done before printing the final result
    // Hint: Use `pthread_join`    

    if (pthread_join(iThread, NULL) != 0) {
        perror("pthread_join() error");
        }

    if (pthread_join(dThread, NULL) != 0) {
        perror("pthread_join() error");
        }

    pthread_mutex_destroy(&lock);

    printf("The magic number is: %d\n", i);

    
    return 0;
}
