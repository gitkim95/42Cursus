/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:51:37 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/04 16:56:43 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy( void ) : ATarget("Target Practice Dummy") {}

Dummy::Dummy( Dummy const& other ) : ATarget(other) {}

Dummy&	Dummy::operator=( Dummy const& other )
{
	ATarget::operator=(other);
	return (*this);
}

Dummy::~Dummy(){}

Dummy*	Dummy::clone( void ) const
{
	return (new Dummy());
}
