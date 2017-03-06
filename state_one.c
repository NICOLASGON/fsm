#include "fsm.h"
#include "state_one.h"
#include "state_two.h"

#include <stdio.h>
#include <stdint.h>

/****************************************************/
/* Internal state definition                        */
/****************************************************/

void start_state_one(void);
state_t during_state_one(void);
void stop_state_one(void);

static struct state_t internal_state = {
    .start = start_state_one,
    .during = during_state_one,
    .stop = stop_state_one,
    .name = "ONE"
};

state_t state_one = &internal_state;

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

void start_state_one(void)
{
    i = 0;
}

state_t during_state_one(void)
{
    state_t next_state = state_one;

    if( i++ == 5 )
        next_state = state_two;

    return next_state;
}

void stop_state_one(void)
{

}
