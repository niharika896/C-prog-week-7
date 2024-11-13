#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int customer_count = 0; //global variable

struct customer {
    int account_number;
    char name[50];
    int balance;
};

int isAccountNumberUnique(int account_number, struct customer *bank) {  //single * because we will be passing bank which is an array that contains all the structures
    for (int i = 0; i < customer_count; i++) {                          //we will be passing starting address of bank and *bank is the first structure 
        if (bank[i].account_number == account_number) {                //now here bank refers to the array bank and can be used like a normal array
            return 0; // Account number is not unique
        }
    }
    return 1; // Account number is unique
}

void addCustomer(struct customer **bank) { //here we are passing the address of the address of bank because this time realloc function
    int account_number;                    //will be used which will play with the address of bank
    int unique = 0;
    while (!unique) {
        printf("Enter account number: ");
        scanf("%d", &account_number);
        fflush(stdin);

        // Check if the account number is unique
        unique = isAccountNumberUnique(account_number, *bank); //int isAccountNumberUnique(int account_number, struct customer *bank)
        if (!unique) {                                            // *bank is the address of bank in addCustomer is passed to isAccountNumberUnique
            printf("Account number already exists. Please enter a unique account number.\n");
            addCustomer(bank);
        }
    }

    *bank = realloc(*bank, (customer_count + 1) * sizeof(struct customer));

    (*bank)[customer_count].account_number = account_number;

    printf("Enter name: ");
    scanf("%[^\n]s", (*bank)[customer_count].name);
    fflush(stdin);

    printf("Enter balance: ");
    scanf("%d", &(*bank)[customer_count].balance);
    fflush(stdin);

    customer_count++;
}

int processTransaction(int account_number, int transaction_type, int amount, struct customer **bank) {
    int customer_index = -1;
    for (int i = 0; i < customer_count; i++) {
        if ((*bank)[i].account_number == account_number) {
            customer_index = i;
            break;
        }
    }

    if (customer_index == -1) {
        printf("Account not found.\n");
        return 0;
    }

    if (transaction_type == 0) { // Deposit
        (*bank)[customer_index].balance += amount;
        printf("Transaction successful! Updated customer record:\n");
        printf("Account Number: %d\nName: %s\nBalance: %d\n", (*bank)[customer_index].account_number, (*bank)[customer_index].name, (*bank)[customer_index].balance);
        return 1;
    }
    else if (transaction_type == 1) { // Withdrawal
        if ((*bank)[customer_index].balance >= amount) {
            (*bank)[customer_index].balance -= amount;
            printf("Transaction successful! Updated customer record:\n");
            printf("Account Number: %d\nName: %s\nBalance: %d\n", (*bank)[customer_index].account_number, (*bank)[customer_index].name, (*bank)[customer_index].balance);
            return 1;
        } else {
            printf("Insufficient Balance\n");
            return 0;
        }
    } else {
        printf("Invalid transaction type. Please enter 0 for DEPOSIT or 1 for WITHDRAWAL.\n");
        printf("0: DEPOSIT\t1: WITHDRAWAL\n");
        scanf("%d", &transaction_type);
        return processTransaction(account_number, transaction_type, amount, bank); // Recursive call
    }
}

int main() {
    struct customer *bank = (struct customer *)malloc(10 * sizeof(struct customer));

    printf("Setting up system\n");
    for (int i = 0; i < 1; i++) {
        addCustomer(&bank);
    }

    printf("Taking Five new entries\n");
    for (int i = 0; i < 1; i++) {
        addCustomer(&bank);
    }

    printf("Welcome to ABC Bank\n");

    int account_number, transaction_type, amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("0: DEPOSIT\t1: WITHDRAWAL\n");
    scanf("%d", &transaction_type);
    printf("Enter Amount: ");
    scanf("%d", &amount);

    int status = processTransaction(account_number, transaction_type, amount, &bank);
    if (status == 1) {
        printf("Records Successfully Updated\n");
    } else {
        printf("Transaction Failed\n");
    }

    free(bank);
    return 0;
}
