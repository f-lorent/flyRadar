//
// Created by florent on 18/07/25.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../librairies/cJSON.h"
#include "../include/parse.h"

typedef struct {
    int time;
    states_t states;
}data_t;

states_t *initMalloc(cJSON *states) {
    return malloc(cJSON_GetArraySize(states) * sizeof(states_t));
}

void parseStates(cJSON *states, states_t *output) {
    volatile int size = cJSON_GetArraySize(states);
    for (int i = 0; i < size; i++) {
        cJSON *state = cJSON_GetArrayItem(states, i);

        if (cJSON_IsArray(state)) {
            cJSON *icao24 = cJSON_GetArrayItem(state, 0);
            cJSON *callsign = cJSON_GetArrayItem(state, 1);
            cJSON *origin_country = cJSON_GetArrayItem(state, 2);
            cJSON *time_position = cJSON_GetArrayItem(state, 3);
            cJSON *longitude = cJSON_GetArrayItem(state, 5);
            cJSON *latitude = cJSON_GetArrayItem(state, 6);
            cJSON *baro_altitude = cJSON_GetArrayItem(state, 7);
            cJSON *on_ground = cJSON_GetArrayItem(state, 8);
            cJSON *velocity = cJSON_GetArrayItem(state, 9);

            output[i].icao24 = icao24->valuestring;
            output[i].callsign = callsign->valuestring;
            output[i].origin_country = origin_country->valuestring;
            output[i].time_position = time_position->valueint;
            output[i].longitude = longitude->valuedouble;
            output[i].latitude = latitude->valuedouble;
            output[i].baro_altitude = baro_altitude->valuedouble;
            output[i].on_ground = on_ground->valueint;
            output[i].velocity = velocity->valuedouble;
        }
    }
}


void parse(const char *data) {
    cJSON *root = cJSON_Parse(data);
    cJSON *time = cJSON_GetObjectItem(root, "time");
    cJSON *states = cJSON_GetObjectItem(root, "states");

    states_t *statesArray = initMalloc(states);
    parseStates(states, statesArray);
    printf("%d\n", statesArray[0].on_ground);

    free(statesArray);
    cJSON_Delete(root);
}