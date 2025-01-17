/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:00:52 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/17 18:21:37 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("unnamed"), grade(0) {}

Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name), grade(grade) {}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat( void ) {}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat )
{
	out	<< bureaucrat.name
		<< ", bureaucrat grade "
		<< bureaucrat.grade << std::endl;
	return (out);
}

void	Bureaucrat::increaseGrade( void )
{
	this->grade--;
}

void	Bureaucrat::decreaseGrade( void )
{
	this->grade++;
}

std::string	Bureaucrat::getName( void ) const
{
	return (name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (grade);
}
