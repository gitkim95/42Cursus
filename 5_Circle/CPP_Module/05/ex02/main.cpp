/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:45:53 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/21 20:50:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	try
    {
        // Bureaucrat 생성
        Bureaucrat alice("Alice", 3);
        Bureaucrat bob("Bob", 150);

        // Form 생성
        ShrubberyCreationForm sForm("sForm");
        RobotomyRequestForm rForm("rForm");
        PresidentialPardonForm pForm("pForm");

        // Form과 Bureaucrat 정보 출력
        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << sForm << std::endl;
        std::cout << rForm << std::endl;
        std::cout << pForm << std::endl;

        // Alice가 Form 서명 시도
        try
        {
            alice.signForm(sForm);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            alice.signForm(rForm);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            alice.signForm(pForm);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Bob이 Form 서명 시도
        try
        {
            bob.signForm(sForm);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            bob.signForm(rForm);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            bob.signForm(pForm);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Form의 서명 상태 확인
        std::cout << sForm << std::endl;
        std::cout << rForm << std::endl;
        std::cout << pForm << std::endl;

        try
        {
            sForm.execute(alice);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            rForm.execute(alice);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            pForm.execute(alice);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            sForm.execute(bob);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            sForm.execute(bob);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            sForm.execute(bob);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        // 예외 처리
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}