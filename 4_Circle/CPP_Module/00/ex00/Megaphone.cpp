/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:31:14 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/19 20:56:27 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		int j = 0;
		while (argv[i][j])
		{
			if (97 <= argv[i][j] && argv[i][j] <= 122)
				argv[i][j] -= 32;
			j++;
		}
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return (0);
}
