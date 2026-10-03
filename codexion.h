#ifndef CODEXION_H
# define CODEXION_H

#include "time.h"
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#endif
