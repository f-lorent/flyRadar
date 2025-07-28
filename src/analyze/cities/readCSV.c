//
// Created by florent on 27/07/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../include/readCSV.h"


#define DELIM        ","
#define BUFF_SIZE    128




typedef enum
{
   CITY,
   CITY_ASCII,
   LAT,
   LNG,
   COUNTRY,
   ISO2,
   ISO3,
   ADMIN_NAME,
   CAPITAL,
   POPULATION,
   ID
}
infos_type;


static char * str_dup (const char * str)
{
   char * dup = NULL;


   if (str != NULL)
   {
      size_t size = strlen (str) + 1;
      dup = malloc (size);

      if (dup != NULL)
      {
         memcpy (dup, str, size);
      }
   }


   return dup;
}


static cityInfos_t * get_contact (const char * filename)
{
   cityInfos_t  *  infos = NULL;
   FILE           *  file  = NULL;
   char           *  token = NULL;
   char              buff [BUFF_SIZE];


   file = fopen (filename, "r");

   if (file != NULL)
   {
      if ((fgets (buff, BUFF_SIZE, file)) != NULL) {}

      if ((fgets (buff, BUFF_SIZE, file)) != NULL)
      {
         char *   p = buff;
         int      i = 0;


         infos = malloc (sizeof (* infos));

         if (infos != NULL)
         {
            while ((token = strtok (p, DELIM)) != NULL)
            {
               if (i == 0)
                  p = NULL;

               switch (i)
               {
                  case CITY:
                     infos->city = str_dup (token);
                     break;

                  case CITY_ASCII:
                     infos->city_ascii = str_dup (token);
                     break;

                  case LAT:
                     infos->lat = strtod (token, NULL);
                     break;

                  case LNG:
                     infos->lng = strtod (token, NULL);
                     break;

                  case COUNTRY:
                     infos->country = str_dup (token);
                     break;

                  case ISO2:
                     infos->iso2 = str_dup (token);
                     break;

                  case ISO3:
                     infos->iso3 = str_dup (token);
                     break;

                  case ADMIN_NAME:
                     infos->admin_name = str_dup (token);
                     break;

                  case CAPITAL:
                     infos->capital = str_dup (token);
                     break;

                  case POPULATION:
                     infos->population = atoi (token);
                     break;

                  case ID:
                     infos->id = atoi (token);
                     break;

                  default:
                     break;
               }

               i++;
            }
         }
      }

      fclose (file);
   }


   return infos;
}


static void free_contact_infos (cityInfos_t ** p)
{
   if (p != NULL && *p != NULL)
   {
      free ((*p)->city);
      free ((*p)->city_ascii);
      free ((*p)->country);
      free ((*p)->iso2);
      free ((*p)->iso3);
      free ((*p)->admin_name);
      free ((*p)->capital);

      free (*p);
      *p = NULL;
   }
}



void readCSV(void)
{
   cityInfos_t * infos = get_contact ("../librairies/citiesDB/worldcities.csv");

   if (infos != NULL)
   {
      printf (
         "Ville : %s \nlatitude : %f\nlongitude %f\n\n",
         infos->city, infos->lat, infos->lng
      );

      free_contact_infos (& infos);
   }
}