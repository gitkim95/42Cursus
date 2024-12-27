/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:26:48 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 21:57:58 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

void	Zombie::destroyZombie( Zombie* zombie )
{
	Zombie*	temp;

	while (zombie)
	{
		temp = zombie;
		zombie = zombie->nextZombie;
		delete temp;
	}
}

Zombie*	Zombie::zombieHorde( int N, std::string name )
{
	Zombie*	firstZombie;
	Zombie*	zombieHorde;

	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			zombieHorde = new Zombie(name);
			firstZombie = zombieHorde;
		}
		else
		{
			Zombie* nextZombie = new Zombie(name);
			zombieHorde->nextZombie = nextZombie;
			zombieHorde = nextZombie;
		}
	}
	zombieHorde = firstZombie;
	for (int i = 0; i < N; i++)
	{
		zombieHorde->announce();
		zombieHorde = zombieHorde->nextZombie;
	}
	return (firstZombie);
}
