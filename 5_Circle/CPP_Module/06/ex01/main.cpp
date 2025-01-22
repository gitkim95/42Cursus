/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:04:44 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/22 23:10:22 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int	main()
{
	Data	data;
	data.value = 1;

	uintptr_t	intData = Serializer::serialize(&data);
	Data*		newData = Serializer::deserialize(intData);

	std::cout << "Original Data Pointer: " << &data << std::endl;
	std::cout << "Serialized Data Pointer: " << intData << std::endl;
	std::cout << "Deserialized Data Pointer: " << newData << std::endl;
	std::cout << "Original value: " << data.value << std::endl;
	std::cout << "New value: " << newData->value << std::endl;

	return (0);
}