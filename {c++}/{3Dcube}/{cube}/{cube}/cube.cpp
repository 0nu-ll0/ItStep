#include <array> // std::array<>
#include <cmath>
#include <iostream>
#include <string> // std::string
#include <utility> // std::pair<>
#include <vector> // std::vector<>
#include <Windows.h>

constexpr auto counter_points = 8;
constexpr auto counter_columns = 2;
constexpr auto counter_edges = 12;

unsigned int scale = 0;

float screen_position_x = 0.0f;
float screen_position_y = 0.0f;
// struct Point
struct Point
{
	private:
		float x = 0;
		float y = 0;
		float z = 0;
	public:
		// constructor without parameters
		Point() : x(0), y(0), z(0) {}
		// constructor with parameters
		Point(const int X, const int Y, const int Z) : x(X), y(Y), z(Z) {}
		// getters
		const float get_x() const { return x; }
		const float get_y() const { return y; }
		const float get_z() const { return z; }
		// setters
		void set_x(const float x = 0) { this->x = x; }
		void set_y(const float y = 0) { this->y = y; }
		void set_z(const float z = 0) { this->z = z; }
};
// struct vector
struct Vector
{
	private:
		float x = 0;
		float y = 0;
		float z = 0;
	public:
		// constructor without parameters
		Vector() : x(0), y(0), z(0) {}
		// constructor with parameters
		Vector(const int X, const int Y, const int Z) : x(X), y(Y), z(Z) {}
		// getters
		const float get_x() const { return x; }
		const float get_y() const { return y; }
		const float get_z() const { return z; }
		// setters
		void set_x(const float x = 0) { this->x = x; }
		void set_y(const float y = 0) { this->y = y; }
		void set_z(const float z = 0) { this->z = z; }
};
// function output cube
void output(const std::vector<std::vector<char>>& cube)
{
	std::cout << "\033[H";

	std::string frame = "";

	for (size_t i = 0; i < cube.size(); ++i)
	{
		for (size_t j = 0; j < cube[i].size(); ++j)
			frame += cube[i][j];
		frame += '\n';
	}
	std::cout << frame << std::flush;
}
// function set value all points
void setting_value_points(std::array<Point, counter_points>& points)
{
	{
		points[0].set_x(-1);
		points[0].set_y(-1);
		points[0].set_z(-1);

		points[1].set_x(1);
		points[1].set_y(-1);
		points[1].set_z(-1);

		points[2].set_x(1);
		points[2].set_y(1);
		points[2].set_z(-1);

		points[3].set_x(-1);
		points[3].set_y(1);
		points[3].set_z(-1);

		points[4].set_x(-1);
		points[4].set_y(-1);
		points[4].set_z(1);

		points[5].set_x(1);
		points[5].set_y(-1);
		points[5].set_z(1);

		points[6].set_x(1);
		points[6].set_y(1);
		points[6].set_z(1);

		points[7].set_x(-1);
		points[7].set_y(1);
		points[7].set_z(1);
	}
}
// function hide console cursor
void hide_cursor()
{
	HANDLE handle_console = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursor_visible;

	GetConsoleCursorInfo(handle_console, &cursor_visible);
	cursor_visible.bVisible = FALSE;
	SetConsoleCursorInfo(handle_console, &cursor_visible);
}
// function getting the console window size
const std::pair<const unsigned int, const unsigned int> console_size()
{
	HANDLE handle_console = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO buffer_console;

	int width = 0;
	int height = 0;

	if (GetConsoleScreenBufferInfo(handle_console, &buffer_console))
	{
		width = buffer_console.srWindow.Right - buffer_console.srWindow.Left + 1;
		height = buffer_console.srWindow.Bottom - buffer_console.srWindow.Top + 1;
	}

	return std::pair<const unsigned int, const unsigned int>(width, height);
}
// function calculation of vertex coordinates
std::array<std::array<float, counter_columns>, counter_points> calculation_vertex_coordinates(const std::array<Point, counter_points>& points)
{
	std::array<std::array<float, counter_columns>, counter_points> coordinates_vertex;

	const unsigned int width = console_size().first;
	const unsigned int height = console_size().second;

	const unsigned int counter_iteration = 8;

	float X = 0;
	float Y = 0;

	float x = 0.0f;
	float y = 0.0f;

	float coefficient = 0.5f;
	float factor = 2.0f;

	for (size_t i = 0; i < counter_iteration; ++i)
	{
		x = (points[i].get_x() * scale) + (points[i].get_z() * scale * coefficient) + screen_position_x;
		y = screen_position_y - (points[i].get_y() * scale) - (points[i].get_z() * scale * coefficient);
		y /= factor;

		X = x;
		Y = y;

		coordinates_vertex[i][0] = Y;
		coordinates_vertex[i][1] = X;
	}

	return coordinates_vertex;
}
// function calculate visible edges
int calculate_Nz(int index_vertex_first, int index_vertex_second, int index_vertex_third, std::array<std::array<float, counter_columns>, counter_points>& coordinates_vertex)
{
	Vector A, B, C;
	Vector AB, BC;

	int Nz = 0;

	const unsigned int x = 1;
	const unsigned int y = 0;

	A.set_x(coordinates_vertex[index_vertex_first][x]);
	A.set_y(coordinates_vertex[index_vertex_first][y]);

	B.set_x(coordinates_vertex[index_vertex_second][x]);
	B.set_y(coordinates_vertex[index_vertex_second][y]);

	C.set_x(coordinates_vertex[index_vertex_third][x]);
	C.set_y(coordinates_vertex[index_vertex_third][y]);

	AB.set_x(B.get_x() - A.get_x());
	AB.set_y(B.get_y() - A.get_y());

	BC.set_x(C.get_x() - B.get_x());
	BC.set_y(C.get_y() - B.get_y());

	Nz = ((B.get_x() - A.get_x()) * (C.get_y() - B.get_y()) - (B.get_y() - A.get_y()) * (C.get_x() - B.get_x()));

	return Nz;
}
// function set edges coord
std::pair<unsigned int, unsigned int>* setting_coordinates_edges(const std::array<Point, counter_points>& points)
{
	const unsigned int index_x = 1;
	const unsigned int index_y = 0;
	int index = 0;
	int add = 0;

	std::pair<unsigned int, unsigned> coordinates_edges[counter_edges * 2];
	std::array<std::array<float, counter_columns>, counter_points> coordinates_vertex;

	coordinates_vertex = calculation_vertex_coordinates(points);

	for (size_t i = 0; i < counter_edges * 2; ++i)
	{
		if (i < counter_points)
		{
			if (i % 4 != 3)
			{
				coordinates_edges[i].first = coordinates_vertex[i][index_y];
				coordinates_edges[i].second = coordinates_vertex[i][index_x];
			}
			else
			{
				coordinates_edges[i].first = coordinates_vertex[0 + add][index_y];
				coordinates_edges[i].second = coordinates_vertex[0 + add][index_x];
				add += 4;
			}
		}
		else
		{
			coordinates_edges->first = coordinates_vertex[index][index_y];
			coordinates_edges->second = coordinates_vertex[index][index_x];
			index++;
		}
	}

	return coordinates_edges;
}
// function drawing line using Bresenham's algorithm
void draw_line(const int xFirst, const int xSecond, const int yFirst, const int ySecond, const float zFirst, const float zSecond, std::vector<std::vector<char>>& shape, std::vector<std::vector<float>>& buffer_depth)
{
	const unsigned char symbol = '+';

	bool direction = true;

	unsigned int Y = 0;
	unsigned int X = 0;
	
	float Z = 0;
	float ZBuff = 0;

	int error = 0;
	int stepX = 0;
	int stepY = 0;
	
	float stepZ = 0;

	int distance = 0;
	int distanceX = 0;
	int distanceY = 0;

	stepX = ((xFirst - xSecond) < 0) ? 1 : -1;
	stepY = ((yFirst - ySecond) < 0) ? 1 : -1;

	distanceX = abs(xSecond - xFirst);
	distanceY = abs(ySecond - yFirst);

	error = (distanceX > distanceY) ? -distanceX : -distanceY;
	distance = (distanceX > distanceY) ? distanceX : distanceY;
	direction = (distanceX > distanceY) ? true : false;

	stepZ = (zSecond - zFirst) / distance;

	Y = yFirst;
	X = xFirst;

	for (size_t j = 0; j <= distance; ++j)
	{
		// Проверяем, не выходим ли мы за границы вектора
		if (Y >= 0 && Y < shape.size() && X >= 0 && X < shape[0].size())
		{
			Z = zFirst + stepZ * j;
			ZBuff = buffer_depth[Y][X];
			if (Z < ZBuff)
			{
				shape[Y][X] = symbol;
				buffer_depth[Y][X] = Z;
			}
		}
		if (direction == true)
		{
			error += 2 * distanceY;
			if (error >= 0)
			{
				Y += stepY;
				error -= 2 * distanceX;
			}
			X += stepX;
		}
		else
		{
			error += 2 * distanceX;
			if (error >= 0)
			{
				X += stepX;
				error -= 2 * distanceY;
			}
			Y += stepY;
		}
	}
}
// function draw cube
void draw_cube(const std::array<Point, counter_points>& points, std::vector<std::vector<char>>& cube, std::vector<std::vector<float>>& buffer_depth)
{
	const unsigned char symbol = '.';

	const unsigned int rows = 6;
	const unsigned int columns = 4;

	const unsigned int indexX = 1;
	const unsigned int indexY = 0;

	std::array<std::array<int, columns>, rows> edges
	{{
		{0, 1, 2, 3},
		{5, 4, 7, 6},
		{1, 5, 6, 2},
		{4, 0, 3, 7},
		{3, 2, 6, 7},
		{0, 4, 5, 1}
	}};

	std::array<std::array<float, counter_columns>, counter_points> coordinates_vertex = calculation_vertex_coordinates(points);
	
	std::array<Point, columns> vertex;

	Point* pointer_vertex = vertex.data();
	
	float Y = 0;
	float X = 0;
	float Z = 0;

	int Ymax = 0;
	int Ymin = 0;

	int normalize = 0;
	int counter = 0;

	int xFirst = 0;
	int xSecond = 0;

	float zFirst = 0;
	float zSecond = 0;
	float zPixel = 0;
	
	float t = 0;
	float tPixel = 0;

	for (size_t j = 0; j < rows; ++j)
	{
		normalize = calculate_Nz(edges[j][0], edges[j][1], edges[j][2], coordinates_vertex);
		if (normalize < 0)
		{
			vertex[0].set_y(coordinates_vertex[edges[j][0]][indexY]);
			vertex[0].set_x(coordinates_vertex[edges[j][0]][indexX]);
			vertex[0].set_z(points[edges[j][0]].get_z());

			vertex[1].set_y(coordinates_vertex[edges[j][1]][indexY]);
			vertex[1].set_x(coordinates_vertex[edges[j][1]][indexX]);
			vertex[1].set_z(points[edges[j][1]].get_z());
			
			
			vertex[2].set_y(coordinates_vertex[edges[j][2]][indexY]);
			vertex[2].set_x(coordinates_vertex[edges[j][2]][indexX]);
			vertex[2].set_z(points[edges[j][2]].get_z());
			
			
			vertex[3].set_y(coordinates_vertex[edges[j][3]][indexY]);
			vertex[3].set_x(coordinates_vertex[edges[j][3]][indexX]);
			vertex[3].set_z(points[edges[j][3]].get_z());

			Ymax = Ymin = pointer_vertex->get_y();
			for (size_t i = 0; i < columns; ++i)
			{
				if (Ymin > (pointer_vertex + i)->get_y())
					Ymin = (pointer_vertex + i)->get_y();
				if (Ymax < (pointer_vertex + i)->get_y())
					Ymax = (pointer_vertex + i)->get_y();
			}
			for (size_t y = Ymin; y <= Ymax; ++y)
			{
				bool geometric_edge_first = false;
				bool geometric_edge_second = false;
				bool left_flag = false;
				bool right_flag = false;

				float x_one = 0.00f;
				float x_two = 0.00f;

				float z_one = 0.00f;
				float z_two = 0.00f;

				counter = 0;

				for (size_t i = 0; i < columns; ++i)
				{
					if ((vertex[i].get_y() <= y && y < vertex[(i + 1) % columns].get_y()) ||
						(vertex[(i + 1) % columns].get_y() <= y && y < vertex[i].get_y()))
					{
						t = static_cast<float>((y - vertex[i].get_y())) / (vertex[(i + 1) % columns].get_y() - vertex[i].get_y());
						X = vertex[i].get_x() + t * (vertex[(i + 1) % columns].get_x() - vertex[i].get_x());
						Z = vertex[i].get_z() + t * (vertex[(i + 1) % columns].get_z() - vertex[i].get_z());

						if (counter == 0)
						{
							x_one = X;
							z_one = static_cast<float>(Z);
							++counter;
							geometric_edge_first = true;
						}
						else if (counter == 1)
						{
							x_two = X;
							z_two = static_cast<float>(Z);
							++counter;
							geometric_edge_second = true;
						}
					}					
				}

				if (counter == 2)
				{
					if (x_one < x_two)
					{
						xFirst = static_cast<int>(std::round(x_one));
						xSecond = static_cast<int>(std::round(x_two));
						zFirst = z_one;
						zSecond = z_two;
					}
					else
					{
						xFirst = static_cast<int>(std::round(x_two));
						xSecond = static_cast<int>(std::round(x_one));
						zFirst = z_two;
						zSecond = z_one;
					}

					left_flag = (x_one < x_two) ? geometric_edge_first : geometric_edge_second;
					right_flag = (x_one < x_two) ? geometric_edge_second : geometric_edge_first;

					for (int x = xFirst; x <= xSecond; ++x)
					{
						if (x < 0 || x >= static_cast<int>(cube[0].size())) 
							continue;

						if (xSecond == xFirst)
							tPixel = 0.0f;
						else
							tPixel = static_cast<float>((x - xFirst)) / (xSecond - xFirst);
						zPixel = zFirst + tPixel * (zSecond - zFirst);

						if (x == xFirst || x == xSecond || y == Ymin || y == Ymax)
						{
							if (zPixel <= buffer_depth[y][x])
							{
								buffer_depth[y][x] = zPixel;
								cube[y][x] = '+';
							}
						}
						else
						{
							if (zPixel <= buffer_depth[y][x])
							{
								buffer_depth[y][x] = zPixel;
								cube[y][x] = symbol;
							}
						}
					}
				}
			}
		}
	}
}
// function horizontal rotation
void horizontal_rotation(std::vector<std::vector<char>>& cube, const std::array<Point, counter_points>& points, std::vector<std::vector<float>>& buffer_depth, bool direction = true)
{
	float angle = 0.00f;
	float x = 0.00f;
	float y = 0.00f;
	float z = 0.00f;

	std::array<Point, counter_points> points_temp = points;

	while (true)
	{
		for (auto& row : cube)
			std::fill(row.begin(), row.end(), ' ');
		for(auto& row : buffer_depth)
			std::fill(row.begin(), row.end(), 10000.0f);
		for (size_t i = 0; i < counter_points; ++i)
		{
			x = points[i].get_x() * cos(angle) - points[i].get_z() * sin(angle);
			y = points[i].get_y();
			z = points[i].get_x() * sin(angle) + points[i].get_z() * cos(angle);

			points_temp[i].set_x(x);
			points_temp[i].set_y(y);
			points_temp[i].set_z(z);
		}

		draw_cube(points_temp, cube, buffer_depth);
		output(cube);

		angle += (direction ? 0.05f : -0.05f);
		if (angle > 6.28f) angle -= 6.28f;
		if (angle < 0) angle += 6.28f;

		Sleep(30);
	}
}
// function vertical rotation
void vertical_rotation(std::vector<std::vector<char>>& cube, const std::array<Point, counter_points>& points, std::vector<std::vector<float>>& buffer_depth, bool direction = true)
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float angle = 0.00f;

	std::array<Point, counter_points> points_temp = points;

	while (true)
	{

		for (auto& row : cube)
			std::fill(row.begin(), row.end(), ' ');
		for (auto& row : buffer_depth)
			std::fill(row.begin(), row.end(), 10000.0f);
		for (size_t i = 0; i < counter_points; ++i)
		{
			x = points[i].get_x();
			y = points[i].get_y() * cos(angle) - points[i].get_z() * sin(angle);
			z = points[i].get_y() * sin(angle) + points[i].get_z() * cos(angle);

			points_temp[i].set_x(x);
			points_temp[i].set_y(y);
			points_temp[i].set_z(z);
		}

		draw_cube(points_temp, cube, buffer_depth);
		output(cube);

		angle += (direction ? 0.05f : -0.05f);
		if (angle > 6.28f) angle -= 6.28f;
		if (angle < 0) angle += 6.28f;

		Sleep(30);
	}
}
// finction diagonal rotation
void diagonal_rotation(std::vector<std::vector<char>>& cube, const std::array<Point, counter_points>& points, std::vector<std::vector<float>>& buffer_depth, bool direction = true)
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float angle = 0.00f;

	std::array<Point, counter_points> points_temp = points;

	while (true)
	{

		for (auto& row : cube)
			std::fill(row.begin(), row.end(), ' ');
		for (auto& row : buffer_depth)
			std::fill(row.begin(), row.end(), 10000.0f);
		for (size_t i = 0; i < counter_points; ++i)
		{
			x = points[i].get_x() * cosf(angle) - points[i].get_z() * sinf(angle);
			z = points[i].get_x() * sinf(angle) + points[i].get_z() * cosf(angle);
			y = points[i].get_y() * cosf(angle) - z * sinf(angle);
			z = points[i].get_y() * sinf(angle) + z * cosf(angle);

			points_temp[i].set_x(x);
			points_temp[i].set_y(y);
			points_temp[i].set_z(z);
		}

		draw_cube(points_temp, cube, buffer_depth);
		output(cube);

		angle += (direction ? 0.05f : -0.05f);
		if (angle > 6.28f) angle -= 6.28f;
		if (angle < 0) angle += 6.28f;

		Sleep(30);
	}
}
// program entry point
int main(int arg_c, char* arg_v[])
{
	const unsigned int width = console_size().first;
	const unsigned int height = console_size().second;

	std::vector<std::vector<char>> cube(height, std::vector<char>(width, ' '));
	std::vector<std::vector<float>> z_buffer(height, std::vector<float>(width, 10000.0f));

	std::array<Point, counter_points> points;

	setting_value_points(points);

	std::cout << "enter scale: ";
	std::cin >> scale;
	std::cout << "enter screen position x: ";
	std::cin >> screen_position_x;
	std::cout << "enter screen position y: ";
	std::cin >> screen_position_y;

	hide_cursor();
	//horizontal_rotation(cube, points, z_buffer);
	//vertical_rotation(cube, points, z_buffer);
	//diagonal_rotation(cube, points, z_buffer, false);
	draw_cube(points, cube, z_buffer);
	output(cube);

	return 0;
}