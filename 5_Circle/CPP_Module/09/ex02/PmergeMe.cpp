/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:31:00 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/12 18:37:44 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <cstdlib>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( const PmergeMe &other) : temp(other.temp) {}

PmergeMe::~PmergeMe( void  ){}

PmergeMe&	PmergeMe::operator=( const PmergeMe &other )
{
	if (this != &other)
		temp = other.temp;
	return (*this);
}

void	PmergeMe::initContainer( std::vector<int>& vec, std::list<int>& list, int ac, char **av )
{
	for (int i = 1; i < ac; i++)
	{
		long	value = strtol(av[i], NULL, 10);
		if (value < 0 || value > INT_MAX)
			throw (PmergeMeException("Error: Value out of range"));
		vec.push_back(static_cast<int>(value));
		list.push_back(static_cast<int>(value));
	}
}

void	PmergeMe::insertionSort( std::vector<int>& vec, int start, int end )
{
	for (int i = start + 1; i <= end; i++)
	{
		int	key = vec[i];
		int	j = i - 1;

		while (j >= start && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

void	PmergeMe::mergeSort( std::vector<int>& vec, int start, int mid, int end )
{
	std::vector<int>	left(vec.begin() + start, vec.begin() + mid + 1);
	std::vector<int>	right(vec.begin() + mid + 1, vec.begin() + end + 1); 
	int					leftIdx = 0, rightIdx = 0, vecIdx = start;
	
	while (leftIdx < static_cast<int>(left.size()) && rightIdx < static_cast<int>(right.size()))
	{
		if (left[leftIdx] < right[rightIdx])
			vec[vecIdx++] = left[leftIdx++];
		else
			vec[vecIdx++] = right[rightIdx++];
	}
	while (leftIdx < static_cast<int>(left.size()))
		vec[vecIdx++] = left[leftIdx++];
	while (rightIdx < static_cast<int>(right.size()))
		vec[vecIdx++] = right[rightIdx++];
}

void	PmergeMe::mergeInsertionSort( std::vector<int>& vec, int start, int end )
{
	PmergeMe	temp;
	int	targetSize = 5;
	if (end - start + 1 <= targetSize)
	{
		temp.insertionSort(vec, start, end);
		return ;
	}

	int	mid = (end - start) / 2 + start;
	mergeInsertionSort(vec, start, mid);
	mergeInsertionSort(vec, mid + 1, end);
	temp.mergeSort(vec, start, mid, end);
}

void	PmergeMe::insertionSort( std::list<int>& list )
{
	if (list.size() < 2)
		return ;
	std::list<int>::iterator	listIter = list.begin();
	listIter++;
	while (listIter != list.end())
	{
		int							key = *listIter;
		std::list<int>::iterator	tempIter = listIter;
		std::list<int>::iterator	prevIter = listIter;
		prevIter--;
		while (tempIter != list.begin() && *prevIter > key)
		{
			*tempIter = *prevIter;
			tempIter = prevIter;
			if (prevIter == list.begin())
				break ;
			prevIter--;
		}
		*tempIter = key;
		listIter++;
	}
}

void	PmergeMe::mergeInsertionSort( std::list<int>& list )
{
	PmergeMe	temp;
	if (list.size() <= 5)
	{
		temp.insertionSort(list);
		return ;
	}
	
	std::list<int>	left, right;
	temp.splitList(left, right, list);

	mergeInsertionSort(left);
	mergeInsertionSort(right);

	list.clear();
	std::list<int>::iterator	leftIter = left.begin();
	std::list<int>::iterator	rightIter = right.begin();

	while (leftIter != left.end() && rightIter != right.end())
	{
		if (*leftIter < *rightIter)
		{
			list.push_back(*leftIter);
			leftIter++;
		}
		else
		{
			list.push_back(*rightIter);
			rightIter++;
		}
	}
	while (leftIter != left.end())
	{
		list.push_back(*leftIter);
		leftIter++;
	}
	while (rightIter != right.end())
	{
		list.push_back(*rightIter);
		rightIter++;
	}
}

void	PmergeMe::splitList( std::list<int>& left, std::list<int>& right, std::list<int>& origin)
{
	std::list<int>::iterator	mid = origin.begin();
	std::advance(mid, origin.size() / 2);

	left.splice(left.begin(), origin, origin.begin(), mid);
	right.splice(right.begin(), origin, origin.begin(), origin.end());
}

PmergeMe::PmergeMeException::PmergeMeException( const std::string &errMsg ) : errMsg(errMsg) {}

PmergeMe::PmergeMeException::~PmergeMeException() throw() {}

const char* PmergeMe::PmergeMeException::what() const throw()
{
	return (errMsg.c_str());
}