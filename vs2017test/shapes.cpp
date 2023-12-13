#include "shapes.h"


void DrawCilynder(int n, double topr, double bottomr)
{
	// Draws a cylinder with specified parameters
	// Parameters:
	//   - n: Number of vertices in the cross-section
	//   - topr: Top radius of the cylinder
	//   - bottomr: Bottom radius of the cylinder
	double alpha, teta = 2 * M_PI / n;

	for (alpha = 0; alpha < 2 * M_PI; alpha += teta)
	{
		glColor3d(fabs(sin(alpha)), fabs(sin(alpha)), fabs(sin(alpha)));
		glBegin(GL_POLYGON);
		glVertex3d(topr * sin(alpha), 1, topr * cos(alpha)); // 1
		glVertex3d(topr * sin(alpha + teta), 1, topr * cos(alpha + teta)); // 2 
		glVertex3d(bottomr * sin(alpha + teta), 0, bottomr * cos(alpha + teta)); // 3 
		glVertex3d(bottomr * sin(alpha), 0, bottomr * cos(alpha)); // 4
		glEnd();
	}

}

void DrawSphere(int n, int slices)
{
	// Draws a sphere with specified parameters
	// Parameters:
	//   - n: Number of vertices in the cross-section of each cylindrical section
	//   - slices: Number of cylindrical sections in the sphere
	double beta, delta = M_PI / slices;
	double topr, bottomr;
	for (beta = -M_PI / 2; beta <= M_PI / 2; beta += delta)
	{
		topr = cos(beta + delta);
		bottomr = cos(beta);
		glPushMatrix();
		glTranslated(0, sin(beta), 0);
		glScaled(1, sin(beta + delta) - sin(beta), 1);
		DrawCilynder(n, topr, bottomr);
		glPopMatrix();
	}
}

// Draws an airplane consisting of a nose, body, cockpit, tail, wings, and vertical wings
void DrawAirplane()
{
	glPushMatrix();
	glRotated(-90, 0, 0, 1);
	// nose
	glPushMatrix();
	glTranslated(0, 5, 0);
	glScaled(1, 5, 1);
	DrawCilynder(50, 0, 1);
	glPopMatrix();
	// body
	glPushMatrix();
	glScaled(1, 5, 1);
	DrawCilynder(150, 1, 1.3);
	glPopMatrix();

	// cockpit
	glPushMatrix();
	glTranslated(-0.25, 3, 0);
	glScaled(1, 4, 1);
	glRotated(90, 0, 1, 0);
	DrawSphere(150, 100);
	glPopMatrix();

	// tail
	glPushMatrix();
	glTranslated(0, -10, 0);
	glScaled(1, 10, 1);
	DrawCilynder(150, 1.3, 0.8);
	glPopMatrix();

	// Wings
	//left (z-axis)
	glColor3d(0, 0.25, 0.25);
	glBegin(GL_POLYGON);
	glColor3d(0, 0.25, 0.25);
	glVertex3d(0, 2, 0);
	glVertex3d(0, -4, 6);
	glColor3d(0.7, 0.7, 0.7);
	glVertex3d(0, -6, 6);
	glVertex3d(0, -5, 0);
	glEnd();
	//right (z-axis)
	glColor3d(0, 0.25, 0.25);
	glBegin(GL_POLYGON);
	glColor3d(0, 0.25, 0.25);
	glVertex3d(0, 2, 0);
	glVertex3d(0, -4, -6);
	glColor3d(0.7, 0.7, 0.7);
	glVertex3d(0, -6, -6);
	glVertex3d(0, -5, 0);
	glEnd();

	// rear wings
	//left (z-axis)
	glColor3d(0, 0.25, 0.25);
	glBegin(GL_POLYGON);
	glColor3d(0, 0.25, 0.25);
	glVertex3d(0, -6, 0);
	glVertex3d(0, -9, 3);
	glColor3d(0.7, 0.7, 0.7);
	glVertex3d(0, -10, 3);
	glVertex3d(0, -11, 0);
	glEnd();
	//right (z-axis)
	glColor3d(0, 0.25, 0.25);
	glBegin(GL_POLYGON);
	glColor3d(0, 0.25, 0.25);
	glVertex3d(0, -6, 0);
	glVertex3d(0, -9, -3);
	glColor3d(0.7, 0.7, 0.7);
	glVertex3d(0, -10, -3);
	glVertex3d(0, -11, 0);
	glEnd();

	// vertical wings

	glColor3d(0, 0.25, 0.25);
	glBegin(GL_POLYGON);
	glColor3d(0, 0.25, 0.25);
	glVertex3d(0, -7, 1);
	glVertex3d(-3, -9, 2);
	glColor3d(0.7, 0.7, 0.7);
	glVertex3d(-3, -10, 2);
	glVertex3d(0, -11, 1);
	glEnd();
	glColor3d(0, 0.25, 0.25);
	glBegin(GL_POLYGON);
	glColor3d(0, 0.25, 0.25);
	glVertex3d(0, -7, -1);
	glVertex3d(-3, -9, -2);
	glColor3d(0.7, 0.7, 0.7);
	glVertex3d(-3, -10, -2);
	glVertex3d(0, -11, -1);
	glEnd();


	glPopMatrix();
}


