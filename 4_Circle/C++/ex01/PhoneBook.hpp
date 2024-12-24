/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:32:37 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/24 22:50:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook() : contactNum(0) {}
		void	add()
		{
			if (contactNum >= 8)
				std::cout << "PhoneBook is full.\nThe oldest contact will be replaced.\n";
			contacts[contactNum % 8].inputContact();
			contactNum++;
			std::cout << "Addition successful\n";
		}
		void	search()
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
	private:
		Contact	contacts[8];
		int		contactNum;
		int		searchIdx;
};

#endif