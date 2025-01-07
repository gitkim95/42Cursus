/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:41:01 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 00:41:02 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main() {
    // ScavTrap 객체 생성 (기본 생성자 사용)
    ScavTrap	scav1;
    // ScavTrap 객체 생성 (매개변수 생성자 사용)
    ScavTrap	scav2("Scavenger");

    // ScavTrap의 특수 능력 테스트
    scav2.guardGate();

    // 공격 테스트
    scav2.attack("Enemy");

    // 복사 생성자 테스트
    ScavTrap	scav3 = scav2; // ScavTrap 복사 생성자 호출

    // 대입 연산자 테스트
    ScavTrap	scav4;
    scav4 = scav2; // ScavTrap 대입 연산자 호출

	std::cout	<< scav1 << "\n"
				<< scav2 << "\n"
				<< scav3 << "\n"
				<< scav4 << std::endl;

    return (0);
}