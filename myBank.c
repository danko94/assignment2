
#include <stdio.h>
#include "myBank.h"

double bank[BANKACCOUNTS][2];

void createBank()
{ //initialize array, set all fields to 0
  for (int i = 0; i < 50; i++)
  {
    bank[i][BALANCE] = 0;
    bank[i][STATUS] = CLOSED;
  }
  return;
}

/**
 * primary (user action) functions
 */

void openAccount()
{ //'O' - action

  int accNumber = -1;
  float depositAmount = 0;
  for (int i = 0; i < BANKACCOUNTS; i++)
  {
    if (bank[i][STATUS] == CLOSED)
    {
      accNumber = i;
      bank[i][STATUS] = OPENED;
      break;
    }
  }
  if (accNumber == -1)
  { //No closed account was found
    printf("Could not open an account!\n");
    return;
  }
  else
  {
    printf("Account opening was successful! Your Account number is: %d\n", accNumber + 901);
    printf("Enter your initial deposit: \n");
    depositAmount = getAmount(DEPOSIT);
    bank[accNumber][BALANCE] = depositAmount;
    return;
  }
}

void checkBalance()
{ //'B' - action

  int accNumber = getAccNumber();

  if (isClosed(accNumber))
  {
    return;
  }
  else
  {
    printf("Your current balance is: %.2f\n", getBalance(accNumber));
    return;
  }
}

void makeDeposit()
{ //'D' - action

  int accNumber = getAccNumber();
  float depositAmount = 0;

  if (isClosed(accNumber))
  {
    return;
  }
  else
  {
    printf("Enter deposit amount: \n");
    depositAmount = getAmount(DEPOSIT);
    printf("Your new balance is %.2f!\n", updateBalance(accNumber, depositAmount));
    return;
  }
}

void makeWithdrawal()
{ //'W' - action

  int accNumber = getAccNumber();
  double currentBalance = getBalance(accNumber);
  if (currentBalance==0)  
  {
    printf("Withdrawal not possible! You don't have any money in your account! \n");
    return;
  }
  
  double withdrawalAmount = currentBalance + 1;

  if (isClosed(accNumber))
  {
    return;
  }
  else
  {
    printf("Enter withdrawal amount: \n");
    while ((currentBalance - withdrawalAmount) < 0)
    {
      withdrawalAmount = getAmount(WITHDRAWAL);
      if ((currentBalance - withdrawalAmount) < 0)
      {
        printf("You don't have enough money in your bank account!(Current balance: %.2lf) \nEnter valid amount:\n", currentBalance);
      }
      
    }
    printf("Your new balance is %.2lf!\n", updateBalance(accNumber, -withdrawalAmount));
    return;
  }
}

void closeAccount()
{ //'C' - action

  int accNumber = getAccNumber();

  if (isClosed(accNumber))
  {
    return;
  }
  else
  {
    bank[getOffset(accNumber)][STATUS] = CLOSED;
    bank[getOffset(accNumber)][BALANCE] = 0;
    printf("Your account (no.%d) has been closed!\n", accNumber);
    return;
  }
}

void printAccounts()
{ //'P' - action

  for (int i = 0; i < BANKACCOUNTS; i++)
  {
    int accNumber = 901 + i;
    if (bank[i][STATUS] == OPENED)
    {
      printf("Account no. %d, Balance: %.2f\n", accNumber, getBalance(accNumber));
    }
  }

  return;
}

void addInterest()
{ //'I' - action

  double interestRate = 0;
  printf("Enter interest rate in percent: \n");

  for (;;)
  {
    scanf(" %lf", &interestRate);
    if ((interestRate>=0))
    {
      interestRate = 1 + (interestRate / 100);  // example: 5% -> 1.05
      for (int i = 0; i < BANKACCOUNTS; i++)
      {
        if (bank[i][OPENED])
        {
          bank[i][BALANCE] *= interestRate;
        }
      }
      break;
    }
    else
    {
      printf("Entered rate is not valid. Please try again: \n");
      //scanf(" %lf", &interestRate); delete this line??
    }
  }
  printf("Bank account balances have been updated!\n");
}

/**
 * added functionality, print transaction options
 */

  void printOptions()
  //H - action
  {
    printf("Open account: \t\t O \nCheck Balance: \t\t B \nMake Deposit: \t\t D \nMake Withdrawal: \t W \nClose Account: \t\t C \nPrint accounts: \t P \nAdd Interest: \t\t I \nShow options: \t\t H \n\nExit: \t\t\t E \n");
    return;
  }

/**
  * secondary functions
  */

int getOffset(int accNumber)
{

  return accNumber - 901;
}

int getAccNumber()
{

  int accNumber = 0;
  for (;;)
  {
    printf("Please enter your account number: \n");
    scanf(" %d", &accNumber);
    if ((accNumber >= 901) && (accNumber < 951))
    {
      break;
    }
    printf("Not a valid account number!\n");
  }

  return accNumber;
}

float getBalance(int accNumber)
{

  int accountOffset = getOffset(accNumber);
  return bank[accountOffset][BALANCE];
}

float updateBalance(int accNumber, float updateAmount)
{

  int accountOffset = getOffset(accNumber);
  float balance = getBalance(accNumber);
  float newBalance = balance + updateAmount;
  bank[accountOffset][BALANCE] = newBalance;
  return newBalance;
}

int isClosed(int accNumber)
{

  int accountOffset = getOffset(accNumber);
  if (bank[accountOffset][STATUS] == CLOSED)
  {
    printf("Transaction could not be performed. The account (no.%d) is closed\n", accNumber);
    return 1;
  }
  else
  {
    return 0;
  }
}

double getAmount(int DepositOrWithdrawal)
{
  double amount = 0;

  for (;;)
  {
    scanf(" %lf", &amount);

    if ((amount < 0) && (DepositOrWithdrawal == WITHDRAWAL))
    {
      printf("Enter valid Withdrawal amount! \n");
    }
    else
    {
      if ((amount < 0) && (DepositOrWithdrawal == DEPOSIT))
      {
        printf("Enter valid Deposit amount! \n");
      }
      else
      {
        break;
      }
    }
  }
  return amount;
}
