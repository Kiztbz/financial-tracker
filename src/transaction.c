#include <stdio.h>
#include <string.h>
#include "transaction.h"
#define MAX_TRANSACTIONS 100

void addTransaction(Transaction transactions[], int *count)
{
    if (*count >= MAX_TRANSACTIONS)
    {
        printf("\nTransaction limit reached. Cannot add more.\n");
        return;
    }

    Transaction t;

    printf("\nEnter description: ");
    scanf(" %[^\n]s", t.description);

    printf("Enter amount: ");
    scanf("%f", &t.amount);

    printf("Enter type (Income/Expense): ");
    scanf("%s", t.type);

    if (strcmp(t.type, "Income") != 0 && strcmp(t.type, "Expense") != 0)
    {
        printf("Invalid type! Please enter either 'Income' or 'Expense'.\n");
        return;
    }

    transactions[*count] = t;
    (*count)++;

    printf("\nTransaction added successfully!\n");
}

void viewTransactions(Transaction transactions[], int count)
{
    if (count == 0)
    {
        printf("\nNo transactions to show.\n");
        return;
    }

    printf("\nTransaction History:\n");
    printf("-----------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Description", "Amount", "Type");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("| %-20s | %-10.2f | %-10s |\n",
               transactions[i].description, transactions[i].amount, transactions[i].type);
    }

    printf("-----------------------------------------------\n");
}

void calculateBalance(Transaction transactions[], int count)
{
    float balance = 0.0;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(transactions[i].type, "Income") == 0)
        {
            balance += transactions[i].amount;
        }
        else if (strcmp(transactions[i].type, "Expense") == 0)
        {
            balance -= transactions[i].amount;
        }
    }

    printf("\nTotal Balance: %.2f\n", balance);
}
