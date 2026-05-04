#include "../{headers}/coordinate_plane.h"

// function fill coordinate plane
void CoordinatePlane::filling(const int& x, const int& y, const int& z)
{
    const unsigned char cross = 197;

    unsigned int max = 0;
    const unsigned int factor = 3;

    max = (static_cast<unsigned int>(abs(y)) > static_cast<unsigned int>(abs(x)) ? static_cast<unsigned int>(abs(y)) : static_cast<unsigned int>(abs(x)));
    max = (max > static_cast<unsigned int>(abs(z))) ? max : static_cast<unsigned int>(abs(z));

    set_height((max % 2 == 0) ? max * factor + 1 : max * factor);
    set_width(get_height() * factor);

    field.resize(get_height(), std::vector<unsigned char>(get_width(), ' '));
    
    for (size_t i = 0; i < get_height(); ++i)
        field[i].resize(get_width());

    int third_part = get_width() / 1.5 - 1;

    for (size_t i = 0; i < get_height(); ++i)
    {
        for (size_t j = 0; j < get_width(); ++j)
        {
            if (i != get_height() / 2)
            {
                if (j != (get_width() / 2))
                    field[i][j] = ' ';
                else
                    field[i][j] = '|';

                if (j == third_part)
                {
                    if (i != get_height() / 2 - 1)
                    {
                        field[i][j] = '/';
                        --third_part;
                    }
                    else
                    {
                        field[i][j] = '/';
                        third_part -= 2;
                    }
                }
            }
            else
            {
                if (j < (get_width() / 2))
                {
                    if (j % 3 == 2 && j != 0)
                        field[i][j] = '+';
                    else
                        field[i][j] = '-';
                }
                else if (j == (get_width() / 2))
                    field[i][j] = '/';
                else if (j > (get_width() / 2))
                {
                    if (j % 3 == 0)
                        field[i][j] = '+';
                    else
                        field[i][j] = '-';
                }
            }
        }
        //field[i].push_back('\n');
    }
}
// function draw points on coordinate plane
void CoordinatePlane::drawing_point(double X, double Y, double Z)
{
    const unsigned int step = 3;

    const unsigned int middle_width = get_width() / 2;
    const unsigned int middle_height = get_height() / 2;

    const unsigned int first_cross_positive = middle_width + 2;
    const unsigned int first_cross_negative = middle_width - 2;

    int x = 0;
    int z_row = 0;
    int z_col = 0;

    int iteration = 0;

    if (Y > 0)
    {
        iteration = 1;
        x = first_cross_positive + (Y - 1) * step;
    }
    else
    {
        iteration = -1;
        x = first_cross_negative + (Y + 1) * step;
    }
    int row = middle_height + X;
    int column = middle_width - X + iteration;
    int count_iteration = 0;
    z_row = row;

    field[middle_height + X][middle_width - X] = 'X';
    field[middle_height][x] = 'Y';
    field[middle_height - Z][middle_width] = 'Z';
    count_iteration = (abs(Y) * step) / 2;

    (static_cast<int>(abs(Y)) % 2 != 0) ? (Y > 0) ? ++column : --column : 0;
    
    for (size_t i = 0; i < count_iteration; ++i)
    {
        field[row][column] = '*';
        column += iteration;
        field[row][column] = ' ';
        column += iteration;
    }

    if ((X > 0 && Y > 0 && Z > 0) || (X > 0 && Y > 0 && Z < 0) || (X < 0 && Y > 0 && Z > 0) || (X < 0 && Y > 0 && Z < 0))
        z_col = column - 2;
    else if (X > 0 && Y < 0 && X > 0 || (X < 0 && Y < 0 && Z > 0) || (X < 0 && Y < 0 && Z < 0))
        z_col = column + 2;

    count_iteration = static_cast<int>(abs(X)) - 1;
    iteration = (X > 0) ? 1 : -1;

    if (X > 0 && Y < 0)
        column += step;
    else if (X < 0 && Y > 0)
        column -= step;
    else if (X > 0 && Y > 0)
        column -= 1;
    else
        column += 1;

    row -= iteration;

    for (size_t i = 0, j = column; i < count_iteration; ++i, j += iteration)
    {
        field[row][j] = '*';
        row -= iteration;
    }

    count_iteration = static_cast<int>(abs(Z));
    iteration = (Z < 0) ? 1 : -1;

    for (size_t i = 0; i < count_iteration; ++i)
    {
        z_row += iteration;
        field[z_row][z_col] = '*';
    }
}
// function output coordinate plane in console
void CoordinatePlane::output() const
{
    for (const auto& row : field) {
        for (unsigned char cell : row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }
}


//for (size_t i = 0; i < height; ++i)
//    std::copy(field[i].begin(), field[i].end(), std::ostream_iterator<unsigned char>(std::cout));
//height = (height % 2 == 0) ? height + 1 : height;
//width = height * 3;


    //bool stop = 0;

    //std::string value = "";

    //do
    //{
    //    stop = 0;
    //    // entering the x-coordinate
    //    std::cout << "enter the size of the coordinate plane: ";
    //    std::getline(std::cin, value, '\n');

    //    
    //    if (atoi(value.c_str()))
    //    {
    //        set_height(atoi(value.c_str()));
    //        stop = 1;
    //    }
    //    else if (value.length() == 1 && value[0] == '0')
    //    {
    //        set_height(0);
    //        stop = 1;
    //    }
    //    else
    //        std::cout << "data entry error !!!" << std::endl;
    //} while (!stop);

    //set_height(height);