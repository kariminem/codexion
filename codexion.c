#include "codexion.h"


int main(int argc, char **argv)
{
    int e = verify_input(argc, argv);
    if (display_errors(e) == 0)
    {
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
    }
    return (0);
}