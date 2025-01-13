// Compile with `gcc foo.c -Wall -std=gnu99 -lpthread`, or use the makefile
// The executable will be named `foo` if you use the makefile, or `a.out` if you use gcc directly

#include <pthread.h>
#include <stdio.h>

int i = 0;

// Note the return type: void*
void* incrementingThreadFunction(){
    // TODO: increment i 1_000_000 times
    for(int j = 0; j < 1000000; j++) {
        i++;
    }
    return NULL;
}

void* decrementingThreadFunction(){
    // TODO: decrement i 1_000_000 times
    for(int j = 0; j < 1000000; j++) {
        i--;
    }
    return NULL;
}


int main(){
    // TODO: 
    // start the two functions as their own threads using `pthread_create`
    // Hint: search the web! Maybe try "pthread_create example"?
    pthread_t iThread;
    pthread_t dThread;

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


    printf("The magic number is: %d\n", i);
    return 0;
}
