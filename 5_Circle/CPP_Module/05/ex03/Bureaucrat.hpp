/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:43:18 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/20 16:00:31 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class	AForm;

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
	friend std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat );

	void		increaseGrade( void );
	void		decreaseGrade( void );
	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		signForm( AForm& form );
	void		executeForm( AForm const& form ); 
	
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

#endif