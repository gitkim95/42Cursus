/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:15:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 22:55:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

#include <iostream>

class HumanB
{
	private:
		Weapon		weapon;
		std::string	name;
	public:
		HumanB(/* args */);
		~HumanB();

		
};

#endif