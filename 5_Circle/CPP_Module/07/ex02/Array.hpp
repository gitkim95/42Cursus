/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:55:03 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/25 22:24:17 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array
{
private:
	T*				arr;
	unsigned int	length;
public:
	Array( void );
	Array( unsigned int n );
	Array( const Array<T>& other );
	~Array();

	Array<T>&	operator=( const Array<T>& other );
	T&			operator[]( unsigned int index );

	unsigned int	size( void ) const;
};

#endif