#include <stdio.h>
#include "myBank.h"

#define EXTERN

int main(){
	createBank();

	char choice = 'e';
	printOptions();
	
	while(choice!='E'){
	  printf("\nTransaction type: \n");
	  scanf(" %c", &choice);	  
	  

	  switch(choice){

	  case 'O':
	    openAccount();
	    break;
	  case 'B':	    
	    checkBalance();
	    break;
	  case 'D':
	    makeDeposit();
	    break;
	  case 'W':
	    makeWithdrawal();
	    break;
	  case 'C':
	    closeAccount();
	    break;
	  case 'P':
	    printAccounts();
	    break;
	  case 'I':
	  	addInterest();
		  break;
	  case 'E':
	  	break;	 
	  case 'H':
	  	printOptions();
		break;
	  default:
	  	printf("Not a valid action!\n");
		break;
	  }
	}

	printf("Program terminated. Good bye!\n");
}
