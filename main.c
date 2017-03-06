#include <unistd.h>

#include "fsm.h"

int main(void)
{
    fsm_init();
    while(1)
    {
        fsm_run();
        usleep(300000);
    }

    return 0;
}
