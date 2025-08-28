// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );  // static function in a class: belongs to the class itslef, not to a a specific object, can be called without vreating an object, cannot access non-static members - dosent know which object youre talking about
	static int	getTotalAmount( void );  // static variable inside a function: reuse the value from the last call of the function
	static int	getNbDeposits( void );   // static variable at top of .cpp : that variable is private to that .cpp file only
	static int	getNbWithdrawals( void ); // static variable in a class : belongs to the class itself, not to each object
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );   // constructor (runs when you create an object) "setup"
	~Account( void );                 // destructor (have ~) "cleanup" (when the programs ends and accounts vector was destroyed, destructors are automatically created for each account)
									  // destructor's rules: (auto called, always has the same name, ~ClassName, cant have params, cant return anything)
	void	makeDeposit( int deposit );   // nonstatic members - operate on a single object's data
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts; // static private variable - belongs to the class shared by all objects - only member functions can access it
	static int	_totalAmount; 
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void ); // static private function member - static belongs to class itself not to specific object, private means can be only usd inside the class itself - called inside other function member of Account , not called by itself
										   // made static because : does not need to access any per-object data , helper function that all Account objects can use, private = outside code (main.cpp or test code) cannot call it on its own, only can within anothe class' function member, and its just a utility function that is used by this calss only, static saves memory 
	int				_accountIndex; // non-static private variable - belongs to each object, only member functions of the class can access them
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void ); // private constructor - didnt use it - its to act as a guard so you didnt create an object without the initial deposit value : ex: Account a; (invalid), Account a(100); (valid) , no neeed to code this coz we'll never call this fn
};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
