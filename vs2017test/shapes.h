#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "glut.h"


// Draws a cylinder with specified parameters
void DrawCilynder(int n, double topr, double bottomr);

// Draws a sphere with specified parameters
void DrawSphere(int n, int slices);

// Draws an airplane model
// This function is responsible for rendering the airplane on the screen.
void DrawAirplane();
