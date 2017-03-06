#include <stdio.h>
#include <unistd.h>

#include "fsm.h"

void start_hook(state_t state)
{
    printf("[%s] start hook\n", state->name);
}

void during_hook(state_t state)
{
    printf("[%s] start during\n", state->name);
}

void stop_hook(state_t state)
{
    printf("[%s] start stop\n", state->name);
}

int main(void)
{
    fsm_register_start_hook(start_hook);
    fsm_register_during_hook(during_hook);
    fsm_register_stop_hook(stop_hook);
    
    fsm_init();
    while(1)
    {
        fsm_run();
        usleep(300000);
    }

    return 0;
}
