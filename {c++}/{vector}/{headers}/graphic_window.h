#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

class Window
{
	public:
		//constructors
		Window() : width(sf::VideoMode::getDesktopMode().width), height(sf::VideoMode::getDesktopMode().height) { window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), "coordinate plane"); }
		// function drawing cells in window
		void drawing_cells();
		// function drawing rectangular coordinate system in space
		void drawing_rectangular_coordinate_system_in_space();
		// function drawing hathes
		void drawing_hatches();
		// function drawing point
		void drawing_points(double X, double Y, double Z);
		// dunction drawing dot lines
		void drawing_dot_lines(double X, double Y, double Z);
		// function drawing vector
		void drawing_vector(double X, double Y, double Z);
		// function construction of a rectangular parallelepiped
		void drawing_rectangular_parallelepiped(double X, double Y, double Z);
		// function drawing window
		void display(double X, double Y, double Z);
		// close window
		void close() { window->close(); }
		//
		void open() { window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), "coordinate plane"); }
	private:
		unsigned int width;
		unsigned int height;

		std::unique_ptr<sf::RenderWindow> window;
};



