/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:14:29 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 18:24:46 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

void	Zombie::randomChump( std::string name )
{
	Zombie* newZombie = new Zombie(name);

	newZombie->announce();
	delete newZombie;
}
