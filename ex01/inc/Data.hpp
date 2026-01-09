/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2026/01/09 18:41:51 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data
{
	int x;
	int y;

	explicit Data(int x = 0, int y = 0);
	Data (const Data & other);
	
	~Data() {};
	
	Data & operator=(const Data & rhs);
	int & operator[](const int index);
	int operator[](const int index) const;

	Data & operator--();
	const Data operator--(int);

	Data & operator++();
	const Data operator++(int);

	Data & operator+=(const int num);
	Data & operator-=(const int num);
	Data & operator*=(const int num);

	Data & operator+=(const Data & rhs);
	Data & operator-=(const Data & rhs);
	Data & operator*=(const Data & rhs);	
	
};

std::ostream & operator<<(std::ostream & out, const Data & v);

#endif
