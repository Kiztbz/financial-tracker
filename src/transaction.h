#ifndef TRANSACTION_H
#define TRANSACTION_H

#define MAX_DESCRIPTION 50
#define MAX_TYPE 10

typedef struct
{
    char description[MAX_DESCRIPTION];
    float amount;
    char type[MAX_TYPE]; // "Income" or "Expense"
} Transaction;

void addTransaction(Transaction transactions[], int *count);
void viewTransactions(Transaction transactions[], int count);
void calculateBalance(Transaction transactions[], int count);

#endif // TRANSACTION_H
