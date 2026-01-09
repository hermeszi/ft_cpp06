/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2026/01/09 18:40:19 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

Data::Data(int x, int y)
{
	this->x = x;
	this->y = y;
}

Data::Data (const Data & other)
{
	operator=(other);
}

Data & Data::operator=(const Data & rhs)
{
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
	}
	return *this;
}

int & Data::operator[](const int index)
{
	if (index == 0)
		return x;
	//else if (index == 1)
	return y;
	// hmm what to return if else
}

int Data::operator[](const int index) const
{
	if (index == 0)
		return x;
	else if (index == 1)
		return y;
	else
		return 0;
}
	
Data & Data::operator+=(const int num)
{
	x += num;
	y += num;
	return *this;
}

Data & Data::operator-=(const int num)
{
	x -= num;
	y -= num;
	return *this;
}

Data & Data::operator*=(const int num)
{
	x *= num;
	y *= num;
	return *this;
}

Data & Data::operator+=(const Data & rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;	
}

Data & Data::operator-=(const Data & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;	
}

Data & Data::operator*=(const Data & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;	
}

Data & Data::operator--()
{
	--(this->x);
	--this->y;
	return *this;
}

const Data Data::operator--(int)
{
	Data temp(x,y);
	(--x);
	(--y);
	return temp;
}

Data & Data::operator++()
{
	(++x);
	(++y);
	return *this;
}

const Data Data::operator++(int)
{
	Data temp(x,y);
	(++x);
	(++y);
	return temp;
}

std::ostream & operator<<(std::ostream & out, const Data & v)
{
	out << "{"<< v.x << ", " << v.y << "}";
	return out;
}
