#include "../{headers}/graphic_window.h"

#include <iostream>

//std::unique_ptr<sf::RenderWindow> window;

// function drawing cells in window
void Window::drawing_cells()
{
    const unsigned int width_descktop = window->getSize().x;
    const unsigned int height_descktop = window->getSize().y;

    const unsigned int padding_horizontal = 920;
    const unsigned int padding_vertical = 20;

    const unsigned int counter_point = 4;
    const unsigned int counter_lines_h = 290;
    const unsigned int counter_lines_v = 400;
    const unsigned int counter_lines_d = 100;

    const unsigned int step_row = 20;
    const unsigned int step_col = 20;

    float x = 0.f;
    float y = 0.f;
    float x_begin = width_descktop / 2;
    float y_begin = padding_vertical * 2;
    float x_end = 440;
    float y_end = 560;

    float length = 520.f;
    float thickness = 500.f;

    sf::ConvexShape plane_applicate;
    sf::ConvexShape plane_ordinate;
    sf::ConvexShape plane_abscissa;

    sf::VertexArray lines_horizontal(sf::Lines, counter_lines_h);
    sf::VertexArray lines_horizontal_apl(sf::Lines, counter_lines_v);
    sf::VertexArray lines_vertical(sf::Lines, counter_lines_v);
    sf::VertexArray lines_vertical_abs(sf::Lines, counter_lines_v);
    sf::VertexArray lines_diagonal_abs(sf::Lines, counter_lines_d);
    sf::VertexArray lines_diagonal_apl(sf::Lines, counter_lines_d);

    x = width_descktop / 2;
    y = padding_vertical;

    plane_ordinate.setPointCount(counter_point);

    plane_ordinate.setPoint(0, sf::Vector2f(x, y));
    plane_ordinate.setPoint(1, sf::Vector2f(x + length, y));
    plane_ordinate.setPoint(2, sf::Vector2f(x + length, y + length));
    plane_ordinate.setPoint(3, sf::Vector2f(x, y + length));

    plane_ordinate.setFillColor(sf::Color::Black);

    plane_applicate.setPointCount(counter_point);

    plane_applicate.setPoint(0, sf::Vector2f(x, y + length));
    plane_applicate.setPoint(1, sf::Vector2f(x + length, y + length));
    plane_applicate.setPoint(2, sf::Vector2f(x, y + length * 2));
    plane_applicate.setPoint(3, sf::Vector2f(x - length, y + length * 2));

    plane_applicate.setFillColor(sf::Color::Black);

    plane_abscissa.setPointCount(counter_point);

    plane_abscissa.setPoint(0, sf::Vector2f(x - length, y + length));
    plane_abscissa.setPoint(1, sf::Vector2f(x, y));
    plane_abscissa.setPoint(2, sf::Vector2f(x, y + length));
    plane_abscissa.setPoint(3, sf::Vector2f(x - length, y + length * 2));

    plane_abscissa.setFillColor(sf::Color::Black);

    x = 0;
    y = 0;

    for (size_t i = 0; i < counter_lines_h / 2; i += 2)
    {
        lines_horizontal[i].position = sf::Vector2f(x, y);
        lines_horizontal[i].color = sf::Color::Blue;
        lines_horizontal[i + 1].position = sf::Vector2f(x + width_descktop, y);
        lines_horizontal[i + 1].color = sf::Color::Blue;
        y += step_row;
    }

    x = 0;
    y = 0;

    for (size_t i = 0; i < counter_lines_v / 2; i += 2)
    {
        lines_vertical[i].position = sf::Vector2f(x, y);
        lines_vertical[i].color = sf::Color::Blue;
        lines_vertical[i + 1].position = sf::Vector2f(x, y + height_descktop);
        lines_vertical[i + 1].color = sf::Color::Blue;
        x += step_col;
    }

    for (size_t i = 0; i < counter_lines_d / 2; i += 2)
    {
        lines_diagonal_abs[i].position = sf::Vector2f(x_begin, y_begin);
        lines_diagonal_abs[i].color = sf::Color::White;
        lines_diagonal_abs[i + 1].position = sf::Vector2f(x_end, y_end);
        lines_diagonal_abs[i + 1].color = sf::Color::White;
        y_begin += step_row;
        y_end += step_row;
    }

    x_begin = width_descktop / 2 + step_col;
    y_begin = height_descktop / 2;
    x_end = 460;
    y_end = height_descktop - step_row;

    for (size_t i = 0; i < counter_lines_d / 2; i += 2)
    {
        lines_diagonal_apl[i].position = sf::Vector2f(x_begin, y_begin);
        lines_diagonal_apl[i].color = sf::Color::White;
        lines_diagonal_apl[i + 1].position = sf::Vector2f(x_end, y_end);
        lines_diagonal_apl[i + 1].color = sf::Color::White;
        x_begin += step_col;
        x_end += step_col;
    }

    x_begin = width_descktop / 2 - step_col;
    y_begin = step_row * 2;
    x_end = x_begin;
    y_end = height_descktop / 2 + step_row;

    for (size_t i = 0; i < counter_lines_d / 2; i += 2)
    {
        lines_vertical_abs[i].position = sf::Vector2f(x_begin, y_begin);
        lines_vertical_abs[i].color = sf::Color::White;
        lines_vertical_abs[i + 1].position = sf::Vector2f(x_end, y_end);
        lines_vertical_abs[i + 1].color = sf::Color::White;
        x_begin -= step_col;
        x_end -= step_col;
        y_begin += step_row;
        y_end += step_row;
    }

    x_begin = width_descktop / 2 - step_col;
    y_begin = height_descktop / 2 + step_row;
    x_end = x_begin + length;
    y_end = y_begin;

    for (size_t i = 0; i < counter_lines_d / 2; i += 2)
    {
        lines_horizontal_apl[i].position = sf::Vector2f(x_begin, y_begin);
        lines_horizontal_apl[i].color = sf::Color::White;
        lines_horizontal_apl[i + 1].position = sf::Vector2f(x_end, y_end);
        lines_horizontal_apl[i + 1].color = sf::Color::White;
        x_begin -= step_col;
        x_end -= step_col;
        y_begin += step_row;
        y_end += step_row;
    }

    window->draw(plane_ordinate);
    window->draw(lines_horizontal);
    window->draw(lines_vertical);
    window->draw(plane_abscissa);
    window->draw(plane_applicate);
    window->draw(lines_diagonal_abs);
    window->draw(lines_diagonal_apl);
    window->draw(lines_vertical_abs);
    window->draw(lines_horizontal_apl);
}
// function drawing rectangular coordinate system in space
void Window::drawing_rectangular_coordinate_system_in_space()
{
    const unsigned int counter_vertex = 3;

    const unsigned int width_descktop = window->getSize().x;
    const unsigned int height_descktop = window->getSize().y;

    const float length_axis_x = 1475.f;
    const float length_axis_y = 1040.f;
    const float length_axis_z = 1040.f;

    const float thickness = 4.f;

    const float step_row = 20.f;
    const float step_col = 20.f;

    float angle_rotate = 0.f;

    float x = 0.f;
    float y = 0.f;

    sf::RectangleShape axis_x(sf::Vector2f(length_axis_x, thickness));
    sf::RectangleShape axis_y(sf::Vector2f(length_axis_y, thickness));
    sf::RectangleShape axis_z(sf::Vector2f(length_axis_z, thickness));

    sf::VertexArray triangle_x(sf::Triangles, counter_vertex);
    sf::VertexArray triangle_y(sf::Triangles, counter_vertex);
    sf::VertexArray triangle_z(sf::Triangles, counter_vertex);

    triangle_x[0].position = sf::Vector2f(width_descktop / 4 - step_col * 3, height_descktop - step_row * 2);
    triangle_x[1].position = sf::Vector2f(width_descktop / 4 - step_col * 3, height_descktop);
    triangle_x[2].position = sf::Vector2f(width_descktop / 4 - step_col, height_descktop);
    triangle_x[0].color = sf::Color::Blue;
    triangle_x[1].color = sf::Color::Blue;
    triangle_x[2].color = sf::Color::Blue;

    triangle_y[0].position = sf::Vector2f(width_descktop * 0.75 + step_col * 2, height_descktop / 2 - step_row);
    triangle_y[1].position = sf::Vector2f(width_descktop * 0.75 + step_col * 3, height_descktop / 2);
    triangle_y[2].position = sf::Vector2f(width_descktop * 0.75 + step_col * 2, height_descktop / 2 + step_row);
    triangle_y[0].color = sf::Color::Black;
    triangle_y[1].color = sf::Color::Black;
    triangle_y[2].color = sf::Color::Black;

    triangle_z[0].position = sf::Vector2f(width_descktop / 2 - step_col, step_row);
    triangle_z[1].position = sf::Vector2f(width_descktop / 2, y);
    triangle_z[2].position = sf::Vector2f(width_descktop / 2 + step_col, step_row);
    triangle_z[0].color = sf::Color::Black;
    triangle_z[1].color = sf::Color::Black;
    triangle_z[2].color = sf::Color::Black;

    y = 20.f;

    angle_rotate = 135.f;
    axis_x.setPosition(width_descktop / 2 + width_descktop / 4 + step_row * 2 + 2, y);
    axis_x.rotate(angle_rotate);
    axis_x.setFillColor(sf::Color::White);

    axis_y.setPosition(width_descktop / 4 - step_row * 2, height_descktop / 2 - 2);
    axis_y.setFillColor(sf::Color::White);

    angle_rotate = 90.f;
    axis_z.setPosition(width_descktop / 2 + 2, y);
    axis_z.rotate(angle_rotate);
    axis_z.setFillColor(sf::Color::White);

    window->draw(axis_x);
    window->draw(axis_y);
    window->draw(axis_z);

    window->draw(triangle_x);
    window->draw(triangle_y);
    window->draw(triangle_z);
}
// function drawing hathes
void Window::drawing_hatches()
{
    const unsigned int width_descktop = window->getSize().x;
    const unsigned int height_descktop = window->getSize().y;

    const unsigned int step_row = 20;
    const unsigned int step_col = 20;

    const unsigned int counter_hatches = 52;

    const float length = 20.f;
    const float thickness = 2.5;

    float x = width_descktop / 4 - step_col * 2;
    float y = height_descktop / 2 - step_row / 2;

    float angle = 90.f;

    sf::RectangleShape hatch(sf::Vector2f(thickness, length));

    hatch.setFillColor(sf::Color::White);
    hatch.setPosition(sf::Vector2f(x, y));

    for (size_t i = 0; i < counter_hatches; ++i)
    {
        window->draw(hatch);

        x += step_col;

        hatch.setFillColor(sf::Color::White);
        hatch.setPosition(sf::Vector2f(x - 1, y));
    }

    x = width_descktop / 2 + step_col / 2;
    y = step_row;

    hatch.setRotation(angle);

    for (size_t i = 0; i < counter_hatches; ++i)
    {
        if (i != counter_hatches / 2)
            window->draw(hatch);

        y += step_row;

        hatch.setFillColor(sf::Color::White);
        hatch.setPosition(sf::Vector2f(x, y - 1));
    }

    angle = 135;

    x = width_descktop / 4 - step_col / 2;
    y = height_descktop - step_row * 1.75;

    hatch.setRotation(angle);
    hatch.setFillColor(sf::Color::White);
    hatch.setPosition(sf::Vector2f(x, y));

    for (size_t i = 0; i < counter_hatches; ++i)
    {
        if (i != counter_hatches / 2 - 1)
            window->draw(hatch);

        y -= step_row;
        x += step_col;

        hatch.setFillColor(sf::Color::White);
        hatch.setPosition(sf::Vector2f(x - 1, y + 1));
    }
}
// function drawing point
void Window::drawing_points(double X, double Y, double Z)
{
    const unsigned int width_descktop = window->getSize().x;
    const unsigned int height_descktop = window->getSize().y;

    const unsigned int step_col = 20;
    const unsigned int step_row = 20;

    const unsigned int size = 6;

    sf::CircleShape pointX(size);
    sf::CircleShape pointY(size);
    sf::CircleShape pointZ(size);

    int x = width_descktop / 2 - size;
    int y = height_descktop / 2 - size;

    pointX.setFillColor(sf::Color::Red);
    pointX.setPosition(x - X * step_col, y + X * step_row);

    pointY.setFillColor(sf::Color::Green);
    pointY.setPosition(x + Y * step_col, y);

    pointZ.setFillColor(sf::Color::Blue);
    pointZ.setPosition(x, y - Z * step_row);

    window->draw(pointX);
    window->draw(pointY);
    window->draw(pointZ);
}
// dunction drawing dot lines
void Window::drawing_dot_lines(double X, double Y, double Z)
{
    const unsigned int width_descktop = window->getSize().x;
    const unsigned int height_descktop = window->getSize().y;

    const unsigned int step_col = 20;
    const unsigned int step_row = 20;

    const unsigned int size = 2;

    float x = width_descktop / 2 - size;
    float y = height_descktop / 2 - size;

    float x_statement = 0.f;
    float y_statement = 0.f;

    int count_iteration = 0;
    int step_iteration = 10;

    sf::CircleShape point(size);

    if (Y < 0)
        x -= step_col;

    point.setFillColor(sf::Color::Green);
    point.setPosition(x - X * step_col + step_col, y + X * step_row);

    count_iteration = abs(Y) * 2;
    if (Y < 0)
        count_iteration += 2;
    // step axis y;
    for (size_t i = 0; i < count_iteration; ++i)
    {
        window->draw(point);

        point.setFillColor(sf::Color::Green);
        point.setPosition(x - X * step_col + step_col, y + X * step_row);

        if (Y > 0)
            x += step_iteration;
        else
            x -= step_iteration;
    }
    // step axis x
    count_iteration = abs(X) * 2;

    x_statement = x - X * step_col - size;
    y_statement = y + X * step_row - size;

    if (Y < 0)
        x_statement += step_col * 2 - size;

    if ((Y < 0 && X < 0) || (Y < 0 && X > 0))
        x += step_col;
    else if ((Y > 0 && X > 0) || (Y > 0 && X < 0))
        x -= step_col;

    for (size_t i = 0; i < count_iteration; ++i)
    {
        if ((Y > 0 && X > 0) || (Y < 0 && X > 0))
        {
            x += step_iteration;
            y -= step_iteration;
        }
        else if ((Y > 0 && X < 0) || (Y < 0 && X < 0))
        {
            x -= step_iteration;
            y += step_iteration;
        }

        point.setFillColor(sf::Color::Green);
        point.setPosition(x - X * step_col + step_col, y + X * step_row);

        window->draw(point);
    }
    // step axis z
    count_iteration = abs(Z) * 2 + 1;

    x = x_statement;
    y = y_statement + size;

    if ((X > 0 && Y > 0) || (X < 0 && Y > 0))
        x += size * 2 - size;
    else if ((X > 0 && Y < 0) || (X < 0 && Y < 0))
        x += size * 2;

    for (size_t i = 0; i < count_iteration; ++i)
    {
        point.setFillColor(sf::Color::Green);
        point.setPosition(x, y);

        window->draw(point);

        if (Z > 0)
            y -= step_iteration;
        else
            y += step_iteration;
    }
}
// function drawing vector
void Window::drawing_vector(double X, double Y, double Z)
{
    const unsigned int width_descktop = window->getSize().x;
    const unsigned int height_descktop = window->getSize().y;

    const unsigned int count_point = 3;

    const float step_col = 20.f;
    const float step_row = 20.f;

    const float radius = 5.f;

    float x = 0;
    float y = 0;
    float turn = 22.5;

    const float angle = 360.f;
    const float fault = 2.f;
    const float size = 4.f;

    sf::Vector2f begin;
    sf::Vector2f end;

    sf::CircleShape begin_vector(radius * 2);
    //sf::CircleShape end_vector(1.f);

    sf::ConvexShape vector(size), triangle(size), triangle_black(size - 1);

    x = width_descktop / 2 - 1;
    y = height_descktop / 2 - 1;

    begin.x = width_descktop / 2 - radius + step_col / 2 - radius;
    begin.y = height_descktop / 2 - radius + step_row / 2 - radius;

    begin_vector.setPosition(begin.x - radius * 2, begin.y - radius * 2);
    begin_vector.setFillColor(sf::Color::Black);

    y += X * step_col;
    y -= Z * step_row;

    x -= X * step_col;
    x += Y * step_col;

    vector.setPoint(0, sf::Vector2f(x - 1, y - 1));
    vector.setPoint(1, sf::Vector2f(begin.x - 1, begin.y - 1));
    vector.setPoint(2, sf::Vector2f(begin.x + 1, begin.y + 1));
    vector.setPoint(3, sf::Vector2f(x + 1, y + 1));
    vector.setFillColor(sf::Color::Yellow);

    triangle.setPoint(0, sf::Vector2f(x - 5, y + 5));
    triangle.setPoint(1, sf::Vector2f(x - 5, y - 5));
    triangle.setPoint(2, sf::Vector2f(x + 5, y - 5));
    triangle.setPoint(3, sf::Vector2f(x + 5, y + 5));
    triangle.setFillColor(sf::Color::Yellow);

    if (vector.getPoint(NULL).x <= (width_descktop / 2) && vector.getPoint(NULL).y >= (height_descktop / 2))
    {
        triangle_black.setPoint(0, sf::Vector2f(x - 5, y - 5));
        triangle_black.setPoint(1, sf::Vector2f(x + 5, y - 5));
        triangle_black.setPoint(2, sf::Vector2f(x + 5, y + 5));
        triangle_black.setFillColor(sf::Color::Black);
    }
    else if (vector.getPoint(NULL).x <= (width_descktop / 2) && vector.getPoint(NULL).y <= (height_descktop / 2))
    {
        triangle_black.setPoint(0, sf::Vector2f(x + 5, y - 5));
        triangle_black.setPoint(1, sf::Vector2f(x + 5, y + 5));
        triangle_black.setPoint(2, sf::Vector2f(x - 5, y + 5));
        triangle_black.setFillColor(sf::Color::Black);
    }
    else if (vector.getPoint(NULL).x >= (width_descktop / 2) && vector.getPoint(NULL).y <= (height_descktop / 2))
    {
        triangle_black.setPoint(0, sf::Vector2f(x - 5, y - 5));
        triangle_black.setPoint(1, sf::Vector2f(x - 5, y + 5));
        triangle_black.setPoint(2, sf::Vector2f(x + 5, y + 5));
        triangle_black.setFillColor(sf::Color::Black);
    }
    else if (vector.getPoint(NULL).x >= (width_descktop / 2) && vector.getPoint(NULL).y >= (height_descktop / 2))
    {
        triangle_black.setPoint(0, sf::Vector2f(x - 5, y + 5));
        triangle_black.setPoint(1, sf::Vector2f(x - 5, y - 5));
        triangle_black.setPoint(2, sf::Vector2f(x + 5, y - 5));
        triangle_black.setFillColor(sf::Color::Black);
    }

    window->draw(begin_vector);
    window->draw(triangle);
    window->draw(triangle_black);
    window->draw(vector);
}
// function construction of a rectangular parallelepiped
void Window::drawing_rectangular_parallelepiped(double X, double Y, double Z)
{
    const unsigned int width_descktop = window->getSize().x;
    const unsigned int height_descktop = window->getSize().y;

    const unsigned int step_row = 20;
    const unsigned int step_col = 20;

    const float radius = 2.f;

    float x = 0;
    float y = 0;

    float statement_x = 0;
    float statement_y = 0;

    int count_iteration = 0;
    unsigned int count_direction = 6;

    const unsigned int rows = 8;
    const unsigned int columns = 9;

    int step_iteration = 10;
    int row_mask = 0;

    bool flag = true;

    sf::CircleShape point(radius);

    const unsigned int masks[rows][columns]
    {
        {0, 2, 5, 3, 4, 1, -1, -1, -1},
        {0, 4, 2, 5, 1, 3, 0, 2, -1},
        {1, 4, 0, 2, 5, 3, 4, -1},
        {3, 5, 1, 4, 0, 3, -1, -1, -1},
        {5, 3, 1, 2, 0, 5, -1, -1, -1},
        {4, 0, 2, 5, 1, 3, -1, -1, -1},
        {0, 2, 1, 3, 4, 0, 5, -1, -1},
        {4, 0, 2, 5, 3, 1, 2, 0, 4}
    };
    std::string directions[rows] = { "up", "down", "left", "right", "diagonal up", "diagonal down" };

    int index_hat = 0;
    int index_count_lines = 0;
    int index_iterations = 0;

    if (X > 0 && Y > 0 && Z > 0)
        row_mask = 0;
    else if (X < 0 && Y > 0 && Z > 0)
        row_mask = 1;
    else if (X > 0 && Y < 0 && Z > 0)
        row_mask = 2;
    else if (X > 0 && Y < 0 && Z < 0)
        row_mask = 3;
    else if (X < 0 && Y > 0 && Z < 0)
        row_mask = 4;
    else if (X > 0 && Y > 0 && Z < 0)
        row_mask = 5;
    else if (X < 0 && Y < 0 && Z < 0)
        row_mask = 6;
    else if (X < 0 && Y < 0 && Z > 0)
        row_mask = 7;

    if (row_mask == 0)
    {
        x = width_descktop / 2 - radius + (abs(Y) * step_col);
        y = height_descktop / 2 - radius;
    }
    else if (row_mask == 1)
    {
        count_direction += 2;
        x = width_descktop / 2 - radius + (abs(Y) * step_col);
        y = height_descktop / 2 - radius;
    }
    else if (row_mask == 2)
    {
        ++count_direction;
        x = width_descktop / 2 - radius - (abs(X) * step_col);
        y = (height_descktop / 2 - radius) + ((abs(X) + abs(Z)) * step_row) - abs(Z) * step_row * 2;
    }
    else if (row_mask == 3)
    {
        x = (width_descktop / 2 - radius) - (abs(Y) * step_col);
        y = height_descktop / 2 - radius;
    }
    else if (row_mask == 4)
    {
        x = (width_descktop / 2 - radius) + (abs(X) * step_col);
        y = (height_descktop / 2 - radius) - (abs(X) * step_col);
    }
    else if (row_mask == 5)
    {
        x = width_descktop / 2 - radius + ((abs(Y) - abs(X)) * step_col);
        y = height_descktop / 2 - radius + ((X + abs(Z)) * step_row);
    }
    else if (row_mask == 6)
    {
        ++count_direction;
        x = width_descktop / 2 - radius;
        y = height_descktop / 2 - radius + (abs(Z) * step_row);
    }
    else if (row_mask == 7)
    {
        count_direction += 3;
        x = width_descktop / 2 - radius;
        y = height_descktop / 2 - radius;
    }
    goto Begin;

Direction:
    window->draw(point);
    if (directions[index_hat] == "up")
    {
        count_iteration = abs(Z) * 2;
        if (index_iterations < (count_iteration))
            y -= step_iteration;
        goto Execution;
    }
    else if (directions[index_hat] == "down")
    {
        if (index_hat == 1 && row_mask == 0)
        {
            if (flag)
            {
                x = width_descktop / 2 - radius - abs(X) * step_col;
                y = height_descktop / 2 - radius - ((abs(Z) - abs(X)) * step_row);
                flag = false;
            }
        }

        count_iteration = abs(Z) * 2;
        if (index_iterations < (count_iteration))
            y += step_iteration;
        goto Execution;
    }
    else if (directions[index_hat] == "left")
    {
        count_iteration = abs(Y) * 2;
        if (index_iterations < (count_iteration))
            x -= step_iteration;
        goto Execution;
    }
    else if (directions[index_hat] == "right")
    {
        if (row_mask == 3 && index_count_lines == 5)
        {
            if (flag)
            {
                x = width_descktop / 2 - radius - (abs(X) + abs(Y)) * step_col;
                y = height_descktop / 2 - radius + (abs(X) + abs(Z)) * step_row;
                flag = false;
            }
        }
        count_iteration = abs(Y) * 2;
        if (index_iterations < (count_iteration))
            x += step_iteration;
        goto Execution;
    }
    else if (directions[index_hat] == "diagonal up")
    {
        if (row_mask == 7 && index_count_lines == 8)
        {
            if (flag)
            {
                x = width_descktop / 2 - radius;
                y = height_descktop / 2 - radius - (abs(Z) * step_row);
                flag = false;
            }
        }

        count_iteration = abs(X) * 2;
        if (index_iterations < (count_iteration))
        {
            x += step_iteration;
            y -= step_iteration;
        }
        goto Execution;
    }
    else if (directions[index_hat] == "diagonal down")
    {

        if (index_hat == 5 && row_mask == 4 && index_count_lines == 5)
        {
            if (flag)
            {
                x = width_descktop / 2 - radius + ((abs(X) + abs(Y)) * step_col);
                if (Z > X)
                    y = height_descktop / 2 - radius - (static_cast<int>(abs(abs(Z) - abs(X))) * step_row);
                else
                    y = height_descktop / 2 - radius + (static_cast<int>(abs(abs(Z) - abs(X))) * step_row);
                flag = false;
            }
        }

        count_iteration = abs(X) * 2;
        if (index_iterations < (count_iteration))x -= step_iteration;
        if (index_iterations < (count_iteration))y += step_iteration;
        goto Execution;
    }
Begin:
    while (index_count_lines < count_direction)
    {
        index_hat = masks[row_mask][index_count_lines];
        if (index_hat == -1)
            break;
        goto Direction;
    Execution:
        if (index_iterations < count_iteration)
        {
            point.setPosition(x, y);
            point.setFillColor(sf::Color::Red);
            window->draw(point);
            ++index_iterations;
            goto Direction;
        }
        ++index_count_lines;
        index_iterations = 0;
    }
}
// function drawing window
void Window::display(double X, double Y, double Z)
{
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear(sf::Color::White);

        drawing_cells();
        drawing_rectangular_coordinate_system_in_space();
        drawing_hatches();
        drawing_points(X, Y, Z);
        drawing_dot_lines(X, Y, Z);
        drawing_rectangular_parallelepiped(X, Y, Z);
        drawing_vector(X, Y, Z);

        window->display();
    }
}

//void Window::drawing_vector(double X, double Y, double Z)
//{
//    const unsigned int width_descktop = window->getSize().x;
//    const unsigned int height_descktop = window->getSize().y;
//
//    const unsigned int count_point = 3;
//
//    const float step_col = 20.f;
//    const float step_row = 20.f;
//
//    const float radius = 5.f;
//
//    float x = 0;
//    float y = 0;
//    float turn = 22.5;
//
//    const float angle = 360.f;
//    const float fault = 2.f;
//    const float size = 4.f;
//
//    sf::Vector2f begin;
//    sf::Vector2f end;
//
//    sf::CircleShape begin_vector(radius * 2);
//    //sf::CircleShape end_vector(1.f);
//
//    sf::ConvexShape vector(size), triangle(size), triangle_black(size - 1);
//
//    x = width_descktop / 2 - 1;
//    y = height_descktop / 2 - 1;
//
//    begin.x = width_descktop / 2 - radius + step_col / 2 - radius;
//    begin.y = height_descktop / 2 - radius + step_row / 2 - radius;
//
//    begin_vector.setPosition(begin.x - radius * 2, begin.y - radius * 2);
//    begin_vector.setFillColor(sf::Color::Black);
//
//    y += X * step_col;
//    y -= Z * step_row;
//
//    x -= X * step_col;
//    x += Y * step_col;
//
//    //end_vector.setFillColor(sf::Color::Blue);
//    //end_vector.setPosition(x, y);
//    vector.setPoint(0, sf::Vector2f(x - 1, y - 1));
//    vector.setPoint(1, sf::Vector2f(begin.x - 1, begin.y - 1));
//    vector.setPoint(2, sf::Vector2f(begin.x + 1, begin.y + 1));
//    vector.setPoint(3, sf::Vector2f(x + 1, y + 1));
//    vector.setFillColor(sf::Color::Yellow);
//
//    triangle.setPoint(0, sf::Vector2f(x - 5, y + 5));
//    triangle.setPoint(1, sf::Vector2f(x - 5, y - 5));
//    triangle.setPoint(2, sf::Vector2f(x + 5, y - 5));
//    triangle.setPoint(3, sf::Vector2f(x + 5, y + 5));
//    triangle.setFillColor(sf::Color::Yellow);
//
//    if (vector.getPoint(NULL).x <= (width_descktop / 2) && vector.getPoint(NULL).y >= (height_descktop / 2))
//    {
//        triangle_black.setPoint(0, sf::Vector2f(x - 5, y - 5));
//        triangle_black.setPoint(1, sf::Vector2f(x + 5, y - 5));
//        triangle_black.setPoint(2, sf::Vector2f(x + 5, y + 5));
//        triangle_black.setFillColor(sf::Color::Black);
//    }
//    else if (vector.getPoint(NULL).x <= (width_descktop / 2) && vector.getPoint(NULL).y <= (height_descktop / 2))
//    {
//        triangle_black.setPoint(0, sf::Vector2f(x + 5, y - 5));
//        triangle_black.setPoint(1, sf::Vector2f(x + 5, y + 5));
//        triangle_black.setPoint(2, sf::Vector2f(x - 5, y + 5));
//        triangle_black.setFillColor(sf::Color::Black);
//    }
//    else if (vector.getPoint(NULL).x >= (width_descktop / 2) && vector.getPoint(NULL).y <= (height_descktop / 2))
//    {
//        triangle_black.setPoint(0, sf::Vector2f(x - 5, y - 5));
//        triangle_black.setPoint(1, sf::Vector2f(x - 5, y + 5));
//        triangle_black.setPoint(2, sf::Vector2f(x + 5, y + 5));
//        triangle_black.setFillColor(sf::Color::Black);
//    }
//    else if (vector.getPoint(NULL).x >= (width_descktop / 2) && vector.getPoint(NULL).y >= (height_descktop / 2))
//    {
//        triangle_black.setPoint(0, sf::Vector2f(x - 5, y + 5));
//        triangle_black.setPoint(1, sf::Vector2f(x - 5, y - 5));
//        triangle_black.setPoint(2, sf::Vector2f(x + 5, y - 5));
//        triangle_black.setFillColor(sf::Color::Black);
//    }
//
//    window->draw(begin_vector);
//    window->draw(triangle);
//    window->draw(triangle_black);
//    window->draw(vector);
//
//    //std::cout << vector.getPoint(0).x << '\t' << vector.getPoint(0).y << std::endl;
//    //std::cout << vector.getPoint(1).x << '\t' << vector.getPoint(1).y << std::endl;
//    //std::cout << vector.getPoint(2).x << '\t' << vector.getPoint(2).y << std::endl;
//    //std::cout << vector.getPoint(3).x << '\t' << vector.getPoint(3).y << std::endl;
//    //system("pause");
//}

//void Window::drawing_vector(double X, double Y, double Z)
//{
//    const unsigned int width_descktop = window->getSize().x;
//    const unsigned int height_descktop = window->getSize().y;
//
//    const float step_col = 20.f;
//    const float step_row = 20.f;
//
//    const float line_thickness = 1.0f;
//    const float head_size = 10.0f;
//    const float head_width = 6.0f;
//
//    sf::Vector2f vector_begin;
//
//    vector_begin.x = static_cast<float>(width_descktop) / 2.0f;
//    vector_begin.y = static_cast<float>(height_descktop) / 2.0f;
//
//    sf::Vector2f vector_end = vector_begin;
//
//    vector_end.y += static_cast<float>(X * step_col);
//    vector_end.y -= static_cast<float>(Z * step_row);
//    vector_end.x -= static_cast<float>(X * step_col);
//    vector_end.x += static_cast<float>(Y * step_col);
//
//    sf::Vector2f direction = vector_end - vector_begin;
//    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
//
//    if (length < 1.0f)
//        return;
//
//    sf::Vector2f unit_direction = direction / length;
//    sf::Vector2f unit_perpendicular(-unit_direction.y, unit_direction.x);
//
//    sf::Vector2f head_base = vector_end - unit_direction * head_size;
//
//    sf::ConvexShape vector;
//    vector.setPointCount(7);
//
//    vector.setPoint(0, vector_begin + unit_perpendicular * line_thickness);
//    vector.setPoint(1, head_base + unit_perpendicular * line_thickness);
//    vector.setPoint(2, head_base + unit_perpendicular * head_width);
//    vector.setPoint(3, vector_end);
//    vector.setPoint(4, head_base - unit_perpendicular * head_width);
//    vector.setPoint(5, head_base - unit_perpendicular * line_thickness);
//    vector.setPoint(6, vector_begin - unit_perpendicular * line_thickness);
//
//    vector.setFillColor(sf::Color::Yellow);
//    vector.setOutlineThickness(1.0f);
//
//    window->draw(vector);
//}