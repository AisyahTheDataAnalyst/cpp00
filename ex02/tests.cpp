// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm> // for_each
#include <functional> // mem_fun_ref
#include "Account.hpp" // Linux & macOS usually case-sensitive, so must Account.hpp not account.hpp. windows are case-insensitive. depends on what you named your .hpp


int		main( void ) {
																		  // renaming Account -> t -> accounts_t  
	typedef std::vector<Account::t>							  accounts_t; // std::vector<T> : a dynamic array( a list can grow/shrink )
	typedef std::vector<int>								  ints_t;     // < > : angle bracklets: tell compiler what type you want
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;  // std::pair<A,B> : just a small container holding exectly 2 things together (not just iterators)
																		  // iterator: a pointer to an element inside a vector/container
																		  // example of iterator : v.begin() returns iterator to the 1st element
																		  //                     : v.end() returns iterator past the last element (last + 1)
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) ); // equivalent to: size_t const amounts_size = sizeof(amounts) / sizeof(int); // () is just another syntax for initializing a variable. // sizeof(amounts) = total memory in bytes taken by the whole array, sizeof(int) = size of 1 int in bytes
	accounts_t				accounts( amounts, amounts + amounts_size );   // accounts_t has a constructor that takes 2 iterators //amounts_size = declaring a variable with how many numbers in the amounts array, accounts also an object
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) ); // d_size = init a variable
	ints_t				deposits( d, d + d_size );         // deposits = building a vector from that range
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) ); // w_size = init a variable
	ints_t				withdrawals( w, w + w_size );      // withdrawals = building a vector from that range
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );//std::for_each(iterator first, iterator past the last, function) - an algorithm in <algorithm> - loop over a range of elements and apply fn to each element
																				     //std::mem_fun_ref = a fn that convert member function to function object("functor") 
																					 //                 = a helper that enable us to call a member function
																					 //                 = wraps a pointer to a member function into smthg can be used like a normal function object
																					 //                 = (&Class: function member) -> creates a callable object
																					 // conclusion - for_each iterates over each element - that calls that wrapper - that calls the actual member function
	for ( acc_int_t it( acc_begin, dep_begin );  // this line is initialization of it ('it' is used to point to both iterator) ('it' is just a variable name, short for 'iteration', could be called anything other than 'it')
		  it.first != acc_end && it.second != dep_end; // it.first → is an accounts_t::iterator (points to an Account)(basically is the accounts.begin() a.k.a. acc_begin), it.second = → is an ints_t::iterator (points to an int)(basically is the dep_begin)
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) ); // same as: it.first->makeDeposit(*it.second) 
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) ); // it.first → iterator to an Account, *it.first → the ACTUAL Account object by dereferencing it
	}                                                 // it.second → iterator to an int, *it.second → the ACTUAL deposit/withdrawal amount
													  // it = iterator/pointer, *it = REAL OBJECT . REMINDER, *(it.first) dosent replace void return type, its saying "who is calling the function?" -> Account. "which Account object should i call the function on?" -> it.second
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
