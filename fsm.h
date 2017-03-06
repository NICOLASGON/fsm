#ifndef __FSM_H__
#define __FSM_H__

#define MAX_SIZE_STATE_NAME 50

typedef struct state_t *state_t;
struct state_t {
    void (*start)(void);
    state_t (*during)(void);
    void (*stop)(void);

    char name[MAX_SIZE_STATE_NAME];
};

void fsm_init(void);
void fsm_run(void);

typedef void (*hook)(state_t state);

void fsm_register_start_hook(hook h);
void fsm_register_during_hook(hook h);
void fsm_register_stop_hook(hook h);

#endif
