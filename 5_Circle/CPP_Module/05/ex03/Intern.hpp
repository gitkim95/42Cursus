/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:18:45 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/21 23:05:40 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
private:
	std::string	formNames[3];
	AForm*	createPresidentialPardonForm( std::string target );
	AForm*	createRobotomyRequestForm( std::string target );
	AForm*	createShrubberyCreationForm( std::string target );
	AForm*	(Intern::*createFormPointer[3])( std::string target );
public:
	Intern( void );
	Intern( const Intern& other );
	~Intern( void );

	Intern&	operator=( const Intern& other );

	AForm*	makeForm( std::string name, std::string target );
};

#endif