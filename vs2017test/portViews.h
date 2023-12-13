#pragma once
#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "glut.h"
#include "f35_plane.h"
#include "shapes.h"
#include "terrain.h"
#include "pov.h"

//f35_plane global vars
extern Plane plane;

// Constant representing the size of the display window
const int WIDTH = 800;
const int HEIGHT = 800;

// Displays the scene in regular view
void display();

// Displays the scene from a top view
void topdisplay();

// Displays the scene from a cockpit view
void cockpitdisplay();

// Displays the scene in a combined view, showing regular, top, and cockpit views simultaneously
void combineddisplay();