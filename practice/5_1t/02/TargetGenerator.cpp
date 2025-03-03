/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:38:07 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 04:47:59 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator( void ) {}

TargetGenerator::TargetGenerator( const TargetGenerator& other ) : targets(other.targets) {}

TargetGenerator& TargetGenerator::operator=( const TargetGenerator& other )
{
	if (this != &other)
	{
		targets = other.targets;
	}
	return (*this);
}

TargetGenerator::~TargetGenerator( void ) {}

void	TargetGenerator::learnTargetType( ATarget* target )
{
	targets[target->getType()] = target->clone();
}

void	TargetGenerator::forgetTargetType( std::string const& type )
{
	std::map<std::string, ATarget*>::const_iterator	it = targets.find(type);

	if (it != targets.end())
	{
		delete (it->second);
		targets.erase(type);
	}
}

ATarget*	TargetGenerator::createTarget( std::string const& type )
{
	std::map<std::string, ATarget*>::const_iterator	it = targets.find(type);

	if (it != targets.end())
		return (it->second->clone());
	return (NULL);
}
