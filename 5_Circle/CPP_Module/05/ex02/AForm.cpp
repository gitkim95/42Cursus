/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:13:50 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/20 17:38:45 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ) : name("unnamed"), sign(false), signGrade(1), executeGrade(1), target("none") {}

AForm::AForm( std::string name, int signGrade, int executeGrade, std::string target )
: name(name), sign(false), signGrade(signGrade), executeGrade(executeGrade), target(target)
{
	if (executeGrade < 1 || signGrade < 1)
		throw (GradeTooHighException());
	if (executeGrade > 150 || signGrade > 150)
		throw (GradeTooLowException());
}

AForm::AForm( const AForm& other )
: name(other.name), sign(other.sign), signGrade(other.signGrade), executeGrade(other.executeGrade), target(other.target) {}

AForm::~AForm( void ) {}

AForm&	AForm::operator=( const AForm& other )
{
	if (this != &other)
	{
		const_cast<std::string&>(name) = other.name;
		sign = other.sign;
		const_cast<int&>(signGrade) = other.signGrade;
		const_cast<int&>(executeGrade) = other.executeGrade;
		const_cast<std::string&>(target) = other.target;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const AForm& form )
{
	out	<< form.getName()
		<< ", form grade required to sign "
		<< form.getSignGrade()
		<< ", form grade required to execute " 
		<< form.getExecuteGrade()
		<< ", the sign status of the form is "
		<< form.getSignStatus()
		<< ", form's target is "
		<< form.getTarget() << std::endl;
	return (out);
}

std::string	AForm::getName( void ) const
{
	return (name);
}

int	AForm::getSignGrade( void ) const
{
	return (signGrade);
}

int	AForm::getExecuteGrade( void ) const
{
	return (executeGrade);
}

std::string	AForm::getSignStatus( void ) const
{
	if (sign)
		return ("true");
	else
		return ("false");
}

std::string	AForm::getTarget( void ) const
{
	return (target);
}

void	AForm::beSigned( Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() <= signGrade)
		sign = true;
	else
		throw (GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}
