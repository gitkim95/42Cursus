/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:20:19 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/24 21:54:06 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class A;
class B;
class C;

class Base
{
public:
	virtual ~Base( void ) {};
};

Base*	generate( void );
void	identify( Base* p );
void	identify( Base& p );

#endif