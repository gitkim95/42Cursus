/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:13:50 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/18 17:46:32 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

Form::Form( void ) : name("unnamed"), sign(false), signGrade(1), executeGrade(1) {}

Form::Form( std::string name, int signGrade, int executeGrade ) : name(name), sign(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (executeGrade < 1 || signGrade < 1)
		throw (GradeTooHighException());
	if (executeGrade > 150 || signGrade > 150)
		throw (GradeTooLowException());
}

Form::Form( const Form& other ) : name(other.name), sign(other.sign), signGrade(other.signGrade), executeGrade(other.executeGrade) {}

Form::~Form( void ) {}

Form&	Form::operator=( const Form& other )
{
	if (this != &other)
	{
		const_cast<std::string&>(name) = other.name;
		sign = other.sign;
		const_cast<int&>(signGrade) = other.signGrade;
		const_cast<int&>(executeGrade) = other.executeGrade;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const Form& form )
{
	out	<< form.name
		<< ", form grade required to sign "
		<< form.signGrade
		<< ", form grade required to execute " 
		<< form.executeGrade << std::endl;
	return (out);
}

std::string	Form::getName( void ) const
{
	return (name);
}

int	Form::getSignGrade( void ) const
{
	return (signGrade);
}

int	Form::getExecuteGrade( void ) const
{
	return (executeGrade);
}

void	Form::beSigned( Bureaucrat& bureaucrat )
{

}

void	Form::signForm( void )
{

}


const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}
