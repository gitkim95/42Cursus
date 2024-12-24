/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:35:53 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/24 22:52:48 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook phonebook;

	while (1)
	{
		std::cin >> input;
		if (!input.compare("ADD"))
			phonebook.add();
		else if (!input.compare("SEARCH"))
			phonebook.search();
		else if (!input.compare("EXIT"))
			break ;
		else
			std::cout << "Invalid command, please try again.\n";
	}
	return (0);
}
