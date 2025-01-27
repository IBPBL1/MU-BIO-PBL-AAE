#include "pointreader.h"
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int readPoints(const char* file, point_t** points) {
    FILE* fp;
    if (fopen_s(&fp, file, "r") != 0) {
        printf("Error: No se puede abrir el archivo %s\n", file);
        return -1;
    }
    printf("Archivo %s abierto correctamente\n", file);

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp); // Leer la primera línea (encabezado)

    int capacity = 2000; // Tamaño inicial del array
    int count = 0;     // Número de puntos leídos
    *points = (point_t*)malloc(capacity * sizeof(point_t));
    if (!*points) {
        printf("Error: No se pudo asignar memoria\n");
        fclose(fp);
        return -1;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        point_t p = { 0.0, 0.0, 0.0 };
        if (sscanf_s(buffer, "%lf %lf %lf", &p.time, &p.x, &p.y) == 3) {
            if (count >= capacity) {
                printf("Error: Capacidad del array excedida\n");
                free(*points);
                fclose(fp);
                return -1;
            }
            (*points)[count++] = p;
            printf("Leído punto: time=%lf, x=%lf, y=%lf\n", p.time, p.x, p.y); // Mensaje de depuración
        }
        else {
            printf("Formato de línea incorrecto: %s\n", buffer); // Mensaje de depuración
        }
    }

    fclose(fp);
    return count;
}










	//TODO 2. Read the file and save the data in a point_t array
	// Use libcsv: 
	//This sample could be useful https://github.com/rgamble/libcsv/blob/master/csv.pdf
	 //If there is an error reading the file

