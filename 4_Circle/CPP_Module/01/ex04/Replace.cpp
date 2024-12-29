/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:43:12 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/30 04:12:01 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Replace.hpp"

std::string	Replace::replaceData( std::string input, std::string target, std::string replace )
{
	size_t	pos = 0;

	pos = input.find(target);
	while (pos != std::string::npos)
	{
		input.erase(pos, target.length());
		input.insert(pos, replace);
		pos = input.find(target, pos + replace.length());
	}
	return (input);
}

void	Replace::writeData( std::string outputPath, std::string replacedData )
{
	std::ofstream	outputFile(outputPath.c_str(), std::ios::out);
	if (!outputFile)
	{
		std::cerr << "Failed to open : " << outputPath << std::endl;
	}
	outputFile << replacedData;
}

std::string Replace::getInput() const
{
	return (inputString);
}

std::string Replace::getOutputPath() const
{
	return (outputPath);
}

Replace::Replace( std::string inputPath )
{
	std::ifstream		inputFile(inputPath.c_str(), std::ios::in);\
	if (!inputFile)
	{
		std::cerr << "Failed to open : " << inputPath << std::endl;
	}
	std::stringstream	buf;
	buf << inputFile.rdbuf();
	inputString = buf.str();
	outputPath = inputPath + std::string(".replace");
}

Replace::~Replace()
{
	
}
