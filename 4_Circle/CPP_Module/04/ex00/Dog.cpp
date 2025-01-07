/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:28:32 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 03:40:55 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog( void ) : Animal()
{
	type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog( std::string type ) : Animal(type)
{
	type = "Dog";
	std::cout << "Dog parameterized constructor called for: " << type << std::endl;
}

Dog::Dog( const Dog& other ) : Animal(other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const Dog& Dog )
{
	out	<< Dog.type << std::endl;
	return (out);
}
