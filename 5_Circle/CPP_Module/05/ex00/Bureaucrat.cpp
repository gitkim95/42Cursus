/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:00:52 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/17 23:52:02 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("unnamed"), grade(150) {}

Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name), grade(grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat( void ) {}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this != &other)
	{
		const_cast<std::string&>(name) = other.name;
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
	if (grade - 1 < 1)
		throw (GradeTooHighException());
	this->grade--;
}

void	Bureaucrat::decreaseGrade( void )
{
	if (grade + 1 > 150)
		throw (GradeTooLowException());
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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}
