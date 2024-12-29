/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:14:39 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/29 20:50:31 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon();
		Weapon( std::string type );
		~Weapon();

		const std::string&	getType() const;
		void				setType( std::string& str );
};

#endif