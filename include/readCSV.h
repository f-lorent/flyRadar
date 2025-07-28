//
// Created by florent on 27/07/25.
//

#ifndef READCSV_H
#define READCSV_H

typedef struct
{
    char *   city;
    char *   city_ascii;
    double    lat;
    double    lng;
    char *   country;
    char *   iso2;
    char *   iso3;
    char *   admin_name;
    char *   capital;
    int      population;
    int      id;
}
cityInfos_t;

void readCSV(void);

#endif //READCSV_H
