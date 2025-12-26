/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/12/26 17:21:23 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

using std::string;
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

void ScalarConverter::convert(const std::string & input)
{
    
}
