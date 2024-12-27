/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:26:17 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 20:28:43 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

int	main()
{
	Zombie*	foo;
	
	foo = Zombie::newZombie("Foo");
	Zombie::randomChump("gitkim");
	
	delete foo;
	return (0);
}
