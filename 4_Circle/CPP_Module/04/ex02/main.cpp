/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 02:57:17 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/12 23:46:56 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const int N = 6;
    Animal* animals[N];

    // Half Dog, Half Cat
    for (int i = 0; i < N / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = N / 2; i < N; ++i) {
        animals[i] = new Cat();
    }
    std::cout << "---" << std::endl;
    // Test copy constructor and assignment operator
    Dog dogCopy = *dynamic_cast<Dog*>(animals[0]);
    Cat catCopy = *dynamic_cast<Cat*>(animals[N / 2]);
    std::cout << "---" << std::endl;
    // Test assignment
    *dynamic_cast<Dog*>(animals[1]) = dogCopy;
    *dynamic_cast<Cat*>(animals[3]) = catCopy;
    std::cout << "---" << std::endl;
    // Make sounds
    for (int i = 0; i < N; ++i) {
        animals[i]->makeSound();
    }

    // Clean up and delete animals
    for (int i = 0; i < N; ++i) {
        delete animals[i];
    }

    // Animal *parent = new Animal();
    // 순수 가상함수가 포함되어 추상클래스가 되어 선언 불가
    return 0;
}
