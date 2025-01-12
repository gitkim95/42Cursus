/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 02:59:56 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 18:18:08 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal( void ) : type("nonamed")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal( const Animal& other )
{
	type = other.type;
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal&	Animal::operator=( const Animal& other )
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const Animal& Animal )
{
	out	<< Animal.type << std::endl;
	return (out);
}

void	Animal::makeSound( void ) const
{
	std::cout << "Silent..." << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (type);
}