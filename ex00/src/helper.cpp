
#include "helper.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cerrno>

using std::cout;
using std::endl;

void printInt(double value)
{
    cout << "int: ";
    
    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
    {
        cout << static_cast<int>(value);
    }
    else
    {
        cout << "Non displayable";
    }
    cout << endl;
}
void printFloat(double value)
{
    cout << "float: ";
    
    if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())
    {
        if (static_cast<int>(value) == value) // whole num
            cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f";
        else
            cout << std::fixed << static_cast<float> (value) << "f";
    }
    else
    {
        cout << "Non displayable";
    }
    cout << endl;
}

void printDouble(double value)
{
    cout << "double: ";
    
    if (value >= -std::numeric_limits<double>::max() && value <= std::numeric_limits<double>::max())
    {
        if (static_cast<int>(value) == value) // whole num
            cout << std::fixed << std::setprecision(1) << value;
        else
            cout << std::fixed << value;
    }
    else
    {
        cout << "Non displayable";
    }
    cout << endl;
}

void printChar(double value)
{
    cout << "char: ";
    
    if (value > std::numeric_limits<char>::max() || 
        value < std::numeric_limits<char>::min())
        {
            cout << "impossible";
        }

    else if (value < 33 || value > 126)
    {
        cout << "Non displayable";
    }
    else
    {
        cout << "'" <<static_cast<char>(value) << "'";
    }
    cout << endl;
}
int convertInt(const std::string & str)
{
    char* endptr;

    errno = 0;
    long l = strtol(str.c_str(), &endptr, 10);

    if (endptr == str.c_str() || *endptr != '\0')
    {
        throw std::invalid_argument("Error: no conversion or extra characters");
    }

    if (errno == ERANGE || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
    {
        throw std::out_of_range("value out of int range");
    }

    return static_cast<int>(l);
}

float convertFloat(const std::string & str)
{
    char* endptr;
    errno = 0;
    std::string temp(str);
    temp.erase(temp.length()-1);
    float d = strtof(temp.c_str(), &endptr);

    if (endptr == temp.c_str() || *endptr != '\0')
    {
        throw std::invalid_argument("Error: no conversion or extra characters");
    }

    if (errno == ERANGE || d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
    {
        throw std::out_of_range("value out of float range");
    }

    return (d);
}

double convertDouble(const std::string & str)
{
    char* endptr;
    errno = 0;
    double d = strtod(str.c_str(), &endptr);

    if (endptr == str.c_str() || *endptr != '\0')
    {
        throw std::invalid_argument("Error: no conversion or extra characters");
    }

    if (errno == ERANGE || d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
    {
        throw std::out_of_range("value out of double range");
    }

    return (d);
}
