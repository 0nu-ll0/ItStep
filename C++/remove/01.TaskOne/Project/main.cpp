#include "../Headers/ComplexNumber.h"
#include "../Headers/Point.h"
#include "../Headers/Student.h"
#include "../Headers/Triangle.h"
#include <Windows.h>

int main(int arg_c, char* arg_v[])
{
	/*
	Student student;

	std::string path = arg_v[0];
	for (unsigned int i = 0; i < path.length(); ++i)
	{
		if (path[i] == '\\')
			path[i] = '/';
	}
	path += "/../../../../Files/student.txt";

	student.input();
	std::cout << student << std::endl;
	student.write_data_file(path);
	*/
	/*
	int a = -3;
	unsigned int b = a;

	std::cout << unsigned char(254) << std::endl;
	std::cout << ' ' << '-' << '-' << std::endl;
	std::cout << '|' << ' ' << ' ' << '|' << std::endl;
	std::cout << ' ' << '-' << '-' << std::endl;
	*/
	/*
	Complex number_one, number_two, number_three, number_four;

	std::cin >> number_one;
	std::cout << number_one;

	std::cin >> number_two;
	std::cout << number_two;
	Complex five(number_one);
	system("pause");

	number_three = number_one + number_two;
	number_four = number_one - number_two;

	std::cout << number_three << std::endl;
	std::cout << number_four << std::endl;
	std::cout << five << std::endl;
	std::cout << Complex::getObjectCount() << std::endl;
	*/
	/*
	std::string path = arg_v[0];
	for (unsigned int i = 0; i < path.length(); ++i)
	{
		if (path[i] == '\\')
			path[i] = '/';
	}
	path += "/../../../../Files/complex_numbers.txt";

	Point point;
	std::ofstream file;

	//file.open(path, std::ios::app);
	
	point.input();
	point.write_data_file(file, path);
	*/
	/*
	int start = 0;
	int stop = 0;

	int end = 0;


	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < end; ++j)
			std::cout << ' ';

		std::cout << '\\';
		stop = start;
		if (i != 14)
		{
			while (stop--)
				std::cout << ' ';
			std::cout << '.';
		}
		else
		{
			while (stop--)
				std::cout << '_';
			std::cout << '.';
		}
		start += 2;
		std::cout << std::endl;
		++end;
	}
	*/
	/*
	for (size_t i = 0; i < 14; ++i)
		std::cout << ' ';
	for (int i = 0; i < 30; ++i)
		std::cout << '-';
	std::cout << '\\' << std::endl;
	*/
	/*
	for (size_t i = 0; i < 50; ++i)
	{
		std::cout << '/';
		stop = start;
		while (stop--)
			std::cout << ' ';
		std::cout << '\\';
		++start;
			std::cout << std::endl;
	}

	std::cout << '|';
	for (size_t i = 0; i < 50; ++i)
		std::cout << '-';
	std::cout << '\\' << std::endl;
	*/

	/*
	Triangle test;

	test.input();
	test.output();
	*/

	int count_space = 0;
	int count_stars = 0;
	int count_arrow = 0;
	int entry = 0;

	count_stars = 90;
	count_arrow = 90;
	count_space = 90;
	while (true)
	{
		system("cls");
		for (size_t i = 0; i < count_arrow - entry; ++i)
			std::cout << '\n';
		for (size_t j = 0; j < count_arrow - count_stars; ++j)
			std::cout << ' ';
		for (size_t j = 0; j < count_space - entry; ++j)
			std::cout << ' ';
		for (size_t j = 0; j < entry; ++j)
			std::cout << '*';
		std::cout << std::endl;
		for (size_t k = 0; k < count_stars; ++k)
			std::cout << '*';
		std::cout << std::endl;
		++entry;
		--count_stars;

		Sleep(1000);
		system("pause");
	}

	system("pause");
	return 0;
}

/*
for (int i = 0; i < 5; ++i)
	std::cout << " | " << '\n' << "-+-" << '\n';

for (int i = 0; i < 10; ++i)
	std::cout << "---|";
std::cout << std::endl;

std::cout << "         ^\n";
for (int i = 0; i < 9; ++i)
{
	for (int j = 0; j < 9; ++j)
		std::cout << ' ';
	std::cout << "|\n";
	for (int j = 0; j < 8; ++j)
		std::cout << ' ';
	std::cout << "-+-\n";
}
std::cout << "        ^";
for (int i = 0; i < 10; ++i)
	std::cout << "---|";
std::cout << std::endl;
*/