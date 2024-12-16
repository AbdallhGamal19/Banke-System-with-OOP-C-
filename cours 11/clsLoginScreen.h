#pragma once
#include<iostream>
#include "clsuser.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "Global.h"
#include "fstream"
#include"clsDate.h"
using namespace std;
class clsLoginScreen:protected clsScreen
{
	
	
	static bool _Login() {
		
		bool LoginFaild=false;
		int FaildLoginCount = 0;
		string Username, Password;
		do
		{
			
			
			if (LoginFaild) {
				FaildLoginCount++;
				cout << "\nInvlaid Username/Password!\n\n";
				cout << "You have " << (3-FaildLoginCount) << " to login\n\n";
			}
			if (FaildLoginCount == 3) {
				cout << "\nYour are Locked after 3 faild trails \n\n";
				return false;
			}
			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;
		
			CurrentUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();

	}
};

