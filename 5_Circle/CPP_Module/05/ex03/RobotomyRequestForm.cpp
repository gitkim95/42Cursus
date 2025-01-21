/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:22:01 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/21 20:10:16 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequest", 72, 45, "none") {}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequest", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void	RobotomyRequestForm::execute( Bureaucrat const& executor ) const
{
	if (executor.getGrade() <= this->getExecuteGrade())
		this->action();
	else
		throw (AForm::GradeTooLowException());
}

void	RobotomyRequestForm::action( void ) const
{
	std::cout << "vrrrr!!" << std::endl;

	std::srand(std::time(0));
	int	randomValue = std::rand() % 2;
	if (randomValue == 0)
	{
		std::cout	<< this->getTarget()
					<< " has been robotized successfully!" << std::endl;
	}
	else
	{
		std::cout	<< this->getTarget()
					<< " has failed to be robotized!" << std::endl;
	}
}
