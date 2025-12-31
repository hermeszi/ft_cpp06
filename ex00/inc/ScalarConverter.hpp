/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/12/31 16:05:24 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>


class ScalarConverter
{
    enum Type_ { 
        CHAR, 
        INT, 
        FLOAT, 
        DOUBLE, 
        SPECIAL_FLOAT,  // nanf, +inff, -inff
        SPECIAL_DOUBLE,  // nan, +inf, -inf
        INVALID
    };

    ScalarConverter() {};
    ScalarConverter(const ScalarConverter &);
    ~ScalarConverter() {};

    ScalarConverter & operator=(const ScalarConverter &);
    
    static Type_ detechType(const std::string & input);
    
public:
    static void convert(const std::string & input);
};


#endif
