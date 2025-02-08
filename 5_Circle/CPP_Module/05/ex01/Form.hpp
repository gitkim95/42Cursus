/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:06:12 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 14:53:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <stdexcept>
# include <string>

class	Bureaucrat;

class	Form
{
private:
	std::string const	name;
	bool				sign;
	int const			signGrade;
	int const			executeGrade;
public:
	Form( void );
	Form( std::string name, int signGrade, int executeGrade );
	Form( const Form& other );
	~Form( void );

	Form&	operator=( const Form& other );

	std::string	getName( void ) const;
	int			getSignGrade( void ) const;
	int			getExecuteGrade( void ) const;
	std::string	getSignStatus( void ) const;
	void		beSigned( Bureaucrat& bureaucrat );

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
std::ostream&	operator<<( std::ostream& out, const Form& Form );

#endif