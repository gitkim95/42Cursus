/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:42:06 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/30 04:11:30 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>

class Replace
{
private:
	std::string inputString;
	std::string outputPath;
public:
	Replace( std::string inputPath );
	~Replace();

	std::string	replaceData( std::string input, std::string target, std::string replace );
	void		writeData( std::string outputPath, std::string replacedData );
	std::string getInput() const;
	std::string getOutputPath() const;
};

#endif