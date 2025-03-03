/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:29:22 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 04:47:56 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <map>
# include <string>

class ATarget;

class TargetGenerator
{
private:
	std::map<std::string, ATarget*>	targets;
	TargetGenerator( const TargetGenerator& other );
	TargetGenerator& operator=( const TargetGenerator& other );
public:
	TargetGenerator( void );
	~TargetGenerator( void );

	void		learnTargetType( ATarget* target );
	void		forgetTargetType( std::string const& type );
	ATarget*	createTarget( std::string const& type );
};


#endif