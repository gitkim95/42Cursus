/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:27:00 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/02 20:08:10 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value ) : value(value << fractionalBits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float fvalue ) : value(static_cast<int>(roundf(fvalue * (1 << fractionalBits))))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	value = other.value;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(value) / (1 << fractionalBits));
}

int		Fixed::toInt() const
{
	return (value >> fractionalBits);
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

bool	Fixed::operator>( const Fixed& other ) const
{
	return ((this->value > other.value) ? true : false);
}

bool	Fixed::operator<( const Fixed& other ) const
{
	return ((this->value < other.value) ? true : false);
}

bool	Fixed::operator>=( const Fixed& other ) const
{
	return ((this->value >= other.value ? true : false));
}

bool	Fixed::operator<=( const Fixed& other ) const
{
	return ((this->value <= other.value ? true : false));
}

bool	Fixed::operator==( const Fixed& other ) const
{
	return ((this->value == other.value ? true : false));
}

bool	Fixed::operator!=( const Fixed& other ) const
{
	return ((this->value != other.value ? true : false));
}

Fixed	Fixed::operator+( const Fixed& other ) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-( const Fixed& other ) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*( const Fixed& other ) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/( const Fixed& other ) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++( void )
{
	this->value += 1;
	return (*this);
}

Fixed&	Fixed::operator--( void )
{
	this->value -= 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	temp = *this;
	this->value += 1;
	return (temp);
}

Fixed	Fixed::operator--( int )
{
	Fixed	temp = *this;
	this->value -= 1;
	return (temp);
}

Fixed&	Fixed::min( Fixed& a, Fixed& b )
{
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max( Fixed& a, Fixed& b )
{
	return ((a > b) ? a : b);
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b)
{
	return ((a < b) ? a : b);
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);
}
