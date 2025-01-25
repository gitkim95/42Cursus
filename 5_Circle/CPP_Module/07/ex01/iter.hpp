/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:25:15 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/25 19:42:41 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>

template <typename T>
void	iter(T* a, size_t length, void (*func)(T&))
{
	for (size_t i = 0; i < length; i++)
	{
		func(a[i]);
	}
}

template <typename T>
void	print(T& value)
{
	std::cout << value << " ";
}

template <typename T>
void	doubleValue(T& value)
{
	value *= 2;
}

#endif