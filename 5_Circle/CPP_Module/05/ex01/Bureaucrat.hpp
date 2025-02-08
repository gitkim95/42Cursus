/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:43:18 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 14:52:44 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class	Form;

class	Bureaucrat
{
private:
	std::string const	name;
	int					grade;
public:
	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat& other );
	~Bureaucrat( void );

	Bureaucrat&				operator=( const Bureaucrat& other );

	void		increaseGrade( void );
	void		decreaseGrade( void );
	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		signForm( Form& form );
	
	class	GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};
std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat );

#endif