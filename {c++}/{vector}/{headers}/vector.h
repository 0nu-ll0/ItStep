#pragma once

#include "../{headers}/coordinate_plane.h"
#include "../{headers}/graphic_window.h"

#include <algorithm>
#include <cmath>
#include <ostream>
#include <string>
#include <vector>

class vector
{
public:
    vector() : x(0), y(0), z(0) { window.close(); }
    vector(int x, int y, int z) : x(x), y(y), z(z) { window.open(); }
    vector(const vector& other) : x(other.x), y(other.y), z(other.z) {}


    bool input();// function to read vector components from user input
    bool output(double X, double Y, double Z); // function to display vector components

    double get_x() const { return x; } // getter for x component
    double get_y() const { return y; } // getter for y component
    double get_z() const { return z; } // getter for z component
    Window& get_window() { return window; } // getter to get field graphic window object
    CoordinatePlane& get_plane() { return plane; } // getter to get field console window object

    void set_x(double& x) { this->x = x; }
    void set_y(double& y) { this->y = y; }
    void set_z(double& z) { this->z = z; }
    CoordinatePlane& set_plane() { return plane; }

    double module() const; //function for finding the length of a vector
    double scalar_product(const vector& vector_second) const; // function scalar product
    bool collinearity(const vector& vector_second) const; // function collinearity vector
    bool orthogonality(const vector& vector_second) const; //function orthogonality vector
    vector normalize() const; // function to normalize the vector

    vector operator+(const vector& vector_second) const; // overload + operator for vector addition
    vector operator-(const vector& vector_second) const; // overload - operator for vector subtraction
    vector operator*(const double value) const; // overload * operator for scalar multiplication
    vector operator*(const vector& vector_second) const; // overload * operator for dot product

    vector operator++(int);
    vector& operator++();
    vector operator--(int);
    vector& operator--();

    vector& operator=(const vector& vector_second);

    bool operator==(const vector& vector_second) const; // overload == operator for vector comparison
    bool operator!=(const vector& vector_second) const; // overload operator for vector comparison
    // overload input/output stream
    friend std::ostream& operator<<(std::ostream& output_stream, vector& _vector);
    friend std::istream& operator>>(std::istream& input_stream, vector& _vector);
    // function output menu
    void menu(std::vector<std::string> menu_items);
private:
    double x;
    double y;
    double z;

    CoordinatePlane plane;
    Window window;
};

