/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2026/01/09 21:19:05 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>

struct Base
{
    virtual ~Base() {std::cout << "Base destructor" << std::endl;};
};

struct A : public Base
{
    ~A() {std::cout << "A destructor" << std::endl;};
};

struct B : public Base
{
    ~B() {std::cout << "B destructor" << std::endl;};
};

struct C : public Base
{
    ~C() {std::cout << "C destructor" << std::endl;};
};

#endif
