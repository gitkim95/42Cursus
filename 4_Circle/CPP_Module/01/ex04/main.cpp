/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:38:27 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/30 04:04:07 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <sstream>
#include "Replace.hpp"

int	main( int argc, char **argv )
{
	if (argc != 4)
		return (0);
	
	Replace*	replace = new Replace(argv[1]);
	std::string	replacedData = replace->replaceData(replace->getInput(), argv[2], argv[3]);
	replace->writeData(replace->getOutputPath(), replacedData);
	delete replace;
	return (0);
}
