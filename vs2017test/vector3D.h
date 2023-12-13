#pragma once

// Template class representing a 3D vector
template <typename T>
class Vector3D {
private:
	T x, y, z;

public:
    // Constructor that initializes the vector with given coordinates
	Vector3D(T x, T y, T z) :x(x), y(y), z(z) {}
    // Getter functions for x, y, and z
    T getX() const { return x; }
    T getY() const { return y; }
    T getZ() const { return z; }

    // Setter functions for x, y, and z
    void setX(T newX) { x = newX; }
    void setY(T newY) { y = newY; }
    void setZ(T newZ) { z = newZ; }

    // Allowing Plane and Pov classes to access private members directly
    friend class Plane;
    friend class Pov;
};