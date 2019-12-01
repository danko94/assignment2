#ifndef MYBANK_H_
#define MYBANK_H_

#define BANKACCOUNTS 50
#define BALANCE 0
#define STATUS 1
#define OPENED 1
#define CLOSED 0
#define DEPOSIT 1
#define WITHDRAWAL -1

#ifndef EXTERN
#define EXTERN
extern double bank[BANKACCOUNTS][2]; 
#endif

//bank init
void createBank();

//show options
void printOptions();

//Transactions O,B,...
void openAccount();
void checkBalance();
void makeDeposit();
void makeWithdrawal();
void closeAccount();
void printAccounts();
void addInterest();

//help functions
float getBalance(int);
float updateBalance(int, float);
int getOffset(int accNumber);
int getAccNumber();
int isClosed(int accNumber);
double getAmount(int DepositOrWithdrawal);





#endif /* MYBANK_H_ */
