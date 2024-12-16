#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h";
#include "clsBankeClient.h"
#include <iostream>

using namespace std;
class clsFindClientScreen : protected clsScreen
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
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
public:
	static void ShowFindClintScreen() {
		if (!CheckAccessRight(clsUser::enPermissions::pFindClient)) {
			return;
		}
		
		_DrawScreenHeader("\tFind Client Screen");

		string AccountNumber = "";
		cout << "\n Please Enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankeClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account number is not found! Please Enter Client Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankeClient Client = clsBankeClient::Finde(AccountNumber);
		if (!Client.IsEmpty()) {
			cout << "\nClient Found :-)\n";
		}
		else {
			cout << "Client Not Found :-)\n";
		}
		_Print(Client);
	}
};

