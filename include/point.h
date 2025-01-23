#pragma once
typedef struct point_t {
	double x;
	double y;
	double time;
} point_t;

void freePoints(point_t** points);