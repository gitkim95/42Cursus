/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:35:53 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/01 17:17:12 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static int	isCorrectInput(int maxNum)
{
	std::stringstream	val;
	std::string			searchIdx;
	int					result;

	std::getline(std::cin, searchIdx);
	val << searchIdx;
	val >> result;
	if (val.fail() || result < 1 || result > maxNum)
		return (-1);
	else
		return (result);
}

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
	std::cout << "  First name| Last name|  Nickname" << std::endl;
	int	limit = (contactNum >= 8) ? 8 : contactNum;
	for (int i = 0; i < limit; i++)
	{
		std::cout << i + 1;
		contacts[i].outputContact();
	}
	std::cout << "Please enter the contact number : ";
	int	searchIdx = isCorrectInput(limit);
	if (searchIdx == -1)
		std::cout << "Wrong number!\n";
	else
		contacts[searchIdx - 1].displayContact();
}

void	Contact::inputContact()
{
	std::cout << "Please enter First Name : ";
	std::getline(std::cin, firstName);
	std::cout << "Please enter Last Name : ";
	std::getline(std::cin, lastName);
	std::cout << "Please enter Nickname : ";
	std::getline(std::cin, nickname);
	std::cout << "Please enter Phone Number : ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Please enter Darkest Secret : ";
	std::getline(std::cin, darkestSecret);
}

std::string	Contact::lengthNotTen(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}
void	Contact::outputContact()
{
	std::cout	<< "|" << std::setw(10) << lengthNotTen(firstName)
				<< "|" << std::setw(10) << lengthNotTen(lastName)
				<< "|" << std::setw(10) << lengthNotTen(nickname) << "\n";
}

void	Contact::displayContact()
{
	std::cout	<< "First Name : " << firstName << "\n"
				<< "Last Name : " << lastName << "\n"
				<< "Nickname : " << nickname << "\n"
				<< "Phone Number : " << phoneNumber << "\n"
				<< "Darkest Secret : " << darkestSecret << "\n";
}
