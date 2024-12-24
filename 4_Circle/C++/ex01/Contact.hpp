/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:31:12 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/24 22:49:19 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	public:
		void	inputContact()
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

		std::string	lengthNotTen(const std::string& str)
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

		void	outputContact()
		{
			std::cout	<< "|" << lengthNotTen(firstName)
						<< "|" << lengthNotTen(lastName)
						<< "|" << lengthNotTen(nickname) << "\n";
		}
		
		void	displayContact()
		{
			std::cout	<< "First Name : " << firstName << "\n"
						<< "Last Name : " << lastName << "\n"
						<< "Nickname : " << nickname << "\n"
						<< "Phone Number : " << phoneNumber << "\n"
						<< "Darkest Secret : " << darkestSecret << "\n";
		}
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

#endif