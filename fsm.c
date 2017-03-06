#include <stdio.h>

#include "fsm.h"
#include "state_one.h"

static state_t actual_state;
static state_t next_state;

void fsm_init(void)
{
    actual_state = state_one;
    actual_state->start();
    printf("[%s] initial start\n", actual_state->name);
}

void fsm_run(void)
{
    next_state = actual_state->during();
    printf("[%s] during\n", actual_state->name);

    if( next_state != actual_state )
    {
        actual_state->stop();
        printf("[%s] stop\n", actual_state->name);
        actual_state = next_state;
        actual_state->start();
        printf("[%s] start\n", actual_state->name);
    }
}
