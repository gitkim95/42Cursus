/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:57:15 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/03 16:26:44 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	gitkim("gitkim");
	ClapTrap	enemy("enemy");

	gitkim.attack(enemy.getName());
	enemy.takeDamage(gitkim.getAttackDamage());
	enemy.beRepaired(5);
	enemy.beRepaired(5);
	enemy.beRepaired(5);
	enemy.beRepaired(5);
	enemy.beRepaired(5);
	enemy.beRepaired(5);
	enemy.beRepaired(5);
	enemy.beRepaired(5);
	enemy.beRepaired(5);
	enemy.beRepaired(5);
	enemy.beRepaired(5);
	std::cout << enemy << std::endl;

	return (0);
}