#ifndef CODEXION_H
# define CODEXION_H

#include "time.h"
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>


typedef struct s_shared_context
{
    pthread_mutex_t mutex;
    int counter;

}t_shared_context;

typedef struct s_controller
{
    long    last_compile_startl; 
    long    time_to_burnout;
    long    time_to_debug;
    long    time_to_refactor;
    long    time_to_compile;
    long    dongle_cooldown;
    int    number_of_compiles_required;
    int number_of_coders;
    int number_of_dongles;
    char * scheduler;
} t_controller;

typedef enum e_state
{
    STATE_WAITING,
    STATE_DEBUGGING,
    STATE_COMPILING,
    STATE_REFACTORING,
} t_state;

typedef struct s_coder
{
    int id;
    t_state state;
    int has_dongle;
    long last_action;
    t_controller *controller;
} t_coder;

typedef struct s_dongle
{
    pthread_mutex_t mutex;
    long available_at;
} t_dnogle;

t_coder*    init_coders(t_controller *controller);
void loading(int wait_time);
void display_global_controller(t_controller *controller);
void    display_coders(t_coder *coders, t_controller *controller);
int	verify_input(int argc, char **argv);
void parse_input(char **argv, t_controller *controller);
int display_errors(int e);
char **state_display();
void    init_threads(t_coder *coders, t_controller *controller);
void    *coder_routine(void *args);
#endif
