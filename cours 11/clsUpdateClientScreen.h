#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h";
#include "clsBankeClient.h"
#include <iostream>

using namespace std;
class clsUpdateClientScreen : protected clsScreen
{
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
    static void ShowUpdateClinte() {
        if (!CheckAccessRight(clsUser::enPermissions::pUpdateClient)) {
            return;
        }
       
        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";
        cout << "\n Please Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankeClient::IsClientExist(AccountNumber))
        {
            cout << "\n Account number is not found! Please Enter Client Account Number: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankeClient Client = clsBankeClient::Finde(AccountNumber);

        _Print(Client);
        cout << "\n Are you sure you want update this account!?";
        char answer = 'n';
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";

            _ReadClientInfo(Client);

            clsBankeClient::enSaveResulte SaveResult = Client.Save();

            switch (SaveResult)
            {
            case  clsBankeClient::enSaveResulte::svSucceded:
            {
                cout << "\nAccount Updated Successfully :-)\n";
                _Print(Client);
                break;
            }
            case clsBankeClient::enSaveResulte::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;
            }

            }
        }
        else {
            cout << "\nClient was not Updated\n";
        }
    }

};

