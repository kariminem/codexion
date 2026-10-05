#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct s_shared_context
{
    pthread_mutex_t mutex;
    int             counter;
}   t_shared_context;

void *my_routine(void *args)
{
    t_shared_context *context;
    context = (t_shared_context *)args;
    int i = 10;
    while (i > 0){
        pthread_mutex_lock(&(context->mutex));
        if (context->counter == 0)
            {
                i--;
                printf("sending info!\n");
                context->counter = 1;
            }
        pthread_mutex_unlock(&(context->mutex));
    }
    return (NULL);
}

void    *listening(void *args)
{
    t_shared_context *context;
    context = (t_shared_context *)args;
    int i = 10;
    while (i > 0){
        pthread_mutex_lock(&(context->mutex));
        if (context->counter == 1)
            {
                i--;
                printf("got the info!\n");
                context->counter = 0;
            }
        pthread_mutex_unlock(&(context->mutex));
    }    return (NULL);
}


int main()
{
    t_shared_context *mutex_handler;
    mutex_handler = malloc(sizeof(t_shared_context));
    if (!mutex_handler)
        return (0);
    mutex_handler->counter = 0;
    pthread_mutex_init(&(mutex_handler->mutex), NULL);
    pthread_t thread_s;
    pthread_t thread_l;


    pthread_create(&thread_s, NULL, my_routine, mutex_handler);
    pthread_create(&thread_l, NULL, listening, mutex_handler);

    pthread_join(thread_s,NULL);
    pthread_join(thread_l,NULL);
    pthread_mutex_destroy(&(mutex_handler->mutex));
}