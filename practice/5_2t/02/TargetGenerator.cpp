/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:43:23 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 18:15:50 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator( void ) {}

TargetGenerator::TargetGenerator( TargetGenerator const& other ) : targets(other.targets) {}

TargetGenerator&	TargetGenerator::operator=( TargetGenerator const& other )
{
	if (this != &other)
	{
		targets = other.targets;
	}
	return (*this);
}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget*>::const_iterator	it = targets.begin();
	std::map<std::string, ATarget*>::const_iterator	temp;
	if (it != targets.end())
	{
		temp = it;
		it++;
		delete (temp->second);
		targets.erase(temp->first);
	}
}

void	TargetGenerator::learnTargetType( ATarget* target )
{
	targets[target->getType()] = target->clone();
}

void	TargetGenerator::forgetTargetType( std::string const& targetName )
{
	std::map<std::string, ATarget*>::const_iterator	it = targets.find(targetName);

	if (it != targets.end())
	{
		delete (it->second);
		targets.erase(targetName);
	}
}

ATarget*	TargetGenerator::createTarget( std::string const& targetName )
{
	std::map<std::string, ATarget*>::const_iterator	it = targets.find(targetName);

	if (it != targets.end())
	{
		return (it->second->clone());
	}
	return (NULL);
}
