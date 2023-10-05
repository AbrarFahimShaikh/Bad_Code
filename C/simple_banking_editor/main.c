#include <stdio.h>
#include <stdlib.h>
struct Account{
  int accountNumber;
  char name[50];
  float balance;
};
void saveData(struct Account *accounts, int count){
  FILE *file = fopen("bank_data.txt","w");
  if(file==NULL){
    printf("Error file opening on writing (-_-) .\n");
    exit(1);
  }

  for(int i =0; i <count; i++){
    fprintf(file,"%d %s %.2f\n",accounts[i].accountNumber,accounts[i].name,accounts[i].balance);
    
  }
  fclose(file);
}
void loadData(struct Account *accounts, int *count){
  FILE* file = fopen("bank_data.txt","r");
  if(file==NULL){
    *count =0;
    return;
  }
  while (fscanf(file, "%d %s %f", &accounts[*count].accountNumber, accounts[*count].name, &accounts[*count].balance) != EOF) {
    (*count)++;
  }
  fclose(file);

}
void displayMenu(){
  printf("\n1.Add Account\n");
  printf("2.View Account \n");
  printf("3.Deposit Cash\n");
  printf("4.Withdraw Cash\n");
  printf("5.Delete Account\n");
  printf("6.Exit\n");
}

void depositCash(struct Account *accounts, int count){
  int accountNumber;
  float amount;
  printf("Enter account nunmber: ");
  scanf("%d",&accountNumber);
  int i;
  for(i = 0 ; i <count; i++){
    if(accounts[i].accountNumber==accountNumber){
      printf("Enter the amount to deposit: ");
      scanf("%f",&amount);
      accounts[i].balance+=amount;
      printf("Amount deposition done! ^_^\n");
      saveData(accounts,count);
      return;
    }

  }
  printf("Account not found!!\n");
}

void withdrawCash(struct Account *accounts,int count){
  int accountNumber;
  float amount;
  printf("Enter account number: ");
  scanf("%d",&accountNumber);

  int i;
  for(i=0;i<count;i++){
    if(accounts[i].accountNumber==accountNumber){
      printf("Enter amount to withdraw: ");
      scanf("%f",&amount);
      if(amount>accounts[i].balance){
        printf("Not enough cash bro!!\n");

      }
      else{
        accounts[i].balance -=amount;
        printf("Cash withdrawn!!\n");
        saveData(accounts,count);
      }
      return;
    }
  }
  printf("Account not found!!\n");
}

void deleteAccount(struct Account *accounts,int *count){
  int accountNumber;

  printf("Enter account number to delete: ");
  scanf("%d",&accountNumber);

  int i, found = 0;
  for(int i = 0 ;  i<*count;i++){
    if(accounts[i].accountNumber == accountNumber){
      found = 1;
      break;
    }
  }
  
  if (found){
    for(int j = i; j<*count-1;j++){
      accounts[j]=accounts[j+1];
    }
    (*count)--;
    printf("Account deleted!\n");
  } else{
    printf("Account not found.\n");
  }
}


int main(){
  struct Account accounts[100];
  int count = 0 ; 
  loadData(accounts,&count);
  int choice;

  do{
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        printf("Enter account number: ");
        scanf("%d",&accounts[count].accountNumber);
        printf("Enter Name: ");
        scanf("%s",accounts[count].name);
        printf("Enter balance: ");
        scanf("%f",&accounts[count].balance);
        count++;
        saveData(accounts,count);
        break;
      case 2:
        printf("\nAccount Details:\n");
        for(int i = 0 ; i <count; i++){
          printf("Account Number: %d\n",accounts[i].accountNumber);
          printf("Name: %s\n",accounts[i].name);
          printf("Balance: %.2f\n\n",accounts[i].balance);
        }
        break;
      case 3:
        depositCash(accounts,count);
        break;

      case 4:
        withdrawCash(accounts,count);
        break;

      case 5:
        deleteAccount(accounts,&count);
        break;
      case 6:
        printf("Exiting...\n");
        break;
      default:
        printf("Choice is invalid, Please try again\n");
    }
  }while(choice!=6);
  return 0;
}
