/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:08:09 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 17:37:33 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
private:
	std::map<std::string, double>	btcData;
public:
	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange &other );
	~BitcoinExchange( void );

	BitcoinExchange&	operator=( const BitcoinExchange &other );

	void	loadData( const std::string &fileName );
	void	matchData( const std::string &fileName );
	double	getBtcPrice( const std::string &date ) const;
};

#endif