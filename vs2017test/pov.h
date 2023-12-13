#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "vector3D.h"
#include "f35_plane.h"

// Pov class represents a point of view (camera) in a 3D environment
class Pov {
private:
	Vector3D <double> eye; // Position of the camera
	Vector3D <double> dir; // Direction the camera is facing
	double sight_angle;	   // Field of view angle
public:
	// Constructor initializes the camera with default values
	Pov() :sight_angle(M_PI), eye(2, 20, 12), dir(sin(M_PI), 0, cos(M_PI)) {}

	// Getter and setter for eye.X
	double getEyeX() const { return eye.x; }
	void setEyeX(double eyex) { eye.x = eyex; }

	// Getter and setter for eye.y
	double getEyeY() const { return eye.y; }
	void setEyeY(double eyey) { eye.y = eyey; }

	// Getter and setter for eye.z
	double getEyeZ() const { return eye.z; }
	void setEyeZ(double eyez) { eye.z = eyez; }

	// Getter and setter for dir.X
	double getDirX() const { return dir.x; }
	void setDirX(double dirx) { dir.x = dirx; }

	// Getter and setter for dir.Y
	double getDirY() const { return dir.y; }
	void setDirY(double diry) { dir.y = diry; }

	// Getter and setter for dir.Z
	double getDirZ() const { return dir.z; }
	void setDirZ(double dirz) { dir.z = dirz; }

	// Getter and setter for sight_angle
	double getSightAngle() const { return sight_angle; }
	void setSightAngle(double sa) { sight_angle = sa; }

	// Updates the camera position based on the given plane position
	void updatePovEye(const Vector3D<double> planePos)
	{
		eye.x = planePos.x;
		eye.y = planePos.y + 15;
		eye.z = planePos.z + 10;
	}

};
