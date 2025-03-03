/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:09:14 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/03 23:29:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>

class Warlock
{
private:
	std::string	name;
	std::string title;
	
	Warlock( void );
	Warlock( const Warlock& other );
	Warlock& operator=( const Warlock& other );
public:
	Warlock( std::string name, std::string title );
	~Warlock();

	std::string const&	getName( void ) const;
	std::string const&	getTitle( void ) const;
	void				setTitle( std::string const& newTitle );

	void				introduce() const;
};

#endif