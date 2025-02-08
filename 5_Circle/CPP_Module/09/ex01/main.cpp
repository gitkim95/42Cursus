/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:28:54 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 21:30:29 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	RPN			calculator;
	std::string	input = av[1];

	try
	{
		int	result = calculator.calculate(input);
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    return (0);
}