#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int counter = 0;

void *fun(size_t x)
{
    for (size_t i = 0; i < 10000000ULL; i++)
        counter += (size_t)x;
};

int main()
{
    pthread_t t;
    pthread_create(&t,0,(void* (*) (void*))&fun, (void *) 1);
    pthread_create(&t,0,(void* (*) (void*))&fun, (void *) 2);
    /*mypause();*/
    printf("counter = %d\n", counter);
    return 0;
}