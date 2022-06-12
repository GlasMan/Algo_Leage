#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int mail;

void    *do_som(void *mutex)
{
    int i = 0;
    pthread_mutex_lock(mutex);
    while (i++ < 30000000)
        mail++;
    pthread_mutex_unlock(mutex);
}

int main()
{
    int i;
    pthread_t *t1;
    pthread_mutex_t mutex; 
    pthread_mutex_init(&mutex, NULL);
    for(i = 0; i < 5; i++)
        pthread_create(&t1[i], NULL, &do_som, &mutex);
    for(i = 0; i < 5; i++)
        pthread_join(t1[i], NULL);
    printf("%d\n", mail);
    pthread_mutex_destroy(&mutex);
}