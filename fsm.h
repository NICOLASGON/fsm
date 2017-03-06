#ifndef __FSM_H__
#define __FSM_H__

typedef struct state_t *state_t;
struct state_t {
    void (*start)(void);
    state_t (*during)(void);
    void (*stop)(void);
};

#endif
