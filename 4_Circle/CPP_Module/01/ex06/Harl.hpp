/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:24:58 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/31 19:10:02 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
private:
	std::string	levels[4];
	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );
	void		(Harl::*funcPointer[4])( void );
public:
	Harl();

	void	 	complain( std::string input );
};

#endif