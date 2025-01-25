/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:40:57 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/25 19:42:56 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main()
{
    int     arr[] = {1, 2, 3, 4, 5};
    size_t  arrLength = 5;

    iter(arr, arrLength, print);
    std::cout << std::endl;
    iter(arr, arrLength, doubleValue);
    iter(arr, arrLength, print);
    std::cout << std::endl;

    return (0);
}