#ifndef __FSM_H__
#define __FSM_H__

#define MAX_SIZE_STATE_NAME

typedef struct state_t *state_t;
struct state_t {
    void (*start)(void);
    state_t (*during)(void);
    void (*stop)(void);

    char name[MAX_SIZE_STATE_NAME];
};

#endif
