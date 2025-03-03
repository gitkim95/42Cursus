/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:29:05 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/03 21:37:48 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Warlock.hpp"

Warlock::Warlock( std::string name, std::string title ) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

std::string const&	Warlock::getName( void ) const
{
	return (name);
}

std::string const&	Warlock::getTitle( void ) const
{
	return (title);
}

void	Warlock::setTitle( std::string const& newTitle )
{
	title = newTitle;
}

void	Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}
