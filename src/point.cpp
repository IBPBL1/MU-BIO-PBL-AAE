#include "point.h"
//#define NULL 0
#include <stdlib.h>
void freePoints(point_t** points) {

	if (points != NULL) {
		free(points); 
		points = NULL;
	}
	//TODO 2. Free the memory allocated for the point_t array
}