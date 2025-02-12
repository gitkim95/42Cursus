/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:33:23 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/12 13:04:58 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <climits>
#include <exception>
#include "PmergeMe.hpp"

static void	printBefore ( int ac, char **av );
static void	printAfter ( std::string after );

int	main(int ac, char **av)
{
	std::vector<int>	vec;
	std::list<int>		list;
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
	PmergeMe::mergeInsertionSort(vec, 0, vec.size() - 1);
	PmergeMe::mergeInsertionSort(list);
	printAfter(vec);

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
	std::cout << "After: ";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i != vec.size() - 2)
			std::cout << " ";
	}
	std::cout << std::endl;
}

//양의 정수를 인수로 사용
//오류는 표준 오류출력
//각 컨테이너에 대해 개별적으로 알고리즘 써라, 제네릭함수는 지양해라
/*
첫 번째 줄에는 명확한 텍스트와 함께 정렬되지 않은 양의 정수 시퀀스를 표시해야 합니다.
두 번째 줄에는 명확한 텍스트와 함께 정렬된 양의 정수 시퀀스를 표시해야 합니다.
세 번째 줄에는 첫 번째 컨테이너를 사용하여 양의 정수 시퀀스를 정렬하는 데 걸린 시간을 명시하는 명확한 텍스트를 표시해야 합니다.
마지막 줄에는 두 번째 컨테이너를 사용하여 양의 정수 시퀀스를 정렬하는 데 걸린 시간을 명시하는 명확한 텍스트를 표시해야 합니다.

Merge-Insertion Sort의 개념
페어 정렬 (Pairwise Sorting)

입력된 숫자들을 두 개씩 짝을 지어 비교합니다.
각 쌍을 정렬한 후, 더 작은 값을 기본 리스트(main chain)에, 더 큰 값을 서브 리스트(secondary chain)에 저장합니다.
서브 리스트 병합 (Recursive Merge)

서브 리스트를 다시 Merge-Insertion Sort 방식으로 정렬합니다.
최적의 비교 전략을 사용하여 기본 리스트에 삽입합니다.
삽입 정렬 (Final Insertion Phase)

병합이 끝난 후, 남아 있는 원소들을 적절한 위치에 삽입합니다.
*/