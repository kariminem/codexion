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

int	verify_input(int argc, char **argv)
{
	int i = 0;
	while (i < argc)
	{
		if (((strcmp("edf", argv[8]) != 0) && (strcmp("fifo", argv[8]) != 0)))
		{
			return (-1);
		}
		if (i != 9 && atoi(argv[i]) < 0)
			return (-2);
		i++;
	}
	return (4);
}

void parse_input(char **argv, t_controller *controller)
{
    controller->number_of_coders = atoi(argv[1]);

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

t_coder*    init_coders(t_controller *controller)
{
    t_state state;
    t_coder *coders = malloc(sizeof(t_coder) * controller->number_of_coders);
    long curr_time = init_time();
    if (!coders)
        return NULL;
    int i = 0;
    state = STATE_WAITING;
    while (i < controller->number_of_coders)
    {
        coders[i].id = i + 1;
        coders[i].state = state;
        coders[i].has_dongle = 0;
        coders[i].last_action = get_time_ms(&curr_time);
        coders[i].controller = controller;
        i++;
    }
    return (coders);
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

int main(int argc, char **argv)
{
	if (verify_input(argc,argv) != 4 || argc != 9)
	{
		if (verify_input(argc, argv) == -1 )
		{
			printf("schedule input unknown, only 'edf' or 'fifo'");
		}
		if (verify_input(argc,argv) == -2)
		{
			printf("cant input negative numbers");
		}
		printf("INPUT ERROR\n");
		return (-1);
	}
    t_controller *controller;
    t_coder *coders;
    controller = malloc(sizeof(t_controller));
    if (!controller)
        return (-1);
    else
    {
        parse_input(argv, controller);
        coders = init_coders(controller);
        display_coders(coders, controller);
    }
    free(controller);
    free(coders);
    return (0);
}