// cours 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsUtility.h";
#include "clsInputValidate.h";
#include "clsDate.h"
#include "clsPerson.h"
#include "clsBankeClient.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsLoginScreen.h"

using namespace std;

#include "Global.h"

int main()
{
    

    while (CanLogin)
    {
        if (!clsLoginScreen::ShowLoginScreen()) {
            break;
        }
    }
    
    system("pause>0");
    return 0;





 
}










