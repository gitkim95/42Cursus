/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:45:53 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/19 21:17:16 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	try
    {
        // Bureaucrat 생성
        Bureaucrat alice("Alice", 3);
        Bureaucrat bob("Bob", 150);

        // Form 생성
        Form importantForm("Important Form", 5, 10);
        Form easyForm("Easy Form", 150, 150);

        // Form과 Bureaucrat 정보 출력
        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << importantForm << std::endl;
        std::cout << easyForm << std::endl;

        // Alice가 Form 서명 시도
        alice.signForm(importantForm);
        alice.signForm(easyForm);

        // Bob이 Form 서명 시도
        bob.signForm(importantForm);
        bob.signForm(easyForm);

        // Form의 서명 상태 확인
        std::cout << importantForm << std::endl;
        std::cout << easyForm << std::endl;

    }
    catch (const std::exception& e)
    {
        // 예외 처리
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}