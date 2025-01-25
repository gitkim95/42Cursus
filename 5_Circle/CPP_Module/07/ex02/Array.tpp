/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:41:54 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/25 22:35:16 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : arr(NULL), length(0)
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array( unsigned int n ) : arr(new T[n]()), length(n)
{
	std::cout << "Uint constructor called" << std::endl;
}

template <typename T>
Array<T>::Array( const Array<T>& other ) : arr(new T[other.length]), length(other.length)
{
	std::cout << "Copy constructor called" << std::endl;
	for (unsigned int i = 0; i < length; i++)
	{
		arr[i] = other.arr[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called" << std::endl;
	delete[] (arr);
}

template <typename T>
Array<T>&	Array<T>::operator=( const Array<T>& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		delete[] (arr);
		length = other.length;
		arr = new T[length];
		for (unsigned int i = 0; i < length; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[]( unsigned int index )
{
	if (index >= length)
		throw (std::exception());
	return (arr[index]);
}

template <typename T>
unsigned int	Array<T>::size( void ) const
{
	return (length);
}