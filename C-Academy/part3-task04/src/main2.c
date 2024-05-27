#include <stdio.h>
#include <stdlib.h>

struct clientData
{
    int acctNum;
    char lastName[15];
    char firstName[10];
    float balance;
};

int enterChoice(void);
void textFile(FILE *);
void updateRecord(FILE *);
void newRecord(FILE *);
void deleteRecord(FILE *);

int main()
{
    FILE *fptr;
    int choice;

    if ((fptr = fopen("credit.dat", "w")) == NULL)
        printf("File coulf not be opened.\n");
    else
    {
        while ((choice = enterChoice()) != 5 )
        {
            switch (choice)
            {
            case 1 :
                textFile(fptr);
                break;
            case 2 :
                updateRecord(fptr);
                break;
            case 3:
                newRecord(fptr);
                break;
            case 4:
//                deleteRecord(fptr);
                break;
            }
        }
    }

    fclose(fptr);
    return 0;
}

void textFile(FILE *readPtr)
{
    FILE *writePtr;
    struct clientData client;

    if ((writePtr = fopen("accounts.txt", "w")) == NULL)
        printf("File could not be opened.\n");
    else
    {
      rewind(readPtr);
    fprintf(writePtr, "%-6s%-16s%-11s%10s\n",
            "Acct", "LAst NAme", "First Name", "Balance");

    while (!feof(readPtr))
    {
        fread(&client, sizeof(struct clientData), 1, readPtr);
        if (client.acctNum != 0)
            fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n",
                    client.acctNum, client.lastName,
                    client.firstName, client.balance);
    }
    }

    fclose(writePtr);
}

void updateRecord(FILE *fptr)
{
    int account;
    float transaction;
    struct clientData client;
    printf("Enter account to update (1-100): ");
    scanf("%d", &account);
    fseek(fptr, (account - 1) * sizeof(struct clientData), SEEK_SET);
    fread(&client, sizeof(struct clientData), 1, fptr);

    if (client.acctNum == 0)
        printf("Account #%d has no information.\n", account);
    else
    {
        printf("%-6d%-16s%-11s%10.2f\n\n",
               client.acctNum, client.lastName,
               client.firstName, client.balance);
        printf("Enter chrge (+) or payment (-): ");
        scanf("%f", &transaction);
        client.balance += transaction;
        printf("%-6d%-16s%-11s%10.2f\n",
               client.acctNum, client.lastName,
               client.firstName, client.balance);
        fseek(fptr, (account - 1) * sizeof(struct clientData), SEEK_SET);
        fwrite(&client, sizeof(struct clientData), 1, fptr);
    }
}

void newRecord(FILE *fptr)
{
    struct clientData client;
    int accountNum;
    printf("Enter new account number (1-100): ");
    scanf("%d", &accountNum);
    fseek(fptr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
    fread(&client, sizeof(struct clientData), 1, fptr);

    if (client.acctNum != 0)
        printf("Account #%d already contains information.\n", client.acctNum);
    else
    {
      printf("Enter lastname, firstname, balance\n? ");
      scanf("%s%s%f", client.lastName, client.firstName, &client.balance);
      client.acctNum = accountNum;
      fseek(fptr, (client.acctNum - 1) * sizeof(struct clientData), SEEK_SET);
      fwrite(&client, sizeof(struct clientData), 1, fptr);
    }
}

int enterChoice(void)
{
    int menuChoice;

    printf("\nEnter your choice\n"
           "1 - store a formatted text file of accounts called\n"
           "     \"accounts.txt\" for printing\n"
           "2 - update an account\n"
           "3 - add a new account\n"
           "4 - delete an account\n"
           "5 - end program\n? ");
    scanf("%d", &menuChoice);

    return menuChoice;
}
