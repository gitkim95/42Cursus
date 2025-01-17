/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:06:12 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/17 23:13:28 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <stdexcept>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
private:
	std::string const	name;
	bool				sign;
	int const			requiredSignGrade;
	int const			requiredExecuteGrade;
public:
	Form( void );
	Form( std::string name, int grade );
	Form( const Form& other );
	~Form( void );

	Form&					operator=( const Form& other );
	friend std::ostream&	operator<<( std::ostream& out, const Form& Form );

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		beSigned( Bureaucrat& bureaucrat );
	void		signForm( void );

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