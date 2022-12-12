#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	/*[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0*/
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ) {

	_nbAccounts++;

	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;

	_totalAmount += this->_amount;

	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	/*[19920104_091532] index:0;amount:42;created*/
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;

}

Account::~Account( void ) {
	/*[19920104_091532] index:0;amount:47;closed*/
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;

}

void	Account::makeDeposit( int deposit ) {

	_totalNbDeposits++;
	this->_nbDeposits++;
	/*[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1*/
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount + deposit
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	if (withdrawal <= this->_amount) {
		_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		/*[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1*/
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << this->_amount
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << this->_amount - withdrawal
				  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		return true;
	} else {
		/*[19920104_091532] index:0;p_amount:47;withdrawal:refused*/
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << this->_amount
				  << ";withdrawal:refused" << std::endl;
		return false;
	}
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	/*[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0*/
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals<< std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::cout << "[19920104_091532] ";
}