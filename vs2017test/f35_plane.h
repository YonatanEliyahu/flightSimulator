#pragma once
#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include "glut.h"
#include "shapes.h"
#include "vector3D.h"

// External declaration of a global unordered_map to keep track of speeds to be dropped, defined and used in the main.cpp
extern std::unordered_map<std::string, bool> speedToDrop;

// Constants
int const MAX_PLANE_ANGLE = 45;
double const PLANE_MIN_SPEED = 0.1;
double const ANGULAR_ACC = 0.001;
double const REGULAR_ACC = 0.15;

// Function to apply rotation to the plane 3D object
void PlaneRotation(const Plane p);

// Plane class definition
class Plane {
private:
	Vector3D <double> pos;           // Position of the plane
	Vector3D <double> dir;           // Direction of the plane
	double Fspeed, angular_speed;    // Forward speed and angular speed
	double sight_angle;               // Sight angle of the plane

public:
	// Constructor initializes the plane's default values
	Plane() :pos(0, 20, 0), Fspeed(PLANE_MIN_SPEED), angular_speed(0), sight_angle(M_PI / 2),
		dir(sin(sight_angle), sin(0), cos(sight_angle))
	{
	}

	// Getter for pos and dir
	Vector3D <double> getPos() const { return pos; }
	Vector3D <double> getDir() const { return dir; }

	// Getter and setter for pos.X
	double getPosX() const { return pos.x; }
	void setPosX(double x) { pos.x = x; }
	void movePosX() { pos.x += Fspeed * dir.x; }

	// Getter and setter for pos.Y
	double getPosY() const { return pos.y; }
	void setPosY(double y) { pos.y = y; }
	void movePosY() { pos.y += Fspeed * dir.y; }

	// Getter and setter for pos.Z
	double getPosZ() const { return pos.z; }
	void setPosZ(double z) { pos.z = z; }
	void movePosZ() { pos.z += Fspeed * dir.z; }

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

	// Getter and setter for Fspeed
	double getFSpeed() const { return Fspeed; }
	void setFSpeed(double speed) { Fspeed = speed; }
	void accelerateFSpeed(int dir = 1, double acceleration = REGULAR_ACC) { Fspeed += dir * acceleration; }

	// Getter and setter for angular_speed
	double getAngularSpeed() const { return angular_speed; }
	void setAngularSpeed(double as) { angular_speed = as; }
	void accelerateAngularSpeed(int dir = 1, double acceleration = ANGULAR_ACC) { angular_speed += dir * acceleration; }

	// Functions to update plane statistics
	void updateStats();
	void dropSpeeds();

};

