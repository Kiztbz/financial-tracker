// main.c
#include <stdio.h>
#include <stdlib.h>
#include "transaction.h"

#define MAX_TRANSACTIONS 100

int main()
{
    Transaction transactions[MAX_TRANSACTIONS];
    int count = 0;
    int choice;

    while (1)
    {
        printf("\nFinancial Tracker\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Calculate Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTransaction(transactions, &count);
            break;
        case 2:
            viewTransactions(transactions, count);
            break;
        case 3:
            calculateBalance(transactions, count);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}