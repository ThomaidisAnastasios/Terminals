#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int sh=0;
sem_t mutex;

void *increment_sh(void *i);
{
    int thread=*(int *)i;

    sem_wait(&mutex);
    sh++;

    printf("Thread=%d after going into boom area the value=%d was changed.\n",thread, sh);

    sem_post(&mutex);
    pthread_exit(0);
}

int main(void)
{
    int i,*thread[10];

    pthread_t threads[10];

    sem_init(&mutex,0,1);

    for(i=0;i<10;i++)
    {
        thread[i]=(int *)malloc(sizeof(int));
        *thread[i]=i;
        pthread_create(&threads[i],NULL,increment_sh,(void *)thread[i]);
    }

    for(i=0;i<10;i++)
        pthread_join(threads[i],NULL);

    sem_destroy(&mutex);

    printf("Last value.%d\n",sh);

    exit(0);
    return 0;
}

