#include <stdio.h>

struct account {
   int account_number;
   char name[30];
   float balance;
};

void create_account(struct account *ptr) {
   printf("Enter account number: ");
   scanf("%d", &ptr->account_number);
   printf("Enter name: ");
   scanf("%s", ptr->name);
   printf("Enter initial balance: ");
   scanf("%f", &ptr->balance);
   printf("Account created successfully.\n\n");
}

void deposit(struct account *ptr) {
   float amount;
   printf("Enter deposit amount: ");
   scanf("%f", &amount);
   ptr->balance += amount;
   printf("Deposit successful. New balance is %.2f\n\n", ptr->balance);
}

void withdraw(struct account *ptr) {
   float amount;
   printf("Enter withdrawal amount: ");
   scanf("%f", &amount);
   if (amount > ptr->balance) {
      printf("Insufficient balance.\n\n");
   } else {
      ptr->balance -= amount;
      printf("Withdrawal successful. New balance is %.2f\n\n", ptr->balance);
   }
}

void view_balance(struct account *ptr) {
   printf("Account number: %d\n", ptr->account_number);
   printf("Name: %s\n", ptr->name);
   printf("Balance: %.2f\n\n", ptr->balance);
}

int main() {
   int choice;
   struct account customer;
   while (1) {
      printf("1. Create account\n");
      printf("2. Deposit\n");
      printf("3. Withdraw\n");
      printf("4. View balance\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            create_account(&customer);
            break;
         case 2:
            deposit(&customer);
            break;
         case 3:
            withdraw(&customer);
            break;
         case 4:
            view_balance(&customer);
            break;
         case 5:
            return 0;
         default:
            printf("Invalid choice.\n\n");
      }
   }
}
