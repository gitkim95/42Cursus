/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:35:53 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/25 19:28:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	PhoneBook::add()
{
	if (contactNum >= 8)
		std::cout << "PhoneBook is full.\nThe oldest contact will be replaced.\n";
	contacts[contactNum % 8].inputContact();
	contactNum++;
	std::cout << "Addition successful\n";
}
void	PhoneBook::search()
{
	if (contactNum == 0)
      	{
		std::cout << "The phonebook is empty." << std::endl;
		return ;
      	}
	int	limit = (contactNum >= 8) ? 8 : contactNum;
	for (int i = 0; i < limit; i++)
	{
		std::cout << i + 1;
		contacts[i].outputContact();
	}
	std::cout << "Please enter the contact number : ";
	std::cin >> searchIdx;
	if (!(0 <= searchIdx && searchIdx <= 7))
		std::cout << "Wrong number!\n";
	else
		contacts[searchIdx - 1].displayContact();
}

void	Contact::inputContact()
{
	std::cout << "Please enter First Name : ";
	std::cin >> firstName;
	std::cout << "Please enter Last Name : ";
	std::cin >> lastName;
	std::cout << "Please enter Nickname : ";
	std::cin >> nickname;
	std::cout << "Please enter Phone Number : ";
	std::cin >> phoneNumber;
	std::cout << "Please enter Darkest Secret : ";
	std::cin >> darkestSecret;
}

std::string	Contact::lengthNotTen(const std::string& str)
{
	if (str.length() < 10)
	{
		int	cnt = 10 - str.length();
		return (std::string(cnt, ' ') + str);
	}
	else if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}
void	Contact::outputContact()
{
	std::cout	<< "|" << lengthNotTen(firstName)
				<< "|" << lengthNotTen(lastName)
				<< "|" << lengthNotTen(nickname) << "\n";
}

void	Contact::displayContact()
{
	std::cout	<< "First Name : " << firstName << "\n"
				<< "Last Name : " << lastName << "\n"
				<< "Nickname : " << nickname << "\n"
				<< "Phone Number : " << phoneNumber << "\n"
				<< "Darkest Secret : " << darkestSecret << "\n";
}
