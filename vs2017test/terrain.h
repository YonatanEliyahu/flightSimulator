#pragma once
#include "glut.h"
#include <math.h>
#include <stdio.h>
#include <time.h>

// Constant representing the size of the grid for terrain generation
const int GSZ = 300;

// Updates the terrain by modifying the height values in the grid
// This function is responsible for creating the landscape.
void UpdateTerrain();

// Applies a smoothing algorithm to the terrain grid to create a more realistic appearance
// Smoothing helps to remove sharp edges and irregularities from the terrain.
void Smooth();

// Draws the terrain as a floor with varying colors based on the height values
// This function is responsible for rendering the terrain on the screen.
void DrawFloor();

// Sets the color of the terrain based on the given height value
// The color is determined to create a visual representation of the terrain's elevation.
void SetColor(double h);
