/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:23:56 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/08 14:17:10 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					value;
	static const int	fractionalBits = 8;
public:
	Fixed();
	Fixed( const int value );
	Fixed( const float fValue );
	Fixed( const Fixed& other );
	~Fixed();

	Fixed&	operator=(const Fixed& other);

	bool	operator>( const Fixed& other ) const;
	bool	operator<( const Fixed& other ) const;
	bool	operator>=( const Fixed& other ) const;
	bool	operator<=( const Fixed& other ) const;
	bool	operator==( const Fixed& other ) const;
	bool	operator!=( const Fixed& other ) const;

	Fixed	operator+( const Fixed& other ) const;
	Fixed	operator-( const Fixed& other ) const;
	Fixed	operator*( const Fixed& other ) const;
	Fixed	operator/( const Fixed& other ) const;

	Fixed&	operator++( void );
	Fixed&	operator--( void );
	Fixed	operator++( int );
	Fixed	operator--( int );

	static Fixed&		min( Fixed& a, Fixed& b );
	static Fixed&		max( Fixed& a, Fixed& b );
	static const Fixed&	min( const Fixed& ca, const Fixed& cb);
	static const Fixed& max( const Fixed& ca, const Fixed& cb);

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif