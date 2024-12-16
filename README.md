# Bank System - C++ OOP Implementation

## Overview
This is a backend system for managing a bank using Object-Oriented Programming (OOP) principles in C++. It provides various functionalities for client management, transactions, user management, currency exchange, and more. Each user has specific permissions to access different features.

## Features

### 1. **Client Management**
   - **Show Client List**: Displays a list of all clients in the system, including their account details.
   - **Add New Client**: Allows adding a new client by inputting their personal information and creating a new account.
   - **Delete Client**: Deletes a client using their account number and password.
   - **Update Client Info**: Allows updating the client’s personal and account information.
   - **Find Client**: Searches for a client by their account number or name.

### 2. **Transactions**
   - **Deposit**: Allows the client to deposit money into their account.
   - **Withdraw**: Allows the client to withdraw money from their account.
   - **Total Balances**: Displays the total balance for the client.
   - **Transfer**: Allows the client to transfer money between accounts.
   - **Transfer Log**: Displays the log of all transfers made.
   - **Main Menu**: The main menu from which users can access different features.

### 3. **User Management**
   - **List Users**: Displays all users in the system.
   - **Add New User**: Allows an admin to add a new user with specific permissions.
   - **Delete User**: Allows an admin to delete a user from the system.
   - **Update User**: Allows an admin to update user information and permissions.
   - **Find User**: Searches for a user by their username or ID.
   - **Main Menu**: The main menu for user management.

### 4. **Login/Register**
   - Allows users to register for the system and log in with their credentials.

### 5. **Currency Exchange**
   - **List Currencies**: Displays all available currencies for exchange.
   - **Find Currency**: Allows searching for a specific currency.
   - **Update Rate**: Allows updating the exchange rate for a currency.
   - **Currency Calculator**: A calculator to convert between different currencies.
   - **Main Menu**: The main menu for currency exchange features.

### 6. **Permissions**
   Each user in the system has specific permissions, which control access to different features:

   - **pListClients**: Allows the user to view the list of clients.
   - **pAddNewClient**: Allows the user to add a new client.
   - **pDeleteClient**: Allows the user to delete a client.
   - **pUpdateClient**: Allows the user to update client information.
   - **pFindClient**: Allows the user to find a client.
   - **pTransactions**: Allows the user to access transactions (deposit, withdraw, transfer).
   - **pManageUsers**: Allows the user to manage users (add, delete, update, find users).
   - **pLoginRegister**: Allows the user to log in and register.
   - **pCurrencyExchange**: Allows the user to access currency exchange features.

---

## How to Use
1. **Login/Register**: Users must log in to the system using their credentials.
2. **Access Permissions**: Based on the user's permissions, they will be granted access to specific features (e.g., adding clients, performing transactions).
3. **Main Menu**: After logging in, the user is presented with a main menu that contains all available features based on their permissions.

---

### Conclusion
This bank system is designed to handle client and user management, transactions, currency exchange, and more, all while using Object-Oriented Programming principles in C++. The permission system ensures that users can only access features relevant to their roles, ensuring security and efficient management of resources.
