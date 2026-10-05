#include "codexion.h"

int verify_input(int argc, char **argv)
{
    if (argc < 9)
        return (-9);
    else if (argc > 9)
        return (10);
    int i = 1;
    while (i < argc)
    {
        if (atoi(argv[1]) < 1)
            return (-4);
        if (((strcmp("edf", argv[8]) != 0) && (strcmp("fifo", argv[8]) != 0)))
            return (-1);
        if (i != 8 && atoi(argv[i]) < 0)
            return (-2);
        if (i != 8 && atoi(argv[i]) == 0)
            return (-3);
        i++;
    }
    return (4);
}

void parse_input(char **argv, t_controller *controller)
{
    controller->number_of_coders = atoi(argv[1]);
    
    controller->number_of_dongles = controller->number_of_coders;

    controller->time_to_burnout = atoi(argv[2]);

    controller->time_to_compile = atoi(argv[3]);

    controller->time_to_debug = atoi(argv[4]);

    controller->time_to_refactor = atoi(argv[5]);

    controller->number_of_compiles_required = atoi(argv[6]);

    controller->dongle_cooldown = atoi(argv[7]);

    controller->scheduler = (argv[8]);
    loading(1);
    display_global_controller(controller);
}

int display_errors(int e)
{
    if (e == -9)
        printf("too few arguments\n");
    else if (e == 10)
        printf("too many arguments\n");
    else if (e == -1)
        printf("schedule input unknown, only 'edf' or 'fifo'\n");
    else if (e == -2)
        printf("cant input negative numbers\n");
    else if (e == -3)
        printf("string found when an integer was expected\n");
    else if (e == -4)
        printf("number of coders can't be less than 1\n");
    else
        return (0);
    return (-1);
}
