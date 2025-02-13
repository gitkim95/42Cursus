/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:25:38 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/13 17:58:18 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "== PLEASE ENTER THE COMMAND ==" << std::endl;
		if (!std::getline(std::cin, input))
			break ;
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
