/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:31:00 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/12 04:11:28 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{

}

PmergeMe::PmergeMe( const PmergeMe &other)
{

}

PmergeMe::~PmergeMe( void )
{

}

PmergeMe&	PmergeMe::operator=( const PmergeMe &other )
{
	
}

void	PmergeMe::insertionSort( std::vector<int>& vec, int start, int end)
{
	for (int i = start + 1; i <= end; i++)
	{
		int	key = vec[i];
		int	j = i;

		while (j >= start && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

void	PmergeMe::insertionSort( std::list<int>& list, int start, int end)
{
	
}

void	PmergeMe::mergeSort( std::vector<int>& vec, int start, int mid, int end)
{
	std::vector<int>	left(vec.begin() + start, vec.begin() + mid + 1);
	std::vector<int>	right(vec.begin() + mid + 1, vec.begin() + end + 1); 
	int					leftIdx = 0, rightIdx = 0, vecIdx = start;
	
	while (leftIdx < left.size() && rightIdx < right.size())
	{
		if (left[leftIdx] < right[rightIdx])
			vec[vecIdx++] = left[leftIdx++];
		else
			vec[vecIdx++] = right[rightIdx++];
	}
	while (leftIdx < left.size())
		vec[vecIdx++] = left[leftIdx++];
	while (rightIdx < right.size())
		vec[vecIdx++] = right[rightIdx++];
}


void	PmergeMe::mergeSort( std::list<int>& list, int start, int mid, int end)
{


}

void	PmergeMe::mergeInsertionSort( std::vector<int>& vec, int start, int end)
{
	int	targetSize = 5;
	if (end - start + 1 <= targetSize)
	{
		insertionSort(vec, start, end);
		return ;
	}

	int	mid = (end - start) / 2 + start;
	mergeInsertionSort(vec, start, mid);
	mergeInsertionSort(vec, mid + 1, end);
	mergeSort(vec, start, mid, end);
}


void	PmergeMe::mergeInsertionSort( std::list<int>& list, int start, int end)
{

}

