#include "Account.hpp"

/**
 * @brief Construct a new Account:: Account object
 * 
 * Initializes a new account with the given initial deposit.
 * Increments the total number of accounts and updates the global total amount.
 * 
 * @param initial_deposit The amount of the initial deposit for the account
 */
Account::Account(int initial_deposit){
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

/**
 * @brief Destroy the Account object.
 * 
 * Destroy the account displaying the account index, current funds and a closure message.
 */
Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * @brief Display the current timestamp.
 * 
 * Display the current time in the [YYYYMMDD_HHMMSS] format.
 */
void Account::_displayTimestamp(){
	std::time_t now = std::time(0);
	std::tm* timeinfo = std::localtime(&now);

	std::cout << "["
			  << timeinfo->tm_year + 1900
			  << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1)
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_hour
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_min
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_sec
			  << "] ";

}

/**
 * @brief Display the informations of all the account.
 * 
 * This includes the number of accounts, total amount, number of deposits, number of withdrawals.
 */
void Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

/**
 * @brief Display the current status of the account.
 * 
 * This includes the account index, available amount of money, number of deposits and number of withdrawal.
 */
void Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl; 
}

/**
 * @brief Adds a deposit to the account.
 * 
 * Update the account's balance and increments both the individual
 * and global deposit counters
 *
 * @param deposit The amount to deposit.
 */
void Account::makeDeposit(int deposit){
	int	old_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << old_amount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

/**
 * @brief Attemps to withdraw a specified amount from the account
 * 
 * If the account has sufficient funds, the withdrawal is processed and
 * both the individual and global counters are updated.Otherwise, the
 * withdrawal is refused.
 *
 * @param withdrawal The amount to withdraw
 * @return true If the account had enough funds and the withdrawal succeeded
 * @return false If the account had insufficient funds and the withdrawal was refused
 */
bool Account::makeWithdrawal(int withdrawal){
	if (_amount >= withdrawal)
	{
		int old_amount = _amount;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << old_amount
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << _amount
				  << ";withdrawal:refused" << std::endl;
		return (false); 
	}
}