/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:45:53 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/17 23:53:53 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main()
{
	try
	{
        // 정상 생성 테스트
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);
        std::cout << alice << " created successfully.\n";
        std::cout << bob << " created successfully.\n";

        // 유효하지 않은 등급으로 생성 테스트
        Bureaucrat invalidHigh("Charlie", 0); // GradeTooHighException 발생
    }
	catch (const Bureaucrat::GradeTooHighException& e)
	{
        std::cerr << "[Exception] " << e.what() << std::endl;
    }
	catch (const Bureaucrat::GradeTooLowException& e)
	{
        std::cerr << "[Exception] " << e.what() << std::endl;
    }

    try
	{
        // 등급 조정 테스트
        Bureaucrat david("David", 2);
        std::cout << "Before increase: " << david << std::endl;
        david.increaseGrade(); // 정상적으로 등급 증가
        std::cout << "After increase: " << david << std::endl;

        // 예외: 등급 초과로 증가
        david.increaseGrade(); // GradeTooHighException 발생
    }
	catch (const Bureaucrat::GradeTooHighException& e)
	{
        std::cerr << "[Exception] " << e.what() << std::endl;
    }

    try
	{
        Bureaucrat eve("Eve", 149);
        std::cout << "Before decrease: " << eve << std::endl;
        eve.decreaseGrade(); // 정상적으로 등급 감소
        std::cout << "After decrease: " << eve << std::endl;

        // 예외: 등급 초과로 감소
        eve.decreaseGrade(); // GradeTooLowException 발생
    }
	catch (const Bureaucrat::GradeTooLowException& e)
	{
        std::cerr << "[Exception] " << e.what() << std::endl;
    }
	Bureaucrat origin("ori", 1);
	Bureaucrat modify("mod", 150);
	std::cout << origin << "\n" << modify << std::endl;
	origin = modify;
	std::cout << origin << "\n" << modify << std::endl;

    return 0;
}