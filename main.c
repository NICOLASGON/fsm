#include <stdio.h>
#include <unistd.h>

#include "fsm.h"
#include "state_one.h"

int main(void)
{
    state_t actual_state = state_one;
    state_t next_state;

    actual_state->start();
    while(1)
    {
        next_state = actual_state->during();

        if( next_state != actual_state )
        {
            actual_state->stop();
            actual_state = next_state;
            actual_state->start();
        }
        usleep(300000);
    }

    return 0;
}
