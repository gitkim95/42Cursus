/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:22:30 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/21 20:24:01 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardon", 25, 5, "none") {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardon", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void	PresidentialPardonForm::execute( Bureaucrat const& executor ) const
{
	if (executor.getGrade() <= this->getExecuteGrade())
		this->action();
	else
		throw (AForm::GradeTooLowException());
}

void	PresidentialPardonForm::action( void ) const
{
	std::cout	<< this->getTarget()
				<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
