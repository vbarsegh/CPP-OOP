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
#include <ctime>
#include <iostream>
class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts;//qani akaunt unenq es pahin
	static int	_totalAmount;//verjnakan qanaki vichakna,kaxvac gorcarqneric
	static int	_totalNbDeposits;//henc mihat gircarq exav esi ++enq anum
	static int	_totalNbWithdrawals;//henc mihat gircarq exav esi ++enq anum

	static void	_displayTimestamp( void );

	int				_accountIndex;//indexavorum enq accountmery
	int				_amount;//hashvi vra exac gumari qanaky orinak
	int				_nbDeposits;//skzbic 0 a vortev gorcarq der chi exel
	int				_nbWithdrawals;//skzbic 0 a vortev gorcarq der chi exel

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
