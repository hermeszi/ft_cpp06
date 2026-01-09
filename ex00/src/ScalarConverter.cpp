/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2026/01/09 18:19:17 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cerrno>
#include "ScalarConverter.hpp"
#include "helper.hpp"

using std::endl;
using std::cout;

ScalarConverter::ScalarConverter(const ScalarConverter & other)
{
    if (this != &other)
        operator=(other);
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & other)
{
    (void) other;
    return *this;
}

static size_t countDecimal(const std::string & str)
{
    size_t count = 0;
    if (str.empty())
        return 0;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str.at(i) == '.')
        {
            ++count;
        }
    }
    return count;
}

static bool validNumber(const std::string & str)
{
    if (str.empty())
    {
        return false;
    }

    bool hasDigit = false;
    bool hasCorrectDecimal = (countDecimal(str) < 2);
        
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str.at(i) == '.')
            ;
        else if (str.at(i) >= '0' && str.at(i) <= '9' )
            hasDigit = true;
        else
            return false;      
    }
    
    return (hasDigit && hasCorrectDecimal);
}


ScalarConverter::Type_ ScalarConverter::detechType(const std::string & input)
{
    if (input.empty())
        return INVALID;
        
    //detech char and special f and d
    if (input.length() == 3 && input.at(0) == '\'' && input.at(2) == '\'')
        return CHAR;
    else if (input == "nanf" || input == "+inff" || input == "-inff")
        return SPECIAL_FLOAT;
    else if (input == "nan" || input == "+inf" || input == "-inf")
        return SPECIAL_DOUBLE;

    //check for Sign and f and .
    bool hasF = false;
    bool hasDecimal = false;
    bool hasSign = false;

    std::string temp(input);
    if (temp.at(0) == '-' || temp.at(0) == '+')
    {
        hasSign = true;
        temp.erase(0,1);
    }
    if (temp.empty())
        return INVALID;
    if (temp.at(temp.length()-1) == 'f')
    {
        hasF = true;
        temp.erase(temp.length()-1, 1);
    }
    if (temp.empty())
        return INVALID;
    
    //check if num is valid 
    hasDecimal = (countDecimal(temp) > 0);  
    if (validNumber(temp))
    {
        if (hasF)
            return FLOAT;
        else if (hasDecimal)
            return DOUBLE;
        else
            return INT;
    }
    return INVALID;   
}


void ScalarConverter::convert(const std::string & input)
{
    //std::cout << "Input received: [" << input << "] length: " << input.length() << std::endl;
    
    ScalarConverter::Type_ type = detechType(input);
    
    if (type == INVALID)
    {
        cout << "Invalid Input" << endl;
        return ;
    }
    else if (type == SPECIAL_FLOAT)
    {
        //cout << "-- TYPE deteched: Special Float --" << endl;
        try
        {
            cout << "char: impossible" << endl;
            cout << "int: impossible" << endl;
            cout << "float: " << input << endl;
            std::string temp(input);
            //temp.pop_back();
            temp.erase(temp.length()-1);
            cout << "double:" << temp << endl;          
        }
        catch(const std::out_of_range & e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "float value must be between " << -std::numeric_limits<float>::max() << " to " << std::numeric_limits<float>::max() << "." << endl;
        }
    }
    else if (type == SPECIAL_DOUBLE)
    {
        //cout << "-- TYPE detected: Special Double --" << endl;
        try
        {
            cout << "char: impossible" << endl;
            cout << "int: impossible" << endl;
            cout << "float: " << input << "f" <<endl;
            cout << "double:" << input << endl;          
        }
        catch(const std::exception & e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "double value must be between " << -std::numeric_limits<double>::max() << " to " << std::numeric_limits<double>::max() << "." << endl;
        }
    }
    else if (type == INT)
    {
        //cout << "-- TYPE deteched: INT --" << endl;
        try
        {
            int value = convertInt(input); // Convert to INT first
            printChar(static_cast<double> (value));
            printInt(static_cast<double> (value));
            printFloat(static_cast<double> (value));
            printDouble(static_cast<double> (value));
        }
        catch(const std::exception & e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "int value must be between " << std::numeric_limits<int>::min() << " to " << std::numeric_limits<int>::max() << "." << endl;
        }
    }
    else if (type == FLOAT)
    {
        //cout << "-- TYPE deteched: FLOAT --" << endl;
        try
        {
            float value = convertFloat(input); // Convert to FLOAT first
            printChar(static_cast<double> (value));
            printInt(static_cast<double> (value));
            printFloat(static_cast<double> (value));
            printDouble(static_cast<double> (value));            
        }
        catch(const std::exception & e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "float value must be between " << -std::numeric_limits<float>::max() << " to " << std::numeric_limits<float>::max() << "." << endl;
        }
    }
    else if (type == DOUBLE)
    {
        //cout << "-- TYPE deteched: DOUBLE --" << endl;
        try
        {
            double value = convertDouble(input); //Convert to DOUBLE first
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);            
        }
        catch(const std::exception & e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "double value must be between " << -std::numeric_limits<double>::max() << " to " << std::numeric_limits<double>::max()<< "." << endl;
        }
    }
    else if (type == CHAR)
    {
        //cout << "-- TYPE deteched: CHAR --" << endl;
        try
        {
            char value = input.at(1); // get CHAR
            printChar(static_cast<double> (value));
            printInt(static_cast<double> (value));
            printFloat(static_cast<double> (value));
            printDouble(static_cast<double> (value));            
        }
        catch(const std::exception & e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "char value must be between 33 to 126." << endl;
        }
    }
    
}
