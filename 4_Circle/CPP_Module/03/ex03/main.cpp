/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:56:36 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 02:45:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    // 1. 기본 생성자 및 생성자에서 출력된 메시지 확인
    DiamondTrap diamond1("DiamondOne");
    std::cout << std::endl;

    // 2. DiamondTrap의 고유 함수 `whoAmI` 호출
    diamond1.whoAmI();
    std::cout << std::endl;

    // 3. DiamondTrap의 `attack` 함수가 ScavTrap의 attack을 사용하는지 확인
    diamond1.attack("TargetOne");
    std::cout << std::endl;

    // 4. 소멸자가 제대로 호출되는지 확인 (DiamondTrap의 소멸자가 호출되어야 함)
    // DiamondTrap 객체가 스코프를 벗어나면 소멸자가 호출됨
    {
        DiamondTrap diamond2("DiamondTwo");
    }
    std::cout << std::endl;
    
    // 5. 여러 객체 테스트
    DiamondTrap diamond3("DiamondThree");
    diamond3.attack("TargetTwo");
    diamond3.whoAmI();
    std::cout << std::endl;

    return (0);
}