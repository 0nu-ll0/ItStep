#include "../{headers}/vector.h"

int main(int arg_c, char* arg_v[])
{
	vector _vector;

	std::vector<std::string> menu_items
									   {"input coordinats", "module", "scalar product two vectors",
										"collinearity", "orthogonality", "normalize", "addition two vectors",
										"substraction two vectors", "dot product two vectors",
		                                "increase of a vector by one", "vector decrement", "console output",
										"graphic output", "exit"
									   };

	_vector.menu(menu_items);

	return 0;
}

//Window window;
//CoordinatePlane plane;

//window.display(5, 10, 15);

//std::cin >> _vector;
//std::cout << _vector << std::endl;
//system("pause");
//// Получаем дескриптор окна консоли
//HWND hWnd = GetConsoleWindow();
//// Скрываем его
//ShowWindow(hWnd, SW_HIDE);
//vector graph(5, 10, 15);
//graph.get_window().display(graph.get_x(), graph.get_y(), graph.get_z());
//_vector.get_window().display(5, 10, 15);
//
//ShowWindow(hWnd, SW_SHOW);
//std::cin >> _vector;
//std::cout << _vector << std::endl;
//system("pause");
//CloseWindow(hWnd);
//plane.filling();
//plane.drawing_point(0, 0, 0);
//plane.output();

//system("pause");