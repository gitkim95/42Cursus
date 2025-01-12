/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:44:20 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 23:06:50 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("nonamed")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other )
{
	type = other.type;
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& other )
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const WrongAnimal& WrongAnimal )
{
	out	<< WrongAnimal.type << std::endl;
	return (out);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "Beep!" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (type);
}