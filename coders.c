#include "codexion.h"

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