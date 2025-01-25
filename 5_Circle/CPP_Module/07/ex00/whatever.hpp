/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:16:01 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/25 17:24:57 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b)
{
	T	temp;
	
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(T a, T b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

template <typename T>
T	max(T a, T b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif