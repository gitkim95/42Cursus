/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:27:18 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 21:51:52 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
	void			announce( void );
	static Zombie*	zombieHorde( int N, std::string name );
	static void		destroyZombie( Zombie* zombie );

	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );

	private:
	std::string	name;
	Zombie*		nextZombie;
};

#endif