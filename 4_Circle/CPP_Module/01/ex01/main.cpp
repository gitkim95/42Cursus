/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:46:40 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 21:58:58 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*	zombieHorde;

	zombieHorde = Zombie::zombieHorde(3, "Foo");
	Zombie::destroyZombie(zombieHorde);
	return (0);
}