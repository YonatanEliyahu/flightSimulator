#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <unordered_map>
#include "glut.h"
#include "terrain.h"
#include "shapes.h"
#include "f35_plane.h"
#include "portViews.h"
#include "pov.h"

using namespace std;

unordered_map<char, bool> keyState; //will help us keep track of the pressed keys that effect the plane
unordered_map<string, bool> speedToDrop; // will help us keep track of the speeds that should be dropped to 0 after key up event 

extern Plane plane;
extern Pov pov;
extern const int WIDTH;
extern const int HEIGHT;

// Initialize OpenGL settings and resources
// This function is called once at the beginning of the program.
// It is used to set up OpenGL configurations, such as enabling features,
// defining perspective, and initializing any necessary resources.
void init()
{
	// Initialize key states and speed drop flags
	keyState['a'] = false;
	keyState['d'] = false;
	keyState['s'] = false;
	keyState['w'] = false;
	speedToDrop["regular"] = false;
	speedToDrop["angular"] = false;

	// Set the window background color to sky-blue
	glClearColor(0.3, 0.6, 0.8, 0);

	// Seed the random number generator
	srand(time(0));

	// Enable Z-buffer for depth testing
	glEnable(GL_DEPTH_TEST);

	// Generate the world map by updating the terrain 2500 times
	// The first 1750 updates introduce variation, and the next 750 updates smooth the terrain
	for (int counter = 0; counter < 1750; ++counter)
		UpdateTerrain();

	// Smooth the terrain to create a more realistic landscape
	Smooth();

	// Further refine the terrain with 750 additional updates
	for (int counter = 0; counter < 750; ++counter)
		UpdateTerrain();
}

// Perform continuous rendering or animation updates
// This function is called continuously during the program's execution.
// It is often used to update the scene, handle animations, or perform
// any other tasks that require continuous processing.
// In an OpenGL application, it is common to trigger redrawing of the scene here.
void idle()
{
	// Update aircraft motion and drop speeds
	plane.updateStats(); //Plane function that handle the movement of the plane
	plane.dropSpeeds();	 //Plane function that drops his speeds when the related keys are released. 

	pov.updatePovEye(plane.getPos()); // Update camera POV based on the plane's position

	// Request redisplay to refresh the window
	glutPostRedisplay();
}


void keyboard(unsigned char key, int  x, int y)
{
	// Set key states for pressed keys
	if (key == 'a' || key == 's' || key == 'd' || key == 'w')
		keyState[key] = true;

	// Get current speeds of the plane
	double Fspeed = plane.getFSpeed();
	double Aspeed = plane.getAngularSpeed();

	// Handle key presses for aircraft motion
	// The "(speed < 0) ? ANGULAR_ACC * 2 : ANGULAR_ACC" checks if the aircraft move in the opposite direction
	// and if so it will accelerate faster to the requested side
	// otherwise it will accelerate by it's default acc const
	switch (key)
	{
	case 'a':
		plane.accelerateAngularSpeed(1, (Aspeed < 0) ? ANGULAR_ACC * 2 : ANGULAR_ACC);
		speedToDrop["angular"] = false;
		break;
	case 'w':
		plane.accelerateFSpeed(1, (Fspeed < 0) ? REGULAR_ACC * 2 : REGULAR_ACC);
		speedToDrop["regular"] = false;
		break;
	case 's':
		plane.accelerateFSpeed(-1, (Fspeed < 0) ? REGULAR_ACC * 2 : REGULAR_ACC);
		speedToDrop["regular"] = false;
		break;
	case 'd':
		plane.accelerateAngularSpeed(-1, (Aspeed > 0) ? ANGULAR_ACC * 2 : ANGULAR_ACC);
		speedToDrop["angular"] = false;
		break;
	}
}

void keyReleased(unsigned char key, int x, int y)
{
	// Reset key states for released keys
	if (key != 'a' && key != 's' && key != 'd' && key != 'w') //if key no in {"asdw"} the function will return
		return;
	keyState[key] = false;

	// Set speed drop flags based on released keys
	switch (key)
	{
	case 'a':
	case 'd':
		speedToDrop["angular"] = true;
		break;
	case 'w':
	case 's':
		speedToDrop["regular"] = true;
		break;
	}
}

void menu(int choice)
{
	// Switch display function based on the chosen menu option
	switch (choice)
	{
	case 1: // regular view
		glutDisplayFunc(display);
		break;
	case 2: // top view
		glutDisplayFunc(topdisplay);
		break;
	case 3: // cockpit view
		glutDisplayFunc(cockpitdisplay);
		break;
	case 4: //combined view
		glutDisplayFunc(combineddisplay);
		break;
	}
}

void main(int argc, char* argv[])
{
	// Initialize GLUT and create a window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // GLUT_DEPTH is Z-buffer
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(500, 100);
	glutCreateWindow("3D");

	// Set display and idle functions
	glutDisplayFunc(display); // display is a name of refresh function
	glutIdleFunc(idle);// idle is a function that runs in background

	// Set keyboard functions for regular keys
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyReleased);

	// Create a menu for different views
	glutCreateMenu(menu);
	glutAddMenuEntry("Regular View", 1);
	glutAddMenuEntry("Top View", 2);
	glutAddMenuEntry("Cockpit View", 3);
	glutAddMenuEntry("Combined View", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// Perform initialization
	init();

	// Enter the GLUT main loop
	glutMainLoop();
}