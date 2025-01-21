/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:20:19 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/22 00:22:53 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreation", 145, 137, "none") {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreation", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void	ShrubberyCreationForm::execute( Bureaucrat const& executor ) const
{
	if (executor.getGrade() <= this->getExecuteGrade())
		this->action();
	else
		throw (AForm::GradeTooLowException());
}

void	ShrubberyCreationForm::action( void ) const
{
	std::ofstream	file(this->getTarget().append("_shrubbery").c_str());

	file	<< "ASCII Table\n"
			<< std::setw(8) << "Decimal|"
			<< std::setw(8) << "Hex|"
			<< std::setw(8) << "Char|" << std::endl;
	for (int i = 0; i < 128; ++i)
	{
		file	<< std::setw(7) << i << "|"
				<< std::hex << std::uppercase << std::setw(7) << i << "|"
				<< std::dec;
		if (std::isprint(i))
			file << std::setw(7) << static_cast<char>(i) << "|";
		else
			file << std::setw(8) << "|";
		file << std::endl;
	}
	file.close();
	std::cout	<< "ASCII Table written to "
				<< this->getTarget()
				<< "_shrubbery file" << std::endl;
}
