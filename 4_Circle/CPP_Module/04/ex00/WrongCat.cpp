/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:44:32 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 18:17:51 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=( const WrongCat& other )
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const WrongCat& WrongCat )
{
	out	<< WrongCat.type << std::endl;
	return (out);
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "quack!" << std::endl;
}
