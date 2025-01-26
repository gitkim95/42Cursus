/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:58:59 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/26 23:05:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack( void );
	MutantStack( const MutantStack& other );
	~MutantStack();

	MutantStack&	operator=( const MutantStack& other );

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator		begin( void );
	iterator		end( void );
	const_iterator	begin( void ) const;
	const_iterator	end( void ) const;
};

# include "MutantStack.tpp"

#endif