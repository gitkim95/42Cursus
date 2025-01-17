/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:43:18 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/17 22:52:22 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

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