/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:09:29 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 19:21:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
	void			announce( void );
	static Zombie*	newZombie( std::string name );
	static void		randomChump( std::string name );

	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );

	private:
	std::string	name;
};

#endif