#pragma once
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include"clsInputValidate.h"
#include"clsShowClientsList.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsers.h"
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"

using namespace std;
class clsMainScreen: protected  clsScreen
{
private:

    enum _enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7,eLoginRegisterList=8, eCurrncyExchange = 9, eExit = 10
    };
    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenue();
    }
    static void _ShowAllClientScreen() {
   
        clsShowClientsList::ShowClientList();
    }
    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClient();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClient();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClinte();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClintScreen();

    }

    static void _ShowTransactionsMenue()
    {
       
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();

    }
    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();

    }
    static void _ShowCurrencyExchangeMainScreen()
    {
        clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
    }
    static void _LogoutScreen()
    {
        CurrentUser = clsUser::Find("", "");

    }
    static void _PerfromMainMenueOption(_enMainMenueOptions enMainMenueOptions) {
        switch (enMainMenueOptions)
        {
        case _enMainMenueOptions::eListClients:
            system("cls");
            _ShowAllClientScreen();
            _GoBackToMainMenue();
            break;
        case _enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case _enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case _enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        case _enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        case _enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        case _enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case _enMainMenueOptions::eLoginRegisterList:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case _enMainMenueOptions::eCurrncyExchange:
            system("cls");
            _ShowCurrencyExchangeMainScreen();
            _GoBackToMainMenue();
            break;
        
         case _enMainMenueOptions::eExit:
             system("cls");
             _LogoutScreen();
             break;
    }
   }

public:
    
  
    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

       _PerfromMainMenueOption((_enMainMenueOptions)_ReadMainMenueOption());
    }
};
