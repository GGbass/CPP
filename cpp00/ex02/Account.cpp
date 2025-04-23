/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:41:04 by marvin            #+#    #+#             */
/*   Updated: 2025/04/20 02:41:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
	std::time_t current = std::time(NULL);
	std::tm *localTime = std::localtime(&current);
	std::cout << "[" << (localTime->tm_year + 1900)
			  << std::setw(2) << std::setfill('0')
			  << ((localTime->tm_mon + 1))
			  << std::setw(2) << std::setfill('0')
			  << localTime->tm_mday << "_"
			  << std::setw(2) << std::setfill('0')
			  << localTime->tm_hour
			  << std::setw(2) << std::setfill('0')
			  << localTime->tm_min
			  << std::setw(2) << std::setfill('0')
			  << localTime->tm_sec << "] ";
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:"<< _accountIndex <<";amount:"<< _amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	if (deposit > 0)
	{
		_amount += deposit;
		_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;

		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:"
				  << _amount - deposit 
				  << ";deposit:" << deposit 
				  << ";amount:" << _amount 
				  <<";nb_deposits:" << _nbDeposits << std::endl;
	}
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > 0 && withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:"
				  << _amount + withdrawal << ";withdrawal:" 
				  << withdrawal <<";amount:" << _amount 
				  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<";p_amount:" 
			  << _amount <<";withdrawal:refused" << std::endl;
	return (false);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:"<< _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
