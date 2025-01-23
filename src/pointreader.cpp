#include "pointreader.h"
#include <stdio.h>
#include <stdlib.h>
int readPoints(const char* file, point_t** points) {
    
        FILE* fp = fopen(file, "r"); //Fitxategia irekitzen
        if (!fp) {
            printf("Error: No se puede abrir el archivo %s\n", file);
            return -1; // Fitxategia irekitzeko errorea
        }

        int capacity = 10; // Arrayaren hasierako tamaina
        int count = 0;     // Irakurritako zenbaki kopurua
        *points = (point_t*)malloc(capacity * sizeof(point_t)); // lerro honek point_t array bat gordetzeko adina memoria esleitzen du,
                                                                //eta memoria-bloke horren helbidea erakuslean gordetzen du *points.
                                                                //Horri esker, array-a dinamikoki haz daiteke, beharrezkoa den heinean.

        if (!*points) { //Pasautako helbidearen edukia "0" baldin bada ez zaio memoria bat esleitzen
            printf("Error: No se pudo asignar memoria\n");
            fclose(fp); //Fitxategia itsi egiten da.
            return -1;
        }

        while (!feof(fp)) { //irakurtzen ari zaren bitartean fitxategi baten amaierara iritsi den edo ez. 
                            

            point_t p;
            if (fscanf(fp, "%lf,%lf,%lf", &p.x, &p.y, &p.time) == 3) {
                // Arraya betetzen bada, handitu egiten da.
                if (count >= capacity) {
                    capacity *= 2;
                    *points = (point_t*)realloc(*points, capacity * sizeof(point_t)); //kode-lerro honek *points-ek apuntatutako memoria-blokearen dimentsioa handitzen du.
                                                                                      // point_t motako elementu gehiago izan ditzan.
                                                                                      // Reallok-ek ezin badu memoria-blokearen dimentsioa handitu, NULL itzultzen du.
                                                                                      

                    if (!*points) { //Puntuak nuluak baldin badira, errorea ematen du.
                        printf("Error: No se pudo ampliar la memoria\n");
                        fclose(fp);
                        return -1;
                    }
                }
                (*points)[count++] = p; //kode-lerro honek p egitura arrayaren uneko posizioan gordetzen du,
                                        //eta gero count kontagailua handitzen du array-an erabilgarri
                                        // dagoen hurrengo posiziora apuntatu dezan.

            }
        }

        fclose(fp); //Fitxategia itsi egiten da.
        return count; // Irakurritako zenbakiak
    }








	//TODO 2. Read the file and save the data in a point_t array
	// Use libcsv: 
	//This sample could be useful https://github.com/rgamble/libcsv/blob/master/csv.pdf
	 //If there is an error reading the file

