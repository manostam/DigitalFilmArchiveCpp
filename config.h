#pragma once
#include <random>
#include "graphics.h"

#define ASSET_PATH "assets\\"

#define WINDOW_WIDTH 1280   // 16:9 resolutions
#define WINDOW_HEIGHT 720
#define CANVAS_WIDTH 854
#define CANVAS_HEIGHT 480
#define YEAR_MIN 1980
#define YEAR_MAX 2023

// to delete ?
// instead of br.fill_color[0] = 1.0f ..., we can macro-do SETCOLOR(br.fill_color, 1.0f, 0.8f, 0.4f);
#define SETCOLOR(c, r, g, b) {c[0] = r; c[1] = g; c[2] = b;}

// to delete  ?
// random float number between 0 and 1, used as percentage of another number, quantity etc
#define RAND0TO1() (rand()/(float)RAND_MAX) 

// returns distance between two points as a float
inline float distance(float x1, float y1, float x2, float y2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}



