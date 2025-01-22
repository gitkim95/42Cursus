/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:34:44 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/22 20:36:35 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Not enough input" << std::endl;
		return (0);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}