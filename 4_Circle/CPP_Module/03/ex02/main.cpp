/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:41:01 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/08 00:51:55 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // ClapTrap 생성자 테스트
    std::cout << "--- ClapTrap Test ---" << std::endl;
    ClapTrap clapTrap("Clappy");
    clapTrap.attack("Enemy1");
    std::cout << std::endl;

    // ScavTrap 생성자 및 기능 테스트
    std::cout << "--- ScavTrap Test ---" << std::endl;
    ScavTrap scavTrap("Scavvy");
    scavTrap.attack("Enemy2");
    scavTrap.guardGate();
    std::cout << std::endl;

    // FragTrap 생성자 및 기능 테스트
    std::cout << "--- FragTrap Test ---" << std::endl;
    FragTrap fragTrap("Fraggy");
    fragTrap.attack("Enemy3");
    fragTrap.highFivesGuys();
    std::cout << std::endl;

    // ScavTrap 복사 생성자 테스트
    std::cout << "--- ScavTrap Copy Constructor Test ---" << std::endl;
    ScavTrap copiedScavTrap = scavTrap;
    copiedScavTrap.attack("Enemy4");
    std::cout << std::endl;

    // FragTrap 복사 생성자 테스트
    std::cout << "--- FragTrap Copy Constructor Test ---" << std::endl;
    FragTrap copiedFragTrap = fragTrap;
    copiedFragTrap.attack("Enemy5");
    std::cout << std::endl;

    // ScavTrap 대입 연산자 테스트
    std::cout << "--- ScavTrap Assignment Operator Test ---" << std::endl;
    ScavTrap assignedScavTrap("AssignedScav");
    assignedScavTrap = scavTrap;
    assignedScavTrap.attack("Enemy6");
    std::cout << std::endl;

    // FragTrap 대입 연산자 테스트
    std::cout << "--- FragTrap Assignment Operator Test ---" << std::endl;
    FragTrap assignedFragTrap("AssignedFrag");
    assignedFragTrap = fragTrap;
    assignedFragTrap.attack("Enemy7");
    std::cout << std::endl;
    
    return (0);
}