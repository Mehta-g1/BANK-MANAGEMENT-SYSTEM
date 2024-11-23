# BANK-MANAGEMENT-SYSTEM
Welcome to the Bank Management System! This program allows users to manage their bank accounts with various functionalities like opening an account, 		depositing and withdrawing money, checking balance, and more. This README is designed to help first-year college students understand how to use and navigate 	the system.


# Features
 -> Open a new bank account
 
 -> Deposit money into an account
 
 -> Withdraw money from an account
 
 -> Check account balance
 
 -> View customer details and transaction history
 
 -> Change account password
 
 -> Reset forgotten password
 
 
# Getting Started
To run the Bank Management System, you need to have a C compiler installed on your machine. 
You can use any IDE like Code::Blocks, Dev-C++, or an online compiler.
# How to Use
 step-1 -> Compile and run the program.
 
 step-2 -> You will be presented with a menu of options.
 
 step-3 -> Enter the number corresponding to the action you want to perform.
 
 step-4 -> Follow the prompts to complete your desired action.
 
# Code Structure
 -> openAccount(): Opens a new bank account.
 
 -> deposit(): Handles money deposits.
 
 -> withdraw(): Handles money withdrawals.
 
 -> checkBalance(): Checks the current balance of an account.
 
 -> displayDetails(): Displays customer details and transaction history.
 
 -> changePassword(): Allows the user to change their password.
 
 -> forgotPassword(): Resets the password if forgotten.
 
 -> loadAccountDetails(): Loads account details from files.
 
 -> saveAccountDetails_file(): Saves account details to files.
 
# Contributing
-> https://github.com/Mehta-g1
 
->https://linkedin.com/Mehta-g1
  
-> https://github.com/ajitkumargupta01
  

# Features
 -> Open a new bank account
 -> Deposit money into an account
 -> Withdraw money from an account
 -> Check account balance
 -> View customer details and transaction history
 -> Change account password
 -> Reset forgotten password

# Prerequisites
 -> You need a C compiler (GCC, Clang, etc.)
 -> Basic understanding of C programming

# 1st Page : ->

                        ---------------------------------------------------------------------
                                                BANK MANAGEMENT SYSTEM
                        ---------------------------------------------------------------------

                               HOME
                        ------------------                                      Opened Accounts: 1

                        1. Open New Account
                        2. Deposit
                        3. Withdraw
                        4. Balance Check
                        5. Customer Details and Transactions
                        6. Change Password
                        7. Forgot Password
                        8. Exit

                Enter your choice:

# 2nd Page (option 1 Opening new account) : ->


                        ---------------------------------------------------------------------
                                                BANK MANAGEMENT SYSTEM
                        ---------------------------------------------------------------------

                               Open New Account
                        ------------------------------

        Enter your name: Mehta_G1
        Enter your mobile number: 1234567890
        Enter account type (Saving OR Current): Saving
        Enter opening balance: 1000
        Create your password (Integer only) for withdrawals: 123


# After Account Opening

                        ---------------------------------------------------------------------
                                                BANK MANAGEMENT SYSTEM
                        ---------------------------------------------------------------------

                               Open New Account
                        ------------------------------

        Account number  : 21051121
        Account holder  : Mehta_G1
        Mobile number   : 1234567890
        Account type    : Saving
        Password        : 12345
        Customer ID     : 235817
        Opening balance : INR 1000.00

        Account opened successfully.


                        Press any key for HOME
                        
# All these data saved into file with name of serial No. as like this :->
			       Customer Details         
			------------------------------

	Account number	: 21051121
	Account holder	: Mehta_G1
	Mobile number	: 1234567890
	Account type	: Saving
	Password	: 12345
	Customer ID	: 235817
	Current balance	: INR 1000.00

# You can see all transaction history and transaction detail accourding to this :->



                        ---------------------------------------------------------------------
                                                BANK MANAGEMENT SYSTEM
                        ---------------------------------------------------------------------

                               Customer Detail and Transactions
                        --------------------------------------------

        Account number  : 21051120
        Account holder  : Mehta_G1
        Mobile number   : 1234567890
        Account type    : Saving
        Password        : 12345
        Customer ID     : 235816
        Current balance : INR 23000.00


                        Transactions
        --------------------------------------------

        Date & Time                     Deposit         Withdrawal              Remaining balance

        17-11-2024 12:58                1000.00                                 1000.00
        17-11-2024 13:7                 10000.00                                11000.00
        18-11-2024 13:9                                 2000.00                 9000.00
        19-11-2024 15:10                3000.00                                 12000.00
        19-11-2024 21:36                1000.00                                 13000.00
        20-11-2024 21:37                1000.00                                 14000.00
        21-11-2024 21:50                                1000.00                 13000.00
        20-11-2024 23:31                1000.00                                 14000.00
        20-11-2024 23:32                                2000.00                 12000.00
        21-11-2024 12:34                20000.00                                32000.00
        21-11-2024 12:35                                10000.00                22000.00
        22-11-2024 9:38                 1000.00                                 23000.00


                        Press any key for HOME
