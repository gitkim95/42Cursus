/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:33:23 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/14 08:33:10 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <climits>
#include <exception>
#include <sys/time.h>
#include "PmergeMe.hpp"

static void			printBefore ( int ac, char **av );
static void			printAfter ( std::vector<int>& vec );
static void			printAfter ( std::list<int>& list );
static long long	getCurrentTime( void );
static void			printCurrentTime( long long start, long long end, int length, std::string type );

int	main(int ac, char **av)
{
	std::vector<int>	vec;
	std::list<int>		list;
	if (ac < 2)
	{
		std::cerr << "Error: Not enough argument" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe::initContainer(vec, list, ac, av);
		printBefore(ac, av);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	long long	vectorStartTime = getCurrentTime();
	PmergeMe::mergeInsertionSort(vec, 0, vec.size() - 1);
	long long	vectorEndTime = getCurrentTime();
	printAfter(vec);
	long long	listStartTime = getCurrentTime();
	PmergeMe::mergeInsertionSort(list);
	long long	listEndTime = getCurrentTime();
	printAfter(list);
	printCurrentTime(vectorStartTime, vectorEndTime, ac - 1, "vector");
	printCurrentTime(listStartTime, listEndTime, ac - 1, "list");
	return (0);
}

static void	printBefore ( int ac, char **av )
{
	std::cout << "Before: ";
	for (int i = 1; i < ac; i++)
	{
		std::cout << av[i];
		if (i != ac - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

static void	printAfter ( std::vector<int>& vec )
{
	std::cout << "After(vector): ";
	for (int i = 0; i < static_cast<int>(vec.size()); i++)
	{
		std::cout << vec[i];
		if (i != static_cast<int>(vec.size()) - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

static void	printAfter ( std::list<int>& list )
{
	std::list<int>::iterator	listIter = list.begin();
	std::cout << "After(list): ";
	for (int i = 0; i < static_cast<int>(list.size()); i++)
	{
		std::cout << *listIter;
		if (i != static_cast<int>(list.size()) - 1)
			std::cout << " ";
		listIter++;
	}
	std::cout << std::endl;
}

static long long	getCurrentTime( void )
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000LL + tv.tv_usec);
}

static void	printCurrentTime( long long start, long long end, int length, std::string type )
{
	std::cout	<< "Time to process a range of "
				<< length
				<< " elements with std::"
				<< type
				<< " : "
				<< (end - start)
				<< " µs" << std::endl;
}
