/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:05:35 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 18:13:34 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <string>
# include <map>

class ATarget;

class TargetGenerator
{
private:
	std::map<std::string, ATarget*>	targets;
	TargetGenerator( TargetGenerator const& other );
	TargetGenerator&	operator=( TargetGenerator const& other );
public:
	TargetGenerator( void );
	~TargetGenerator();

	void	learnTargetType( ATarget* spell );
	void	forgetTargetType( std::string const& spellName );
	ATarget*	createTarget( std::string const& spellName );
};

#endif