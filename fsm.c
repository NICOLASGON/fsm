#include <stdio.h>

#include "fsm.h"
#include "state_one.h"

static state_t actual_state;
static state_t next_state;

static hook start_hook = NULL;
static hook during_hook = NULL;
static hook stop_hook = NULL;

void fsm_init(void)
{
    actual_state = state_one;
    actual_state->start();
    if( start_hook )
        start_hook(actual_state);
}

void fsm_run(void)
{
    next_state = actual_state->during();
    if( during_hook )
        during_hook(actual_state);

    if( next_state != actual_state )
    {
        actual_state->stop();
        if( stop_hook )
            stop_hook(actual_state);

        actual_state = next_state;

        actual_state->start();
        if( start_hook )
            start_hook(actual_state);
    }
}

void fsm_register_start_hook(hook h)
{
    if(h)
        start_hook = h;
}

void fsm_register_during_hook(hook h)
{
    if(h)
        during_hook = h;
}

void fsm_register_stop_hook(hook h)
{
    if(h)
        stop_hook = h;
}
