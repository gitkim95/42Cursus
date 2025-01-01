/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:27:27 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/01 15:22:41 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout	<< "[ DEBUG ]\n"
				<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-specialketchup burger. "
				<< "I really do!\n" << std::endl;
}

void	Harl::info( void )
{
	std::cout	<< "[ INFO ]\n"
				<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn’t put enough bacon in my burger! If you did, "
				<< "I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning( void )
{
	std::cout	<< "[ WARNING ]\n"
				<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming for years whereas you started working "
				<< "here since last month.\n" << std::endl;
}

void	Harl::error( void )
{
	std::cout	<< "[ ERROR ]\n"
				<< "This is unacceptable! I want to speak to the manager now.\n"
				<< std::endl;
}

void	Harl::complain( std::string input )
{
	int	level;

	for (int i = 0; i < 4; i++)
	{
		if (input == levels[i])
		{
			level = i;	
		}
	}

	switch (level)
	{
		case (0):
			(this->*funcPointer[0])();
			(this->*funcPointer[1])();
			(this->*funcPointer[2])();
			(this->*funcPointer[3])();
			// goto case_1;
			break ;
		case (1):
		case_1:
			(this->*funcPointer[1])();
			(this->*funcPointer[2])();
			(this->*funcPointer[3])();
			// goto case_2;
			break ;
		case (2):
		case_2:
			(this->*funcPointer[2])();
			(this->*funcPointer[3])();
			// goto case_3;
			break ;
		case (3):
		case_3:
			(this->*funcPointer[3])();
			break ;
		default:
			std::cout	<< "[ Probably complaining about insignificant problems ]"
						<< std::endl;
	}
}

Harl::Harl()
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	funcPointer[0] = &Harl::debug;
	funcPointer[1] = &Harl::info;
	funcPointer[2] = &Harl::warning;
	funcPointer[3] = &Harl::error;
}
