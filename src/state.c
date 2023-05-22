#include "state.h"

enum state states;

void switch_state(int s) {
    states = s;
}

enum state get_state() {
    return states;
}