/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2026/01/09 21:25:51 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iostream>
#include <typeinfo>
#include <ctime>
#include <cstdlib>

Base* generate(void)
{
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    switch (std::rand() % 3)
    {
        case 0: 
            {
                std::cout << " A is chosen" << std::endl;
                return new A();
            }
        case 1:
            {
                std::cout << " B is chosen" << std::endl;
                return new B();
            }
        default:
        {
            std::cout << " C is chosen" << std::endl;
            return new C();
        }
    }
}

void identify(Base* p)
{
    std::cout << "identify --> ";
    if (dynamic_cast<A*>(p))
        std::cout << "A";
    else if (dynamic_cast<B*>(p))
        std::cout << "B";
    else if (dynamic_cast<C*>(p))
        std::cout << "C";
    else
        std::cout << "Others";
    std::cout << std::endl;
    return ;
}

void identify(Base& p)
{
    std::cout << "identify --> ";
    try
    {
        (void) dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::bad_cast &){}
    try
    {
        (void) dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ; 
    }
    catch(const std::bad_cast &){}
    try
    {
        (void) dynamic_cast<C&>(p);
        std::cout << "C" << std::endl; 
        return ; 
    }
    catch(const std::bad_cast &){}
    std::cout << "Other" << std::endl;
}

static void test()
{
    Base* ptr = generate();  // Returns A, B, or C randomly
    
    std::cout << "===== Pass to identify(ptr) =====" << std::endl;
    identify(ptr);

    std::cout << "\n===== Pass to identify(ref) =====" << std::endl;
    identify(*ptr);
    
    delete ptr;

}
int main()
{
    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << "======================================" << std::endl;
        std::cout << "\tTest " << i + 1 << std::endl;
        test();
        std::cout << "======================================" << std::endl;
    }
    return 0;
}
