/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:27:15 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 03:41:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat( void ) : Animal()
{
	type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat( std::string type ) : Animal(type)
{
	type = "Cat";
	std::cout << "Cat parameterized constructor called for: " << type << std::endl;
}

Cat::Cat( const Cat& other ) : Animal(other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat&	Cat::operator=( const Cat& other )
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const Cat& Cat )
{
	out	<< Cat.type << std::endl;
	return (out);
}
