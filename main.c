#include <stdio.h>
#include <unistd.h>

#include "fsm.h"
#include "state_one.h"

int main(void)
{
    state_t actual_state = state_one;
    state_t next_state;

    actual_state->start();
    printf("[%s] start\n", actual_state->name);
    while(1)
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
        usleep(300000);
    }

    return 0;
}
