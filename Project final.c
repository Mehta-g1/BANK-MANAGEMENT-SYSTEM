/* This code is developed by @mehta-g1 and @ajitkumargupta01 */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define MAX_ACCOUNTS 20

struct Account
{
    int id;
    char mob[10];
    int pass;
    char name[20];
    int account_num;
    char acc_type[20];
    float balance;
};
void openAccount(struct Account *person, int *i, int *auto_acc_num);
void deposit(struct Account *person, int i);
void withdraw(struct Account *person, int i);
void checkBalance(struct Account *person, int i);
void displayDetails(struct Account *person, int i);
void changePassword(struct Account *person, int i);
void forgotPassword(struct Account *person, int i);
void saveAccountDetails_file(struct Account person[], int j, int i);
void loadAccountDetails(struct Account *person, int *i);
void delay(int milliseconds);
void heading();
void saveTransactionDetails_file(int acc, float amount, char tran_category, float rem_balance);
void printTransationsDetails_file(int acc);
void transactionHeading_file(int acc);
int generateRandom4Digit();
void heading()
{
    printf("\033[35m");
    printf("\n\t\t\t---------------------------------------------------------------------\n");
    printf("\033[0m");
    printf("\t\t\t\t\t\t\033[34mBANK MANAGEMENT SYSTEM\033[0m");
    printf("\033[35m");
    printf("\n\t\t\t---------------------------------------------------------------------\n");
    printf("\033[0m");
}

int main()
{

    int choice, i = 0, auto_acc_num = 21051120;
    struct Account person[MAX_ACCOUNTS];
    loadAccountDetails(person, &i);
    while (1)
    {
        system("cls");
        heading();
        printf("\n\t\t\t       HOME       ");
        printf("\033[33m");
        printf("\n\t\t\t------------------\033[0m");
        printf("\033[1m\033[36m");

        printf("\t\t\t\t\tOpened Accounts: %d", i);
        printf("\n\n\t\t\t1. Open New Account\n");
        printf("\t\t\t2. Deposit\n");
        printf("\t\t\t3. Withdraw\n");
        printf("\t\t\t4. Balance Check\n");
        printf("\t\t\t5. Customer Details and Transactions\n");
        printf("\t\t\t6. Change Password\n");
        printf("\t\t\t7. Forgot Password\n");
        printf("\t\t\t8. Exit\n");
        printf("\n\t\tEnter your choice: ");
        printf("\033[0m");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            openAccount(person, &i, &auto_acc_num);
            break;
        case 2:
            deposit(person, i);
            break;
        case 3:
            withdraw(person, i);
            break;
        case 4:
            checkBalance(person, i);
            break;
        case 5:
            displayDetails(person, i);
            break;
        case 6:
            changePassword(person, i);
            break;
        case 7:
            forgotPassword(person, i);
            break;
        case 8:
            system("cls");
            printf("\nExiting...\n");
            return 0;
        default:
        	system("cls");
   			heading();
            printf("\n\t\t\033[31mInvalid option! Please try again.\033[0m\n");
            getch();
        }
    }
}

void transactionHeading_file(int acc)
{
    FILE *fp;
    char filename[20];
    sprintf(filename, "%d.txt", acc);
    fp = fopen(filename, "w");
    if (fp != NULL)
    {
        //	fprintf(fp,"\n\t\t\tAccount Number: %d\n\n",acc);
        fprintf(fp, "\tDate & Time\t\t\tDeposit\t\tWithdrawal\t\tRemaining balance\n\n");
    }
    fclose(fp);
}

void printTransationsDetails_file(int acc)
{
    FILE *fp;
    char filename[20];
    char ch;
    sprintf(filename, "%d.txt", acc);
    fp = fopen(filename, "r");
    if (fp != NULL)
    {
        while (1)
        {
            ch = getc(fp);
            if (ch == EOF)
                return;
            printf("%c", ch);
        }
    }
}

void saveTransactionDetails_file(int acc, float amount, char tran_category, float rem_balance)
{
    FILE *fp;
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    char filename[20];
    sprintf(filename, "%d.txt", acc);
    fp = fopen(filename, "a");
    if (fp != NULL)
    {
        if (tran_category == 'd')
        {
            fprintf(fp, "\t%d-%d-%d %d:%d\t\t%.2f\t\t\t\t\t%.2f\n", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900, local->tm_hour, local->tm_min, amount, rem_balance);
        }
        else
        {
            fprintf(fp, "\t%d-%d-%d %d:%d\t\t\t\t%.2f\t\t\t%.2f\n", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900, local->tm_hour, local->tm_min, amount, rem_balance);
        }
        fclose(fp);
    }
}

void loadAccountDetails(struct Account *person, int *i)
{

    FILE *fp;
    char filename[50];
    int j = 0;

    while (1)
    {
        sprintf(filename, "%d.txt", j);
        fp = fopen(filename, "r");

        if (fp == NULL)
        {
            break;
        }
        fscanf(fp, "\n\t\t\t       Customer Details         ");
        fscanf(fp, "\n\t\t\t------------------------------\n\n");
        fscanf(fp, "\tAccount number\t: %d\n", &person[j].account_num);
        fscanf(fp, "\tAccount holder\t: %[^\n]\n", &person[j].name);
        fscanf(fp, "\tMobile number\t: %s\n", &person[j].mob);
        fscanf(fp, "\tAccount type\t: %[^\n]\n", person[j].acc_type);
        fscanf(fp, "\tPassword\t: %d\n", &person[j].pass);
        fscanf(fp, "\tCustomer ID\t: %d\n", &person[j].id);
        fscanf(fp, "\tCurrent balance\t: INR %f\n", &person[j].balance);
        fclose(fp);

        j++;
    }
    *i = j;
}

void saveAccountDetails_file(struct Account person[], int j,int i)
{
    FILE *fp;
    char filename[50];
    sprintf(filename, "%d.txt", j);
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        //printf("File Not Opened !");
        return;
    }
    else
    {
        fprintf(fp, "\n\t\t\t       Customer Details         ");
        fprintf(fp, "\n\t\t\t------------------------------\n\n");
        fprintf(fp, "\tAccount number\t: %d\n", person[j].account_num);
        fprintf(fp, "\tAccount holder\t: %s\n", person[j].name);
        fprintf(fp, "\tMobile number\t: %s\n", person[j].mob);
        fprintf(fp, "\tAccount type\t: %s\n", person[j].acc_type);
        fprintf(fp, "\tPassword\t: %d\n", person[j].pass);
        fprintf(fp, "\tCustomer ID\t: %d\n", person[j].id);
        fprintf(fp, "\tCurrent balance\t: INR %.2f\n", person[j].balance);
        fclose(fp);
    }
}

void openAccount(struct Account *person, int *i, int *auto_acc_num)
{

    static int customer_id = 235816;
    char acc_mob[10];
    system("cls");
    heading();
    printf("\n\t\t\t       Open New Account       ");
    printf("\033[33m");
    printf("\n\t\t\t------------------------------\n\n\033[0m");
    printf("\tEnter your name: ");
    fflush(stdin);
    gets(person[*i].name);
    printf("\tEnter your mobile number: ");
    fflush(stdin);
    gets(acc_mob);
    if (strlen(acc_mob) != 10)
    {
        printf("\033[31m\t\tInvalid Mobile Number.\033[0m \n \tEnter valid Mobile number: \033[0m");
        gets(person[*i].mob);
    }
    strcpy(person[*i].mob, acc_mob);
    printf("\tEnter account type (\033[31mSaving OR Current\033[0m): ");
    fflush(stdin);
    gets(person[*i].acc_type);

    printf("\tEnter opening balance: ");
    scanf("%f", &person[*i].balance);

    person[*i].id = customer_id + (*i);

    printf("\tCreate your password (\033[31mInteger only\033[0m) for withdrawals: ");
    scanf("%d", &person[*i].pass);
    person[*i].account_num = *auto_acc_num + *(i);
    printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
    delay(15);
    system("cls");
    heading();
    printf("\n\t\t\t       Open New Account");
    printf("\033[33m\n\t\t\t------------------------------\n\n\033[0m");
    printf("\033[1m\033[33m\tAccount number\t: \033[0m\033[32m\033[4m%d\033[0m \n", person[*i].account_num);
    printf("\033[1m\033[33m");
    printf("\tAccount holder\t: %s\n", person[*i].name);
    printf("\tMobile number\t: %s\n", person[*i].mob);
    printf("\tAccount type\t: %s\n", person[*i].acc_type);
    printf("\tPassword\t: \033[4m%d\n\033[0m", person[*i].pass);
    printf("\033[1m\033[33m\tCustomer ID\t: \033[0m\033[32m\033[4m%d\033[0m \n", person[*i].id);
    printf("\033[1m\033[33m");
    printf("\tOpening balance\t: INR %.2f\n", person[*i].balance);
    printf("\033[0m");
    printf("\n\033[32m\tAccount opened successfully.\n\033[0m");
    saveAccountDetails_file(person, *i, *i);
    transactionHeading_file(person[*i].account_num);
    if (person[*i].balance > 0)
    {
        saveTransactionDetails_file(person[*i].account_num, person[*i].balance, 'd', person[*i].balance);
    }
    (*i)++;
    printf("\n\n\t\t\tPress any key for HOME");
    getch();
}

void deposit(struct Account *person, int i)
{
    int acc_num, j, flag = 0;
    float deposit_amount;

    system("cls");
    heading();
    printf("\n\t\t\t       Amount Deposit         ");
    printf("\033[33m");
    printf("\n\t\t\t------------------------------\n\n\033[0m");
    printf("\tEnter account number to deposit: ");
    scanf("%d", &acc_num);

    for (j = 0; j < i; j++)
    {
        if (acc_num == person[j].account_num)
        {
            printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
            delay(8);
            system("cls");
            heading();
            printf("\n\t\t\t       Amount Deposit         ");
            printf("\033[33m");
            printf("\n\t\t\t------------------------------\n\n\033[0m");
            printf("\tAccount holder: %s\n", person[j].name);
            printf("\tEnter amount to deposit: ");
            scanf("%f", &deposit_amount);

            person[j].balance += deposit_amount;
            printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
            delay(3);
            system("cls");
            heading();
            printf("\n\t\t\t       Amount Deposit         ");
            printf("\033[33m");
            printf("\n\t\t\t------------------------------\n\n\033[0m");
            printf("\n\033[32m\t    INR %.2f deposit successfully.\n\033[0m", deposit_amount);
            saveTransactionDetails_file(person[j].account_num, deposit_amount, 'd', person[j].balance);
            saveAccountDetails_file(person, j, j);
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
        delay(20);
        system("cls");
        heading();
        printf("\n\t\t\t       Amount Deposit         ");
        printf("\033[33m");
        printf("\n\t\t\t------------------------------\n\n\033[0m");
        printf("\n\033[31m\tAccount number not found! Please try again.\n\033[0m");
    }
    printf("\n\n\t\t\tPress any key for HOME");
    getch();
}

void withdraw(struct Account *person, int i)
{
    int acc_num, acc_pass, j, attempts, flag = 0;
    float withdraw_amount;

    system("cls");
    heading();
    printf("\n\t\t\t       Amount Withdraw         ");
    printf("\033[33m");
    printf("\n\t\t\t------------------------------\n\n\033[0m");
    printf("\tEnter account number to withdraw from: ");
    scanf("%d", &acc_num);

    for (j = 0; j < i; j++)
    {
        if (acc_num == person[j].account_num)
        {
            printf("\tAccount holder: %s\n", person[j].name);
            flag = 1;

            for (attempts = 3; attempts > 0; attempts--)
            {
                printf("\tEnter your password: ");
                scanf("%d", &acc_pass);

                if (acc_pass == person[j].pass)
                {
                    printf("\tEnter withdraw amount: ");
                    scanf("%f", &withdraw_amount);

                    if (withdraw_amount <= person[j].balance)
                    {
                        person[j].balance -= withdraw_amount;
                        printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
                        delay(15);
                        system("cls");
                        heading();
                        printf("\n\t\t\t       Amount Withdraw         ");
                        printf("\033[33m");
                        printf("\n\t\t\t------------------------------\n\n\033[0m");
                        printf("\n\033[32m\tBalance withdrawal successful.\n\t\033[0m \033[36mRemaining balance:INR %.2f\n\033[0m", person[j].balance);
                        saveTransactionDetails_file(person[j].account_num, withdraw_amount, 'w', person[j].balance);
                        saveAccountDetails_file(person, j, j);
                    }
                    else
                    {
                        printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
                        delay(15);
                        system("cls");
                        heading();
                        printf("\n\t\t\t       Amount Withdraw         ");
                        printf("\033[33m");
                        printf("\n\t\t\t------------------------------\n\n\033[0m");
                        printf("\033[31m\t\tInsufficient balance.\n\033[0m");
                    }
                    break;
                }
                else
                {
                    printf("\033[31m\tWrong password! Remaining %d attempt.\n\033[0m", attempts - 1);
                }
            }
            break;
        }
    }
    if (!flag)
    {
        printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
        delay(20);
        system("cls");
        heading();
        printf("\n\t\t\t       Amount Withdraw         ");
        printf("\033[33m");
        printf("\n\t\t\t------------------------------\n\n\033[0m");
        printf("\033[31m\tAccount number not found! Please try again.\n\033[0m");
    }
    printf("\n\n\t\t\tPress any key for HOME");
    getch();
}

void checkBalance(struct Account *person, int i)
{
    int acc_num, acc_pass, j, attempts, flag = 0;

    system("cls");
    heading();
    printf("\n\t\t\t       Balance Enquiry         ");
    printf("\033[33m");
    printf("\n\t\t\t------------------------------\n\n\033[0m");
    printf("\tEnter your account number: ");
    scanf("%d", &acc_num);

    for (j = 0; j < i; j++)
    {
        if (acc_num == person[j].account_num)
        {
            flag = 1;
            printf("\tAccount holder: %s\n", person[j].name);
            for (attempts = 3; attempts > 0; attempts--)
            {
                printf("\tEnter your password: ");
                scanf("%d", &acc_pass);

                if (acc_pass == person[j].pass)
                {
                    printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
                    delay(10);
                    system("cls");
                    heading();
                    printf("\n\t\t\t       Balance Enquiry         ");
                    printf("\033[33m");
                    printf("\n\t\t\t------------------------------\n\n\033[0m");
                    printf("\033[36m\tCurrent balance: INR %.2f\n\033[0m", person[j].balance);
                    break;
                }
                else
                {
                    printf("\033[31m\tWrong password! Remaining %d attempt.\n\033[0m", attempts - 1);
                }
            }
            break;
        }
    }
    if (!flag)
    {
        printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
        delay(20);
        system("cls");
        heading();
        printf("\n\t\t\t       Balance Enquiry         ");
        printf("\033[33m");
        printf("\n\t\t\t------------------------------\n\n\033[0m");
        printf("\033[31m\tAccount number not found! Please try again.\n\033[0m");
    }
    printf("\n\n\t\t\tPress any key for HOME");
    getch();
}

void displayDetails(struct Account *person, int i)
{
    int acc_num, acc_pass, j, attempts, flag = 0;

    system("cls");
    heading();
    printf("\n\t\t\t       Customer Detail and Transactions         ");
    printf("\033[33m");
    printf("\n\t\t\t------------------------------------------------\n\n\033[0m");
    printf("\tEnter your account number: ");
    scanf("%d", &acc_num);

    for (j = 0; j < i; j++)
    {
        if (acc_num == person[j].account_num)
        {
            flag = 1;
            for (attempts = 3; attempts > 0; attempts--)
            {
                printf("\tEnter your password: ");
                scanf("%d", &acc_pass);
                if (acc_pass == person[j].pass)
                {
                    printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
                    delay(15);
                    system("cls");
                    heading();
                    printf("\n\t\t\t       Customer Detail and Transactions        ");
                    printf("\033[33m");
                    printf("\n\t\t\t--------------------------------------------\n\n\033[0m");
                    printf("\033[1m\033[33m\tAccount number\t: \033[0m\033[32m\033[4m%d\033[0m \n", person[j].account_num);
                    printf("\033[1m\033[33m");
                    printf("\tAccount holder\t: %s\n", person[j].name);
                    printf("\tMobile number\t: %s\n", person[j].mob);
                    printf("\tAccount type\t: %s\n", person[j].acc_type);
                    printf("\tPassword\t: %d\n", person[j].pass);
                    printf("\t\033[33mCustomer ID\t: %d\n", person[j].id);
                    printf("\tCurrent balance\t: INR %.2f\n\n\n", person[j].balance);
                    printf("\033[0m");
                    printf("\t\t\tTransactions\n");
                    printf("\t\033[33m--------------------------------------------\n\n\033[0m");
                    printTransationsDetails_file(person[j].account_num);
                    break;
                }
                else
                {
                    printf("\033[31m\tWrong password! Remaining %d attempt.\n\033[0m", attempts - 1);
                }
            }
            break;
        }
    }
    if (!flag)
    {
        printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
        delay(20);
        system("cls");
        heading();
        printf("\n\t\t\t       Customer Details         ");
        printf("\033[33m");
        printf("\n\t\t\t------------------------------\n\n\033[0m");
        printf("\033[31m\tAccount number not found! Please try again.\n\033[0m");
    }
    printf("\n\n\t\t\tPress any key for HOME");
    getch();
}

void changePassword(struct Account *person, int i)
{
    int acc_num, acc_pass, j, attempts, new_password, flag = 0;

    system("cls");
    heading();
    printf("\n\t\t\t       Password Change         ");
    printf("\033[33m");
    printf("\n\t\t\t------------------------------\n\n\033[0m");
    printf("\tEnter your account number: ");
    scanf("%d", &acc_num);

    for (j = 0; j < i; j++)
    {
        if (acc_num == person[j].account_num)
        {
            flag = 1;
            printf("\tAccount holder: %s\n", person[j].name);
            for (attempts = 3; attempts > 0; attempts--)
            {
                printf("\tEnter your old password: ");
                scanf("%d", &acc_pass);

                if (acc_pass == person[j].pass)
                {
                    printf("\tEnter new password (\033[31mInteger only\033[0m): ");
                    scanf("%d", &new_password);
                    person[j].pass = new_password;
                    printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
                    delay(10);
                    system("cls");
                    heading();
                    printf("\n\t\t\t       Password Change         ");
                    printf("\033[33m");
                    printf("\n\t\t\t------------------------------\n\n\033[0m");
                    printf("\n\033[32m\tPassword changed.\033[0m\n");
                    saveAccountDetails_file(person, j, i);
                    break;
                }
                else
                {
                    printf("\033[31m\tWrong password! Remaining %d attempt.\n\033[0m", attempts - 1);
                }
            }
            break;
        }
    }
    if (!flag)
    {
        printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
        delay(20);
        system("cls");
        heading();
        printf("\n\t\t\t       Password Change         ");
        printf("\033[33m");
        printf("\n\t\t\t------------------------------\n\n\033[0m");
        printf("\033[31m\tAccount number not found! Please try again.\n\033[0m");
    }
    printf("\n\n\t\t\tPress any key for HOME");
    getch();
}

void delay(int milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 10)
        ;
}

void forgotPassword(struct Account *person, int i)
{
    int acc_num, customer_id, new_password, j, flag = 0;

    system("cls");
    heading();
    printf("\n\t\t\t       Password Forgot         ");
    printf("\033[33m");
    printf("\n\t\t\t------------------------------\n\n\033[0m");
    printf("\tEnter your account number: ");
    scanf("%d", &acc_num);

    for (j = 0; j < i; j++)
    {
        if (acc_num == person[j].account_num)
        {
            printf("\tAccount holder: %s\n", person[j].name);
            flag = 1;

            printf("\tEnter your Customer ID: ");
            scanf("%d", &customer_id);

            if (customer_id == person[j].id)
            {
                printf("\tEnter new password (\033[31mInteger only\033[0m): ");
                scanf("%d", &new_password);
                person[j].pass = new_password;
                printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
                delay(15);
                system("cls");
                heading();
                printf("\n\t\t\t       Password Forgot         ");
                printf("\033[33m");
                printf("\n\t\t\t------------------------------\n\n\033[0m");
                printf("\n\033[32m\tPassword reset.\n\033[0m");
                saveAccountDetails_file(person, j, i);
            }
            else
            {
                printf("\033[31m\tIncorrect Customer ID!\n\033[0m");
            }
            break;
        }
    }
    if (!flag)
    {
        printf("\033[1m\033[33m\n\t\tLoading....\033[0m");
        delay(20);
        system("cls");
        heading();
        printf("\n\t\t\t       Password Forgot         ");
        printf("\033[33m");
        printf("\n\t\t\t------------------------------\n\n\033[0m");
        printf("\033[31m\tAccount number not found! Please try again.\n\033[0m");
    }
    printf("\n\n\t\t\tPress any key for HOME");
    getch();
}
