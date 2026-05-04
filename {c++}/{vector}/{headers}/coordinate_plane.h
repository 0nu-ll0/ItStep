#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class CoordinatePlane
{
    public:
        // constructors
        CoordinatePlane() : height(0), width(0) { field.resize(height); }
        CoordinatePlane(unsigned int Height, unsigned int Width) : height(Height), width(Width), field(Height, std::vector<unsigned char>(Width, ' ')) {}
        CoordinatePlane(const CoordinatePlane& plane) : height(plane.height), width(plane.width), field(plane.field) {}
        // getter
        const unsigned int get_height() const { return height; }
        const unsigned int get_width() const { return width; }
        // setter
        void set_height(const unsigned int& _height) { height = _height; }
        void set_width(const unsigned int& _width) { width = _width; }
        // methods
        void filling(const int& height, const int& width, const int& z);
        void drawing_point(double X, double Y, double Z);
        void output() const;
    private:
        unsigned int width;
        unsigned int height;

        std::vector<std::vector<unsigned char>> field;
};