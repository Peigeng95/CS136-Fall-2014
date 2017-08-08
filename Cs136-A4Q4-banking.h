// banking.h
#include <stdbool.h>
/*----------------------------------------------------------------------------
 * This module allows you to perform a series of banking transactions 
 * (deposits and withdrawals) on one or more bank account structures, and keeps 
 * track of relevant statistics for the current active account.  
 *----------------------------------------------------------------------------*/
struct bank_acct {
   int id; // id is an account number, and is positive.
   int balance; // balance is in cents, to avoid the inaccuracies of floats. 
};

// returns an bank account (bank_acct structure) with the provided id and balance.
// PRE: new_id > 0, new_bal >= 0
// POST: returns a bank_acct with id = new_id,  balance = new_bal
struct bank_acct create_acct(int new_id, int new_bal);


// Sets the active account to be acct.
// PRE: acct != NULL
// POST: the active account is changed, and the internal statistics are reset 
void set_active_acct(struct bank_acct *acct);


// Deposits amt cents to the active account.  
//PRE: amt > 0, there is an active account
//POST: the active account's balance is updated, as are the internal statistics
void deposit(int amt);


// Attempts to remove amt cents from the active account.  
// If the balance is not great enough, the transaction does not complete 
// (no money is withdrawn, and this does not count as a transaction).
// Returns whether or not the transaction completed succesfully.
//PRE:  amt > 0, there is an active account
//POST: If the active account has balance >= amt, its balance is decreased and 
// the internal statistics are updated.  If not there are no changes to the state.
bool withdraw(int amt);


// Returns the largest successful withdrawal made since the current active account was set.  
// Returns 0 if there have been no successful withdrawals
// PRE: there is an active account
// POST: return value >= 0
int max_withdrawal(void);


// Returns the largest deposit made since the curent active account was set. 
// Returns 0 if there have been no deposits.
// PRE: there is an active account
// POST: return value >= 0
int max_deposit(void);


// Get the number of successful transactions since the current active account was set
// PRE: there is an active account
// POST: return value >= 0
int transaction_count(void);
