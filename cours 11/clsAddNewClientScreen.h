#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h";
#include "clsBankeClient.h"
#include <iostream>
using namespace std;
class clsAddNewClientScreen: protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankeClient& Client) {
    cout << "\nEnter FirstName: ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter LastName: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter PinCode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance: ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber("\nEnter Account Balance:");
}
    static void _Print(clsBankeClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
public:
	static void ShowAddNewClient() {
        if (!CheckAccessRight(clsUser::enPermissions::pAddNewClient)) {
            return;
        }
        
        _DrawScreenHeader("\tAdd New Client Screen");

        string AccountNumber;
        cout << "Please Enter Account Number " ;
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankeClient::IsClientExist(AccountNumber)) {
            cout << "Account Number is already Used , choose another one\n";
            AccountNumber = clsInputValidate::ReadString();
        
        }
        clsBankeClient NewClient = clsBankeClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(NewClient);
        clsBankeClient::enSaveResulte SaveResult;
        SaveResult=NewClient.Save();
        switch (SaveResult)
        {
            case clsBankeClient::enSaveResulte::svSucceded: {
                cout << "Client Added Successfuly\n";
                _Print(NewClient);
                break;
            }
            case clsBankeClient::enSaveResulte::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }
            case clsBankeClient::enSaveResulte::svFaildAccountNumberExists:
            {
                cout << "\nError account was not saved because account number is used!\n";
                break;

            }
        }

    };

};

