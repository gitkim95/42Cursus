/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:06:12 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/20 09:02:50 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <stdexcept>
# include <string>

class	Bureaucrat;

class	AForm
{
private:
	std::string const	name;
	bool				sign;
	int const			signGrade;
	int const			executeGrade;
	std::string const	target;
public:
	AForm( void );
	AForm( std::string name, int signGrade, int executeGrade, std::string target );
	AForm( const AForm& other );
	virtual ~AForm( void );

	AForm&					operator=( const AForm& other );
	friend std::ostream&	operator<<( std::ostream& out, const AForm& AForm );

	std::string		getName( void ) const;
	int				getSignGrade( void ) const;
	int				getExecuteGrade( void ) const;
	std::string		getSignStatus( void ) const;
	std::string		getTarget( void ) const;
	void			beSigned( Bureaucrat& bureaucrat );
	virtual void	execute( Bureaucrat const& executor ) const = 0;
	virtual void	action( void ) const = 0;

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