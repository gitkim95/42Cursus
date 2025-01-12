/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:01:12 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 23:06:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Empty..";
}

Brain::Brain( const Brain& other )
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain&	Brain::operator=( const Brain& other )
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}