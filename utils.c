#include "codexion.h"

void loading(int wait_time)
{
    printf(".");
    fflush(stdout);
    sleep(wait_time);
    printf(".");
    fflush(stdout);
    sleep(wait_time);
    printf(".\n");
    fflush(stdout);
    sleep(wait_time);
}

void display_global_controller(t_controller *controller)
{
    printf("number of coders --> %d\n", controller->number_of_coders);
    fflush(stdout);
    printf("time_to_burnout --> %lu\n", controller->time_to_burnout);
    fflush(stdout);
    printf("time_to_compile --> %lu\n", controller->time_to_compile);
    fflush(stdout);
    printf("time_to_debug --> %lu\n", controller->time_to_debug);
    fflush(stdout);
    printf("time_to_refactor --> %lu\n", controller->time_to_refactor);
    fflush(stdout);
    printf("number_of_compiles_required --> %d\n", controller->number_of_compiles_required);
    fflush(stdout);
    printf("dongle_cooldown --> %lu\n", controller->dongle_cooldown);
    fflush(stdout);
    printf("scheduler --> %s\n", controller->scheduler);
    fflush(stdout);
}

void    display_coders(t_coder *coders, t_controller *controller)
{
    printf("DISPLAYING CODERS");
    loading(3);
    const char *state_strings[] = {
    "waiting",
    "compiling",
    "debugging",
    "refactoring"
};
    int i = 0;
    while ( i < controller ->number_of_coders)
    {
        printf("coder id --> %d\n", coders[i].id);
        printf("coder state --> %s\n", state_strings[coders[i].state]);
        printf("coder has a dongle or NOT --> %d\n", coders[i].has_dongle);
        printf("coder's last action timestamp --> %lu\n", coders[i].last_action);
        if (i+1 != controller -> number_of_coders)
            loading(1);
        i++;
    }
}