#include "portViews.h"


Pov pov = Pov();

void display() // regular view
{    
	// Enable depth testing
	glEnable(GL_DEPTH_TEST); 

	// Clears the frame buffer and z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Sets up the projection matrix
	glViewport(0, 0, WIDTH, HEIGHT); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	glFrustum(-1, 1, -1, 1, 0.7, 350);

	// Sets up the view matrix based on camera position and direction
	gluLookAt(pov.getEyeX(), pov.getEyeY(), pov.getEyeZ(),
		pov.getEyeX() + pov.getDirX(), pov.getEyeY() - 1, pov.getEyeZ() + pov.getDirZ(),  // this is the direction
		0, 1, 0);

	// Switches to the modelview matrix and draws the floor and airplane
	glMatrixMode(GL_MODELVIEW);
	DrawFloor();
	glPushMatrix();
	PlaneRotation(plane);
	DrawAirplane();
	glPopMatrix();

	// Disable depth testing when not needed
	glDisable(GL_DEPTH_TEST); 

	// Swaps the front and back buffers
	glutSwapBuffers(); 
}

void topdisplay()
{
	// Enable depth testing
	glEnable(GL_DEPTH_TEST);

	// Clears the frame buffer and z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clean frame buffer and z-buffer

	// Sets up the projection matrix
	glViewport(0, 0, WIDTH, HEIGHT); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	glFrustum(-1, 1, -1, 1, 0.7, 350);

	// Sets up the view matrix for the top view
	gluLookAt(pov.getEyeX(), pov.getEyeY()+50, pov.getEyeZ(),
		pov.getEyeX() + pov.getDirX(), pov.getEyeY() - 1, pov.getEyeZ() + pov.getDirZ(),  // this is the direction
		0, 1, 0);

	// Switches to the modelview matrix and draws the floor and airplane
	glMatrixMode(GL_MODELVIEW);
	DrawFloor();
	glPushMatrix();
	PlaneRotation(plane);
	DrawAirplane();
	glPopMatrix();

	// Disable depth testing when not needed
	glDisable(GL_DEPTH_TEST);

	// Swaps the front and back buffers
	glutSwapBuffers();
}

void cockpitdisplay()
{
	// Enable depth testing
	glEnable(GL_DEPTH_TEST);

	// Clears the frame buffer and z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

	// Sets up the projection matrix
	glViewport(0, 0, WIDTH, HEIGHT); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 0.7, 350);


	// Sets up the view matrix based on the plane's position and direction
	gluLookAt(plane.getPosX(), plane.getPosY() + 4, plane.getPosZ(),
		plane.getPosX() + plane.getDirX(), plane.getPosY() + 3, plane.getPosZ() + plane.getDirZ(),  // this is the direction
		0, 1, 0);

	// Switches to the modelview matrix and draws the floor and airplane
	glMatrixMode(GL_MODELVIEW);
	DrawFloor();
	glPushMatrix();
	PlaneRotation(plane);
	DrawAirplane();
	glPopMatrix();

	// Disable depth testing when not needed
	glDisable(GL_DEPTH_TEST);

	// Swaps the front and back buffers
	glutSwapBuffers();
}

void combineddisplay()
{
	// Enable depth testing
	glEnable(GL_DEPTH_TEST);

	// Clears the frame buffer and z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	// regular view
	glViewport(0, HEIGHT / 2, WIDTH / 2, HEIGHT / 2); //top left corner
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 0.7, 350);

	gluLookAt(pov.getEyeX(), pov.getEyeY(), pov.getEyeZ(),
		pov.getEyeX() + pov.getDirX(), pov.getEyeY() - 1, pov.getEyeZ() + pov.getDirZ(),  // this is the direction
		0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	DrawFloor();
	glPushMatrix();
	PlaneRotation(plane);
	DrawAirplane();
	glPopMatrix();

	// top view
	glViewport(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2); // top right corner
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 0.7, 350);
	gluLookAt(pov.getEyeX(), pov.getEyeY()+50, pov.getEyeZ(),
		pov.getEyeX() + pov.getDirX(), pov.getEyeY() - 1, pov.getEyeZ() + pov.getDirZ(),  // this is the direction
		0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	DrawFloor();
	glPushMatrix();
	PlaneRotation(plane);
	DrawAirplane();
	glPopMatrix();

	// cockpit view
	glViewport(0, 0, WIDTH, HEIGHT / 2); // bottom
	glMatrixMode(GL_PROJECTION); 

	glLoadIdentity(); 
	glFrustum(-1, 1, -1, 1, 0.7, 350);
	gluLookAt(plane.getPosX(), plane.getPosY() + 4, plane.getPosZ(),
		plane.getPosX() + plane.getDirX(), plane.getPosY() + 3, plane.getPosZ() + plane.getDirZ(),  // this is the direction
		0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	DrawFloor();
	glPushMatrix();
	PlaneRotation(plane);
	DrawAirplane();
	glPopMatrix();

	// Disable depth testing when not needed
	glDisable(GL_DEPTH_TEST);

	// Swaps the front and back buffers
	glutSwapBuffers();
}