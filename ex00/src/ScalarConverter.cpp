/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/12/31 22:00:37 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

using std::string;
using std::endl;
using std::cout;

ScalarConverter::ScalarConverter() {};

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

static bool hasOneDecimal(const std::string & str)
{
    if (str.empty())
        return false;
    bool hasDecimal = false;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str.at(i) == '.')
        {
            if (hasDecimal == false)
                hasDecimal = true;
            else
                return false;
        }
    }
    return hasDecimal;
}

static bool isValidNum(const std::string & str)
{
    if (str.empty())
        return false;
        
    bool hasDecimal = false;
    bool hasDigit = false;

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str.at(i) == '.')
        {
            if (hasDecimal == false)
                hasDecimal = true;
            else
                return false;
        }
        else if (str.at(i) < 58 && str.at(i) > 47)
            hasDigit = true;
        else
            return false;      
    }
    return hasDigit;
}

Type_ ScalarConverter::detechType(const std::string & input)
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
        
    hasDecimal = hasOneDecimal(temp);
    if (isValidNum(temp))
    {
        if (hasF && hasDecimal)
            return FLOAT;
        else if (hasDecimal)
            return DOUBLE;
        else if (!hasF)
            return INT;
    }
    return INVALID;   
}
static void printInt(int value)
{
    
}

void ScalarConverter::convert(const std::string & input)
{
    Type_ type = detechType(input);
    
    if (type == INVALID)
    {
        cout << "Invalid Input" << endl;
        return ;
    }
    if (type == INT)
    {
        cout << "-- TYPE deteched: INT --" << endl;
        int value = std::stoi(input); // no range test yet
    }
    else if (type == FLOAT)
    {
        cout << "-- TYPE deteched: FLOAT --" << endl;
        float value = std::stof(input); // no range test yet
    }
    else if (type == DOUBLE)
    {
        cout << "-- TYPE deteched: DOUBLE --" << endl;
        float value = std::stod(input); // no range test yet
    }
    else if (type == CHAR)
    {
        cout << "-- TYPE deteched: CHAR --" << endl;
        char value = input.at(1);
    }
    
}
