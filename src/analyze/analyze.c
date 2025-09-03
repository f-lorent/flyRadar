//
// Created by florent on 27/07/25.
//

#include <math.h>

#include "../../include/readCSV.h"
#include "../../include/analyze.h"

#include <stdio.h>

#include "../../include/nCursePrint.h"

#define RAYON_EARTH 6371.0
#define TRESHOLD 15.0

static cityInfos_t saumur =
    {
    "Paris",
    "Paris",
    48.8567,
    2.3522,
    "France",
    "FR",
    "FRA",
    "Île-de-France",
    "primary",
    11060000,
    1250015082
    };

double angularDistance(double lat1, double lat2, double lon1, double lon2) {
    double lat1_rad = lat1 * M_PI / 180.0;
    double lat2_rad = lat2 * M_PI / 180.0;
    double lon1_rad = lon1 * M_PI / 180.0;
    double lon2_rad = lon2 * M_PI / 180.0;

    double delta =  acos(sin(lat1_rad) * sin(lat2_rad) + cos(lat1_rad) * cos(lat2_rad) * cos(lon1_rad - lon2_rad));
    return delta * RAYON_EARTH;
}

void analyze(const parse_t * parse) {
    int size = parse->size;
    for (int i = 0; i < size; i++) {
        double distance = angularDistance(saumur.lat, parse->states[i].latitude, saumur.lng, parse->states[i].longitude);
        if (distance < TRESHOLD) {
            printf("Callsign : %s \nProvenance : %s\nVitesse %f\n\n",
                   parse->states[i].callsign, parse->states[i].origin_country, parse->states[i].velocity
            );
        }
    }
}


