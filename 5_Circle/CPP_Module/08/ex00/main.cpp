/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:56:13 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/26 18:04:36 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int	main()
{
	//vector
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	try
	{
		std::vector<int>::const_iterator result = easyfind(vec, 3);
		std::cout << "Found the value : " << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//list
	std::list<int> lst;
	lst.push_back(6);
	lst.push_back(7);
	lst.push_back(8);
	lst.push_back(9);
	lst.push_back(10);
	try
	{
		std::list<int>::const_iterator result = easyfind(lst, 8);
		std::cout << "Found the value : " << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	

	//empty
	std::vector<int> empty;
	try
	{
		easyfind(empty, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}