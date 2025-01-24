/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:20:19 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/24 23:49:03 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate( void )
{
	Base *base;

	std::srand(std::time(0));
	int randomValue = std::rand() % 3;
	if (randomValue == 0)
	{
		base = new A();
	}
	else if (randomValue == 1)
	{
		base = new B();
	}
	else
	{
		base = new C();
	}
	return (base);
}

void	identify( Base *p )
{
	A *a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "A" << std::endl;

	B *b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "B" << std::endl;

	C *c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "C" << std::endl;
}

void	identify( Base &p )
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception &e)	{}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception &e)	{}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::exception &e)	{}
}
