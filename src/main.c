#include <stdio.h>
#include <stdlib.h>

#include "../include/logic.h"

static const char *url = "https://opensky-network.org/api/states/all";

int main(void) {
    stateMachine(url);
    return 0;
}