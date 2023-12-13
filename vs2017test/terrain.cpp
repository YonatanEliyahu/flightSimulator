#include "terrain.h"

double ground[GSZ][GSZ];
double waves[GSZ][GSZ] = { 0 };
double tmp[GSZ][GSZ];

void SetColor(double h)
{
	double r, g, b;
	// Determine the color based on the height value
	if (fabs(h) < 0.2) // sand
	{
		r = 0.9;
		g = 0.8;
		b = 0.7;
	}
	else if (fabs(h) < 4) // grass
	{
		r = fabs(h) / 10;
		g = 0.3 + fabs(h) / 7;
		b = 0;
	}
	else if (fabs(h) < 7) // stones
	{
		r = fabs(h) / 10;
		g = fabs(h) / 12;
		b = fabs(h) / 15;
	}
	else // snow
	{
		r = fabs(h) / 10;
		g = fabs(h) / 10;
		b = fabs(h) / 9;
	}
	// Set the OpenGL color based on the determined RGB values
	glColor3d(r, g, b);
}


void DrawFloor()
{
	int i, j;
	glColor3d(0, 0, 0);

	// Draw the terrain polygons with colors determined by SetColor
	// sets height by green channel:   ground[i][j][1]
	for (i = 1; i < GSZ; i++)
		for (j = 1; j < GSZ; j++)
		{
			glBegin(GL_POLYGON);
			// Set color and vertices for the polygon
			SetColor(ground[i][j]);
			glVertex3d(j - GSZ / 2, ground[i][j], i - GSZ / 2);
			SetColor(ground[i][j - 1]);
			glVertex3d(j - 1 - GSZ / 2, ground[i][j - 1], i - GSZ / 2);
			SetColor(ground[i - 1][j - 1]);
			glVertex3d(j - 1 - GSZ / 2, ground[i - 1][j - 1], i - 1 - GSZ / 2);
			SetColor(ground[i - 1][j]);
			glVertex3d(j - GSZ / 2, ground[i - 1][j], i - 1 - GSZ / 2);
			glEnd();
		}
	glLineWidth(1);


	// Draw transparent water using blending for a realistic effect
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(0, 0.2, 0.6, 0.8); // the 4-th parameter is opacity
	for (i = 1; i < GSZ; i++)
		for (j = 1; j < GSZ; j++)
		{
			glBegin(GL_POLYGON);
			// Draw transparent water polygons
			glVertex3d(j - GSZ / 2, waves[i][j], i - GSZ / 2);
			glVertex3d(j - 1 - GSZ / 2, waves[i][j - 1], i - GSZ / 2);
			glVertex3d(j - 1 - GSZ / 2, waves[i - 1][j - 1], i - 1 - GSZ / 2);
			glVertex3d(j - GSZ / 2, waves[i - 1][j], i - 1 - GSZ / 2);
			glEnd();
		}

	glDisable(GL_BLEND);

}

void Smooth()
{
	int i, j;
	// Apply a smoothing filter to the terrain
	for (i = 1; i < GSZ - 1; i++)
		for (j = 1; j < GSZ - 1; j++)
		{
			// Use a 3x3 mask for smoothing
			tmp[i][j] = (ground[i - 1][j - 1] + 2 * ground[i - 1][j] + ground[i - 1][j + 1] +
				2 * ground[i][j - 1] + 4 * ground[i][j] + 2 * ground[i][j + 1] +
				ground[i + 1][j - 1] + 2 * ground[i + 1][j] + ground[i + 1][j + 1]) / 16.0;
		}

	for (i = 1; i < GSZ - 1; i++)
		for (j = 1; j < GSZ - 1; j++)
			ground[i][j] = tmp[i][j];
}

void 	UpdateTerrain()
{
	int x1, y1, x2, y2;
	double a, b;
	int i, j;
	double delta = 0.1;

	// Randomly select two points to modify a region of the terrain
	if (rand() % 2 == 0)
		delta = -delta;

	x1 = rand() % GSZ;
	y1 = rand() % GSZ;
	x2 = rand() % GSZ;
	y2 = rand() % GSZ;

	// Adjust terrain based on a linear function determined by two random points
	if (x1 != x2)
	{
		a = (y2 - y1) / double(x2 - x1);
		b = y1 - a * x1;
		for (i = 0; i < GSZ; i++)
			for (j = 0; j < GSZ; j++)
				if (i < a * j + b) // y = ax+b
					ground[i][j] += delta;
				else
					ground[i][j] -= delta;

	}

}