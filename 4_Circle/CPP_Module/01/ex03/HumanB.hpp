/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:15:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/29 20:57:29 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		weapon;
		std::string	name;
	public:
		HumanB( std::string& name );
		~HumanB();

		void	attack();
		void	setWeapon( std::string newWeapon );
};

#endif