/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:29:48 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/09 00:30:56 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe
{
private:
	/* data */
public:
	PmergeMe( void );
	PmergeMe( const PmergeMe &other);
	~PmergeMe( void );

	PmergeMe&	operator=( const PmergeMe &other );
};

#endif