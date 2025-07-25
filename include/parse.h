//
// Created by florent on 20/07/25.
//

#ifndef PARSE_H
#define PARSE_H

#include <stdbool.h>
#include "../librairies/cJSON.h"

typedef struct {
    char *icao24;
    char *callsign;
    char *origin_country;
    int time_position;
    float longitude;
    float latitude;
    float baro_altitude;
    bool on_ground;
    float velocity;
}states_t;

states_t *initMalloc(cJSON *states);

void parse(const char *data);

#endif //PARSE_H
