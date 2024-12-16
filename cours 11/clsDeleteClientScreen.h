#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h";
#include "clsBankeClient.h"
#include <iostream>
using namespace std;
class clsDeleteClientScreen : protected clsScreen
{
    static void _Print(clsBankeClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAccountNumber : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:

	static void ShowDeleteClient() {
        if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient)) {
            return;
        }

        _DrawScreenHeader("\tShow Delete Client Screen");
    string AccountNumber;
    cout << "Enter Account Number\n";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankeClient::IsClientExist(AccountNumber)) {
        cout << "Accout number is not fount! Enter valid account number\n";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankeClient Client = clsBankeClient::Finde(AccountNumber);
    _Print(Client);
    cout << "\n Are you sure you want delet this account!?";
    char answer = 'n';
    cin >> answer;
    if (answer=='y'|| answer=='Y')
    {
        if (Client.Delete()) {
            cout << "\nClient deleted successfuly\n";
            _Print(Client);
        }
        else {
            cout << "\n!Error client was not deleted\n";
        }
    }
    else {
        cout << "\nClient was not deleted\n";
    }
}
};

