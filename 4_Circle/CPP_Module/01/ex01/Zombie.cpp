/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:31:26 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 21:54:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() : name("Unnamed"), nextZombie(NULL) {}

Zombie::Zombie( std::string name ) : name(name), nextZombie(NULL) {}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed." << std::endl;
}
