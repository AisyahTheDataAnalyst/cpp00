/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:31:29 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/24 16:37:55 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream> // std::cout
#include <ctime> // std::time_t(), std::localtime()
#include <iomanip> //std::setw(), std::setfill()

// static private variables initializer (shared among all objects)

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// a utility function used within the class only (static private function member)

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);

    std::cout   << "[" 
                << 1900 + ltm->tm_year
                << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon
                << std::setfill('0') << std::setw(2) << ltm->tm_mday
                << "_"
                << std::setfill('0') << std::setw(2) << ltm->tm_hour
                << std::setfill('0') << std::setw(2) << ltm->tm_min
                << std::setfill('0') << std::setw(2) << ltm->tm_sec
                << "] ";
}

// constructor

Account::Account(int initial_deposit)
{
    // init non-static private variables - for each objects
    this->_accountIndex = _nbAccounts; // "this->" : a pointer to the current object, its by default inside any non-static member function (constructor, destructor, or normal function), only need to write this to avoid conflict names of local variable and member bariable
    this->_amount = initial_deposit;
	this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    // adjust static private variables - shared by all objects
    _nbAccounts++;
    _totalAmount += this->_amount;

    _displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";"
                << "amount:" << this->_amount << ";"
                << "created" << std::endl;
}

// getters (public static function)

int	Account::getNbAccounts( void )  
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) 
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )  
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) 
{
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout   << "accounts:" << _nbAccounts << ";"
                << "total:" << _totalAmount << ";"
                << "deposits:" << _totalNbDeposits << ";"
                << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

// setters (public function)

void Account::makeDeposit( int deposit )
{
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    int p_amount = this->_amount - deposit;
    _displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";"
                << "p_amount:" << p_amount << ";"
                << "deposit:" << deposit << ";"
                << "amount:" << this->_amount << ";"
                << "nb_deposits:" << this->_nbDeposits << std::endl;

}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";"
                << "p_amount:" << this->_amount << ";";

    if ( checkAmount() < withdrawal)
    {
        std::cout   << "withdrawal:refused" << std::endl;
        return (false);
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout   << "withdrawal:" << withdrawal << ";"
                << "amount:" << this->_amount << ";"
                << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";"
                << "amount:" << this->_amount << ";"
                << "deposits:" << this->_nbDeposits << ";"
                << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// destructor

Account::~Account(void)
{
    _displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";"
                << "amount:" << this->_amount << ";"\
                << "closed" << std::endl;
}