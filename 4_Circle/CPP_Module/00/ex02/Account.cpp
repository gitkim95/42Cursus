/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:52:38 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/25 19:48:31 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

// 정적 변수 초기화
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// 생성자
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

// 소멸자
Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

// 정적 함수: 총 계좌 수 반환
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

// 정적 함수: 총 금액 반환
int Account::getTotalAmount(void)
{
    return _totalAmount;
}

// 정적 함수: 총 입금 횟수 반환
int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

// 정적 함수: 총 출금 횟수 반환
int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

// 정적 함수: 타임스탬프 출력
void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm* local_time = std::localtime(&now);
    std::cout << "[" 
              << (1900 + local_time->tm_year)
              << std::setfill('0') << std::setw(2) << (1 + local_time->tm_mon)
              << std::setfill('0') << std::setw(2) << local_time->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << local_time->tm_hour
              << std::setfill('0') << std::setw(2) << local_time->tm_min
              << std::setfill('0') << std::setw(2) << local_time->tm_sec
              << "] ";
}

// 입금
void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

// 출금
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:";
    if (withdrawal > _amount) {
        std::cout << "refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << withdrawal 
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

// 잔액 확인 (디버깅용, 출력 없음)
int Account::checkAmount(void) const
{
    return _amount;
}

// 상태 출력
void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// 정적 함수: 총 계좌 정보 출력
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts 
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals 
              << std::endl;
}
