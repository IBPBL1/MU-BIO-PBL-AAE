#include "point.h"
//#define NULL 0
#include <stdlib.h>
void freePoints(point_t** points) {
    if (points != NULL && *points != NULL) {
        free(*points);
        *points = NULL;
    }
}