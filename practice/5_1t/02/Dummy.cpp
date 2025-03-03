/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:55:56 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 03:08:10 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy( void ) : ATarget("Target Practice Dummy") {}

Dummy::Dummy( const Dummy& other ) : ATarget(other) {}

Dummy::~Dummy( void ) {}

Dummy&	Dummy::operator=( const Dummy& other )
{
	ATarget::operator=(other);
	return (*this);
}

Dummy*	Dummy::clone( void ) const
{
	return (new Dummy());
}
