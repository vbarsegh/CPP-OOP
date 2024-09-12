#include "Account.hpp"

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}


Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_amount = initial_deposit;
	// this->_accountIndex = _nbAccounts++;
	// this->_nbDeposits = 0;
	// this->_nbWithdrawals = 0;
	// _totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout<< "amount:" << this->_amount << ";" << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" <<  _accountIndex  << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	cur_time;
	struct tm *infotime;

	cur_time = time(nullptr);
	infotime = localtime(&cur_time);
	std::cout << "[" << infotime->tm_year + 1900 << infotime->tm_mon << infotime->tm_mday;
	std::cout << "_" << infotime->tm_hour << infotime->tm_min << infotime->tm_sec;
	
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
