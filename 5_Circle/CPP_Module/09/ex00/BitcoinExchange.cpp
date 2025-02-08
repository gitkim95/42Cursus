/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:38:08 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 17:43:48 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) : btcData(other.btcData) {}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange &other )
{
	if (this != &other)
	{
		btcData = other.btcData;
	}
	return (*this);
}

void	BitcoinExchange::loadData( const std::string &fileName )
{
	std::ifstream	file(fileName.c_str());
	if (!file.is_open())
		std::cerr << "Error: Cannot open database file" << std::endl;

	std::string	line;
	while (std::getline(file, line))
	{
		std::istringstream	iss(line);
		std::string			date;
		double				price;

		if (std::getline(iss, date, ',') && (iss >> price))
            btcData[date] = price;
	}
	file.close();
}

void	BitcoinExchange::matchData( const std::string &fileName )
{
	std::ifstream	file(fileName.c_str());
	if (!file.is_open())
		std::cerr << "Error: Cannot open input file" << std::endl;
	
	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream	iss(line);
		std::string			date, pipe;
		double				value;

		if (std::getline(iss, date, ' ') && std::getline(iss, pipe, ' ') && (iss >> value))
		{
			if (pipe != "|")
			{
				std::cerr << "Error: Invalid format in input file" << std::endl;
				continue;
			}
			if (value < 0 || value > 1000)
			{
				std::cerr << "Error: Value out of range(0 ~ 1000)" << std::endl;
				continue;
			}
			double	price = getBtcPrice(date);
			if (price == -1)
			{
				std::cerr << "Error: No data for date => " << date << std::endl;
				continue;
			}
			std::cout << date << " => " << value << " = " << (value * price) << std::endl;
		}
		else
			std::cerr << "Error: Bad input => " << line << std::endl;
	}
}

double	BitcoinExchange::getBtcPrice( const std::string &date ) const
{
	if (btcData.empty())
		return (-1);
	std::map<std::string, double>::const_iterator	data = btcData.lower_bound(date);
	if (data == btcData.begin() && data->first != date)
		return (-1);
	if (data->first == date)
		return (data->second);
	return ((--data)->second);
}
