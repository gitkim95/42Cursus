/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:29:48 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/12 03:14:37 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>

class PmergeMe
{
private:
	std::vector<int>	vec;
	std::list<int>		list;
public:
	PmergeMe( void );
	PmergeMe( const PmergeMe &other);
	~PmergeMe( void );

	PmergeMe&	operator=( const PmergeMe &other );
	
	void	insertionSort( std::vector<int>& vec, int start, int end);
	void	insertionSort( std::list<int>& list, int start, int end);
	void	mergeSort( std::vector<int>& vec, int start, int mid, int end);
	void	mergeSort( std::list<int>& list, int start, int mid, int end);
	void	mergeInsertionSort( std::vector<int>& vec, int start, int end);
	void	mergeInsertionSort( std::list<int>& list, int start, int end);
};

#endif