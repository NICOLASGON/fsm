#include "fsm.h"
#include "state_one.h"
#include "state_two.h"

#include <stdio.h>
#include <stdint.h>

/****************************************************/
/* Internal state definition                        */
/****************************************************/

void start_state_two(void);
state_t during_state_two(void);
void stop_state_two(void);

static struct state_t internal_state = {
    .start = start_state_two,
    .during = during_state_two,
    .stop = stop_state_two
};

state_t state_two = &internal_state;

/****************************************************/
/* Public variables definition                      */
/****************************************************/

/****************************************************/
/* Private variables definition                     */
/****************************************************/

static uint8_t i = 0;

/****************************************************/
/* State API methods                                */
/****************************************************/

void start_state_two(void)
{
    printf("Start state_two !\n");

    i = 0;
}

state_t during_state_two(void)
{
    state_t next_state = state_two;

    printf("During state_two...\n");
    
    if( i++ == 5 )
        next_state = state_one;

    return next_state;
}

void stop_state_two(void)
{
    printf("Stop state_two !\n");
}
