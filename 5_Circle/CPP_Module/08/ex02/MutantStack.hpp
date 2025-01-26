/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:58:59 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/26 19:11:21 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack
{
private:
	/* data */
public:
	MutantStack( void );
	MutantStack( const MutantStack& other );
	~MutantStack();

	MutantStack&	operator=( const MutantStack& other );

	void	push( void );
	void	pop( void );
	void	size( void );
	void	begin( void );
	void	end( void );
};

#endif