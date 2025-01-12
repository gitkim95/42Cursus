/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 02:59:56 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 23:42:27 by gitkim           ###   ########.fr       */
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
	std::cout << "Animal Copy assignment operator called" << std::endl;
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

std::string	Animal::getType( void ) const
{
	return (type);
}