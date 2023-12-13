#include "f35_plane.h"

// Create an instance of the Plane class
Plane plane = Plane();

// OpenGL transformation to rotate the plane based on its state
void PlaneRotation(const Plane p)
{
	// Translate to the plane's position
	glTranslated(p.getPosX(), p.getPosY(), p.getPosZ());
	// Rotate around the Y-axis based on the plane's sight angle
	double planeYRotation = p.getSightAngle() * 180 / M_PI - 90;
	glRotated(planeYRotation, 0, 1, 0);

	// Rotate around the X-axis based on the plane's angular speed
	//This makes use of std::clamp to ensure that planeXRotation is clamped within the specified range (-MAX_PLANE_ANGLE to MAX_PLANE_ANGLE).
	//If the value falls outside the specified range, it will be set to the nearest bound.
	double planeXRotation = std::clamp(p.getAngularSpeed() * 5000, (double)-MAX_PLANE_ANGLE, (double)MAX_PLANE_ANGLE);
	glRotated(planeXRotation, -1, 0, 0);

}

// Update the plane's stats, including position and direction
void Plane::updateStats()
{
	sight_angle += angular_speed;

	// Update the direction based on the new sight angle
	dir.x = sin(sight_angle);
	//dir.y = sin(0);
	dir.z = cos(sight_angle);

	// Move the plane's position based on its direction and forward speed
	movePosX();
	movePosY();
	movePosZ();
}

// Gradually drop the plane's speeds based on user input
void Plane::dropSpeeds()
{
	for (auto& pair : speedToDrop)
	{
		if (!pair.second)
			continue;
		// Drop the regular speed gradually to PLANE_MIN_SPEED
		if (pair.first == "regular") {
			if (Fspeed == PLANE_MIN_SPEED || fabs(Fspeed) < REGULAR_ACC) {
				Fspeed = PLANE_MIN_SPEED;
				pair.second = false;
				continue;
			}
			this->accelerateFSpeed((Fspeed > 0 ? -1 : 1), fabs(Fspeed)/100); 
		}

		// Drop the angular speed gradually to zero
		if (pair.first == "angular") {
			if (angular_speed == 0 || fabs(angular_speed) < ANGULAR_ACC) {
				angular_speed = 0;
				pair.second = false;
				continue;
			}
			this->accelerateAngularSpeed((angular_speed > 0 ? -1 : 1), fabs(angular_speed)/10);
		}
	}
}
