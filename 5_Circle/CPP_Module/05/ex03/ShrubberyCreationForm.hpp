/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:02:54 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/21 01:53:19 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string name );
	ShrubberyCreationForm( const ShrubberyCreationForm& other );
	virtual ~ShrubberyCreationForm( void );

	ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& other );

	virtual void	execute( Bureaucrat const& executor ) const;
	virtual void	action( void ) const;
};

#endif