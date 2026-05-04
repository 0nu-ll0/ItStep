#include "../{headers}/vector.h"

// menu function 
void vector::menu(std::vector<std::string> menu_items)
{
    vector vector_second;
    vector vector_result;

    double result = 0;

    std::string padding = "  ";
    std::string padding_window = "\t\t\t";
    std::string header = "vector control system";

    const unsigned int stretching = 15;

    const unsigned int rows = menu_items.size() + 5;
    unsigned int columns = menu_items[0].length();

    unsigned int index = 0;
    unsigned int choise = 0;
    unsigned int max = 0;
    unsigned int counter_spaces = 0;

    for (size_t i = 0; i < menu_items.size() - 1; ++i)
    {
        if (menu_items[i].length() < menu_items[i + 1].length())
        {
            columns = menu_items[i + 1].length() + stretching;
            max = i + 1;
        }
    }

    counter_spaces = columns;
    
    do
    {
        system("cls");

        index = 0;

        for (size_t i = 0; i < rows; ++i)
        {
            if (i == 1) 
            { 
                std::cout << padding_window << '|';
                for (size_t i = 0; i < counter_spaces / 4; ++i)
                    std::cout << ' ';
                std::cout << header;
                for (size_t i = 0; (columns % 2 == 0) ? i < counter_spaces / 4 - 1: i < counter_spaces / 4; ++i)
                    std::cout << ' ';
                std::cout << '|' << std::endl;

                continue;
            }
            for (size_t j = 0; j < columns; ++j)
            {
                if (i > 0 && i < (rows - 1) && i != 2)
                {
                    if (!j)
                        std::cout << padding_window << '|';
                    else if (j == (columns - 1))
                        std::cout << '|';
                    else if (i > 1 && i < (rows - 2))
                    {
                        std::cout << padding << index + 1 << '.' << menu_items[index];
                        for (size_t i = menu_items[index].length() + padding.length() + std::to_string(index + 1).length(); i < columns - 3; ++i)
                            std::cout << ' ';
                        std::cout << '|';
                        if (index < menu_items.size() - 1)
                            ++index;
                        else
                            index = max;
                        break;
                    }
                    else
                        std::cout << ' ';
                }
                else
                {
                    if (!j || j == (columns - 1))
                    {
                        if (!j)
                            std::cout << padding_window << '+';
                        else
                            std::cout << '+';
                    }
                    else
                        std::cout << '-';
                }
            }
            std::cout << std::endl;
        }

        std::cout << padding_window << "select a menu item: ";
        std::cin >> choise;

        this->get_window().close();

        switch (choise)
        {
            case 1:
                this->input();
                break;
            case 2:
                std::cout << this->module();
                system("pause");
                break;
            case 3:
                vector_second.input();
                result = this->scalar_product(vector_second);
                std::cout << "first vector coordinates x: " << this->get_x() << " y: " << this->get_y() << " z: " << this->get_z() << std::endl;
                std::cout << "second vector coordinates x: " << vector_second.get_x() << " y: " << vector_second.get_y() << " z: " << vector_second.get_z() << std::endl;
                std::cout << "scalar product of two vectors: " << result << std::endl;
                system("pause");
                break;
            case 4:
                vector_second.input();
                if (this->collinearity(vector_second))
                    std::cout << "vectors are collinear" << std::endl;
                else
                    std::cout << "the vectors are not collinear" << std::endl;
                system("pause");
                break;
            case 5:
                vector_second.input();
                if (this->orthogonality(vector_second))
                    std::cout << "vectors are orthogonal" << std::endl;
                else
                    std::cout << "the vectors are not orthogonal" << std::endl;
                system("pause");
                break;
            case 6:
                vector_result = this->normalize();
                std::cout << "new vector coordinates x: " << vector_result.get_x() << " y: " << vector_result.get_y() << " z: " << vector_result.get_z() << std::endl;
                system("pause");
                break;
            case 7:
                vector_second.input();
                vector_result = *this + vector_second;
                std::cout << "result addition two vectors x: " << vector_result.get_x() << " y: " << vector_result.get_y() << " z: " << vector_result.get_z() << std::endl;
                system("pause");
                break;
            case 8:
                vector_second.input();
                vector_result = *this - vector_second;
                std::cout << "result difference two vectors x: " << vector_result.get_x() << " y: " << vector_result.get_y() << " z: " << vector_result.get_z() << std::endl;
                system("pause");
                break;
            case 9:
                vector_second.input();
                vector_result = *this * vector_second;
                std::cout << "result addition two vectors x: " << vector_result.get_x() << " y: " << vector_result.get_y() << " z: " << vector_result.get_z() << std::endl;
                system("pause");
                break;
            case 10:
                ++(*this);
                std::cout << "result prefix increment vector x: " << this->get_x() << " y: " << this->get_y() << " z: " << this->get_z() << std::endl;
                system("pause");
                break;
            case 11:
                --(*this);
                std::cout << "result prefix decrement vector x: " << this->get_x() << " y: " << this->get_y() << " z: " << this->get_z() << std::endl;
                system("pause");
                break;
            case 12:
                std::cout << *this << std::endl;
                system("pause");
                break;
            case 13:
                this->get_window().open();
                this->get_window().display(get_x(), get_y(), get_z());
                break;
            case 14:
                choise = menu_items.size();
                break;
            default:
                std::cout << "select the correct menu item" << std::endl;
                system("pause");
                break;
        }
    } while (choise != menu_items.size());
}
// data entry function
bool vector::input()
{
    bool stop = 0;

    std::string value = "";

    do
    {
        system("cls");
        stop = 0;
        // entering the x-coordinate
        std::cout << "enter x coordinate: ";
        std::getline(std::cin, value, '\n');

        if (atof(value.c_str()))
        {
            x = atof(value.c_str());
            stop = 1;
        }
        else if (value.length() == 1 && value[0] == '0')
        {
            x = 0;
            stop = 1;
        }
        else
            std::cout << "Data Entry Error !!!" << std::endl;
    } while (!stop);
    // ########################## //
    do
    {
        stop = 0;
        // entering the y coordinate
        std::cout << "enter y coordinate: ";
        // std::cin.ignore();
        std::getline(std::cin, value, '\n');

        if (atof(value.c_str()))
        {
            y = atof(value.c_str());
            stop = 1;
        }
        else if (value.length() == 1 && value[0] == '0')
        {
            y = 0;
            stop = 1;
        }
        else
            std::cout << "Data Entry Error !!!" << std::endl;
    } while (!stop);
    // ########################## //
    do
    {
        stop = 0;
        // entering the z coordinate
        std::cout << "enter z coordinate: ";
        // std::cin.ignore();
        std::getline(std::cin, value, '\n');

        if (atof(value.c_str()))
        {
            z = atof(value.c_str());
            stop = 1;
        }
        else if (value.length() == 1 && value[0] == '0')
        {
            z = 0;
            stop = 1;
        }
        else
            std::cout << "Data Entry Error !!!" << std::endl;
    } while (!stop);
    // ########################## //

    set_x(x);
    set_y(y);
    set_z(z);

    set_plane().filling(get_x(), get_y(), get_z());
    set_plane().drawing_point(get_x(), get_y(), get_z());

    return true;
}
// function output graphic mode coordinate plane
bool vector::output(double X, double Y, double Z)
{
    window.display(X, Y, Z);

    return true;
}
// function for finding the length of a vector
double vector::module() const
{
    double length = 0;

    length = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));

    return length;
}
// function scalar product
double vector::scalar_product(const vector& vector_second) const
{
    double scalar_product = 0;

    scalar_product = this->x * vector_second.x + this->y * vector_second.y + this->z * vector_second.z;

    return scalar_product;
}
// function collinearity vector
bool vector::collinearity(const vector& vector_second) const
{
    double componenta_x = this->y * vector_second.z - this->z * vector_second.y;
    double componenta_y = this->z * vector_second.x - this->x * vector_second.z;
    double componenta_z = this->x * vector_second.y - this->y * vector_second.x;

    return (abs(componenta_x) < 1e-9 && abs(componenta_y) < 1e-9 && abs(componenta_z) < 1e-9);
}
//function orthogonality vector
bool vector::orthogonality(const vector& vector_second) const
{
    double result = 0;

    result = this->x * vector_second.x + this->y * vector_second.y + this->z * vector_second.z;

    if (abs(result) < 1e-9)
        return true;
    else
        return false;
}
// function normalize vector
vector vector::normalize() const
{
    vector vector_r;

    if (this->module() < 1e-9)
        return vector{ 0,0,0 };

    vector_r.x = this->x / this->module();
    vector_r.y = this->y / this->module();
    vector_r.z = this->z / this->module();

    return vector_r;
}
// function addition two vectors
vector vector::operator+(const vector& vector_second) const
{
    vector vector_result;

    vector_result.x = this->x + vector_second.x;
    vector_result.y = this->y + vector_second.y;
    vector_result.z = this->z + vector_second.z;

    return vector_result;
}
// function subtraction two vectors
vector vector::operator-(const vector& vector_second) const
{
    vector vector_result;

    vector_result.x = this->x - vector_second.x;
    vector_result.y = this->y - vector_second.y;
    vector_result.z = this->z - vector_second.z;

    return vector_result;
}
// function postfix increment overloading
vector vector::operator++(int)
{
    vector vector_r;

    vector_r = *this;

    if (this->module() > 1e-9)
    {
        this->x = this->x + this->x / this->module();
        this->y = this->y + this->y / this->module();
        this->z = this->z + this->z / this->module();
    }

    return vector_r;
}
// function prefix increment overloading
vector& vector::operator++()
{
    if (this->module() > 1e-9)
    {
        this->x = this->x + this->x / this->module();
        this->y = this->y + this->y / this->module();
        this->z = this->z + this->z / this->module();
    }

    return *this;
}
// function postfix decrement overloading
vector vector::operator--(int)
{
    vector vector_r;

    vector_r = *this;

    if (this->module() > 1e-9)
    {
        this->x = this->x - this->x / this->module();
        this->y = this->y - this->y / this->module();
        this->z = this->z - this->z / this->module();
    }

    return vector_r;
}
// function prefix decrement overloading
vector& vector::operator--()
{
    if (this->module() > 1e-9)
    {
        this->x = this->x - this->x / this->module();
        this->y = this->y - this->y / this->module();
        this->z = this->z - this->z / this->module();
    }

    return *this;
}
// function vector product
vector vector::operator*(const vector& vector_second) const
{
    const unsigned int strings = 2;
    const unsigned int columns = 3;

    double matrix_determinant[strings][columns];

    vector vector_result;

    for (size_t i = 0; i < strings; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            if (!i) matrix_determinant[i][j] = *(&(this->x) + j);
            else if (i) matrix_determinant[i][j] = *(&(vector_second.x) + j);
        }
    }

    vector_result.x = matrix_determinant[0][1] * matrix_determinant[1][2]
                    - matrix_determinant[0][2] * matrix_determinant[1][1];

    vector_result.y =  -(matrix_determinant[0][0] * matrix_determinant[1][2]
                       - matrix_determinant[0][2] * matrix_determinant[1][0]);

    vector_result.z = matrix_determinant[0][0] * matrix_determinant[1][1]
                    - matrix_determinant[0][1] * matrix_determinant[1][0];

    return vector_result;
}
// function vector number multiplication
vector vector::operator*(const double value) const
{
    vector vector_r;

    vector_r.x = this->x * value;
    vector_r.y = this->y * value;
    vector_r.z = this->z * value;

    return vector_r;
}
// overloading operator=
vector& vector::operator=(const vector& vector_second)
{
    if (this == &vector_second)
        return *this;

    this->x = vector_second.x;
    this->y = vector_second.y;
    this->z = vector_second.z;

    return *this;
}
// overloading operator==
bool vector::operator==(const vector& vector_second) const
{
    if (this->x == vector_second.x && this->y == vector_second.y && this->z == vector_second.z)
        return true;
    return false;
}
// overloading operator!=
bool vector::operator!=(const vector& vector_second) const
{
    if (this->x != vector_second.x || this->y != vector_second.y || this->z != vector_second.z)
        return true;
    return false;
}
// overload input
std::istream& operator>>(std::istream& input_stream, vector& _vector)
{
    double x = 0;
    double y = 0;
    double z = 0;

    bool stop = 0;

    std::string value = "";

    do
    {
        stop = 0;
        // entering the x-coordinate
        std::cout << "enter x coordinate: ";
        std::getline(input_stream, value, '\n');

        if (atof(value.c_str()))
        {
            x = atof(value.c_str());
            stop = 1;
        }
        else if (value.length() == 1 && value[0] == '0')
        {
            x = 0;
            stop = 1;
        }
        else
            std::cout << "Data Entry Error !!!" << std::endl;
    } while (!stop);
    // ########################## //
    do
    {
        stop = 0;
        // entering the y coordinate
        std::cout << "enter y coordinate: ";
        // std::cin.ignore();
        std::getline(input_stream, value, '\n');

        if (atof(value.c_str()))
        {
            y = atof(value.c_str());
            stop = 1;
        }
        else if (value.length() == 1 && value[0] == '0')
        {
            y = 0;
            stop = 1;
        }
        else
            std::cout << "Data Entry Error !!!" << std::endl;
    } while (!stop);
    // ########################## //
    do
    {
        stop = 0;
        // entering the z coordinate
        std::cout << "enter z coordinate: ";
        // std::cin.ignore();
        std::getline(input_stream, value, '\n');

        if (atof(value.c_str()))
        {
            z = atof(value.c_str());
            stop = 1;
        }
        else if (value.length() == 1 && value[0] == '0')
        {
            z = 0;
            stop = 1;
        }
        else
            std::cout << "Data Entry Error !!!" << std::endl;
    } while (!stop);
    // ########################## //

    _vector.set_x(x);
    _vector.set_y(y);
    _vector.set_z(z);

    _vector.set_plane().filling(_vector.get_x(), _vector.get_y(), _vector.get_z());
    _vector.set_plane().drawing_point(_vector.get_x(), _vector.get_y(), _vector.get_z());

    return input_stream;
}
// overload output
std::ostream& operator<<(std::ostream& output_stream, vector& _vector)
{
    _vector.get_plane().output();

    return output_stream;
}

//for (size_t i = 0; i < rows; ++i)
//{
//    for (size_t j = 0; j < columns; ++j)
//    {
//        if (i > 0 && i < (rows - 1))
//        {
//            if (!j || j == (columns - 1))
//                std::cout << '|';
//            else if (i > 1 && i < (rows - 2))
//            {
//                std::cout << padding << index + 1 << '.' << menu_items[index];
//                for (size_t i = menu_items[index].length() + padding.length() + std::to_string(index + 1).length(); i < columns - 3; ++i)
//                    std::cout << ' ';
//                std::cout << '|';
//                ++index;
//                break;
//            }
//            else
//                std::cout << ' ';
//        }
//        else
//        {
//            if (!j || j == (columns - 1))
//                std::cout << '+';
//            else
//                std::cout << '-';
//        }
//    }
//    std::cout << std::endl;
//}

//if ((!i && (!j || j == (columns - 1))) || (!i && j == (columns - 1)) || (i == (rows - 1) && (!j || j == (columns - 1))))
//    std::cout << '+';
//else if (!i && (j > 0 && j < (columns - 2)))
//    std::cout << '-';
//else if(



//std::cout << menu_items[index].length() << '\t' << columns << std::endl; system("pause");
//std::cout << menu_items[index].length() + padding.length() + std::to_string(index).length() << std::endl; system("pause");