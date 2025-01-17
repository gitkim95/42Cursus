/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:04:21 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/17 14:38:03 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main( void )
{
	Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(0.0f, 3.0f);

    // 내부에 있는 점
    Point pointInside(1.0f, 1.0f);

    // 삼각형의 변 위에 있는 점
    Point pointOnEdge(2.0f, 0.0f);

    // 삼각형 외부에 있는 점
    Point pointOutside(5.0f, 5.0f);

    // 테스트
    std::cout << "Point Inside: " << (a.bsp(a, b, c, pointInside) ? "True" : "False") << std::endl;
    std::cout << "Point On Edge: " << (a.bsp(a, b, c, pointOnEdge) ? "True" : "False") << std::endl;
    std::cout << "Point Outside: " << (a.bsp(a, b, c, pointOutside) ? "True" : "False") << std::endl;

    return 0;
}