/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:25:58 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/22 00:16:11 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void )
{
	formNames[0] = "presidential pardon";
	formNames[1] = "robotomy request";
	formNames[2] = "shrubbery creation";
	createFormPointer[0] = &Intern::createPresidentialPardonForm;
	createFormPointer[1] = &Intern::createRobotomyRequestForm;
	createFormPointer[2] = &Intern::createShrubberyCreationForm;
}

Intern::Intern( const Intern& other )
{
	for (int i = 0; i < 3; i++)
	{
		formNames[i] = other.formNames[i];
		createFormPointer[i] = other.createFormPointer[i];
	}
}

Intern::~Intern( void ) {}

Intern&	Intern::operator=( const Intern& other )
{
	if (this != &other)
	{
		for (int i = 0; i < 3; i++)
		{
			formNames[i] = other.formNames[i];
			createFormPointer[i] = other.createFormPointer[i];
		}
	}
	return (*this);
}

AForm*	Intern::createPresidentialPardonForm( std::string target )
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::createRobotomyRequestForm( std::string target )
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createShrubberyCreationForm( std::string target )
{
	return (new ShrubberyCreationForm(target));
}


AForm*	Intern::makeForm( std::string formName, std::string target )
{

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout	<< "Intern creates "
						<< formName << std::endl;
			return ((this->*createFormPointer[i])(target));
		}
	}

	std::cerr	<< formName
				<< ": No matching form found." << std::endl;
	return (NULL);
}
