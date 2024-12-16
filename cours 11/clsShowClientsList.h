#pragma once
#include <iomanip>
#include <iostream>
#include<vector>
#include "clsBankeClient.h"
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;
class clsShowClientsList : protected clsScreen
{
private:
   static void _PrintClientRecordLine(clsBankeClient Client)
{

       cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
       cout << "| " << setw(20) << left << Client.FullName();
       cout << "| " << setw(12) << left << Client.Phone;
       cout << "| " << setw(20) << left << Client.Email;
       cout << "| " << setw(10) << left << Client.PinCode;
       cout << "| " << setw(12) << left << Client.AccountBalance;

}
public:
    static void ShowClientList() {
        if (!CheckAccessRight(clsUser::enPermissions::pListClients)) {
            return;
        }
        
        vector<clsBankeClient> vClients;
        vClients = clsBankeClient::GetClientList();
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";
        _DrawScreenHeader("\t  Client List Screen", SubTitle);

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vClients.size() == 0) {
            cout << "\t\t\t\tNo Clients Available In the System!";
        }
        else {
            for (clsBankeClient& C : vClients)
            {
                _PrintClientRecordLine(C);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};
