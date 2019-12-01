#ifndef MYBANK_H_
#define MYBANK_H_

#define BANKACCOUNTS 50
#define BALANCE 0
#define STATUS 1
#define OPENED 1
#define CLOSED 0
#define DEPOSIT 1
#define WITHDRAWAL -1

#ifndef BANK_DEF
extern double bank[BANKACCOUNTS][2]; 
#endif /* BANK_DEF */

//bank init
void createBank();

//show options
void printOptions();

//Transactions O,B,D,...
void openAccount();
void checkBalance();
void makeDeposit();
void makeWithdrawal();
void closeAccount();
void printAccounts();
void addInterest();

//help functions
double getBalance(int);
double updateBalance(int, double);
int getOffset(int);
int getAccNumber();
int isClosed(int);
double getAmount(int);





#endif /* MYBANK_H_ */
