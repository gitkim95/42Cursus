/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:47:39 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/22 01:59:52 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
private:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter& other );
	ScalarConverter&	operator=( const ScalarConverter& other );


public:
	~ScalarConverter( void );

	static void	convert( const std::string& input );
};

#endif