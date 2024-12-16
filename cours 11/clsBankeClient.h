#pragma once
#include "clsPerson.h"
#include"clsString.h"
#include "fstream" 
#include "Global.h"
class clsBankeClient:public clsPerson
{
private:
	enum enMode { EmptyMode = 0, updateMode = 1, AddMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarckForDelete = false;
	static clsBankeClient _ConvertLineToClientObject(string line,string Seperatir="#//#") {
		vector <string>  vClientData;

		vClientData = clsString::Split(line, Seperatir);
		vClientData = clsString::Split(line, Seperatir);
		return clsBankeClient(enMode::updateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}
	static clsBankeClient _GetEmptyClientObject() {
		return clsBankeClient(enMode::EmptyMode, "", "", "", "", "","", 0);
	}
	static vector <clsBankeClient> _LoadClientsDataFromFile() {
		fstream MyFile;
		vector <clsBankeClient> vClients;
		MyFile.open("Clients.txt", ios::in);//read mode
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line))
			{
				clsBankeClient Client = _ConvertLineToClientObject(line);
				
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	static string _ConverClientObjectToLine(clsBankeClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}
	static void _SaveClientDataToFile(vector <clsBankeClient> vClients) {
		fstream myFile;
		
		myFile.open("Clients.txt", ios::out);//overrite mode
		if (myFile.is_open()) {
			string line;
			for (clsBankeClient C : vClients)
			{
				if (C.MarckForDelete() == false) {
					line = _ConverClientObjectToLine(C);
					myFile << line << endl;
				}
				
			}
			
			myFile.close();
		}
	}
	void _AddDataLineToFile(string  stDataLine) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out|ios::app);
			if (MyFile.is_open()) {
				MyFile << stDataLine << endl;
				MyFile.close();
			}
			
	}
	void _Update() {
		vector <clsBankeClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankeClient& C :_vClients)
		{
			if (C.AccountNumber() == AccountNumber()) {
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClients);
	}
	void _addNew() {
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}
	struct stTrnsferLogRecord;

	static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTrnsferLogRecord TrnsferLogRecord;

		vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
		TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
		TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
		TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
		TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

		return TrnsferLogRecord;

	}
	string _PrepareTransferLogRecord(float Amount, clsBankeClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += AccountNumber() + Seperator;
		TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	}

	void _RegisterTransferLog(float Amount, clsBankeClient DestinationClient, string UserName)
	{

		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
public:
	

	clsBankeClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber,
		string PinCode,
		float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone) 
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	struct stTrnsferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;

	};
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	bool MarckForDelete() {
		return _MarckForDelete;
	}
	string AccountNumber() {
		return _AccountNumber;
	}
	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode( ) {
		return  _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance() {
		return  _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;
	void Deposit(double amount) {
		_AccountBalance += amount;
		Save();
	}
	bool Withdraw(double amount) {
		if (amount > _AccountBalance) {
			return false;
		}
		_AccountBalance -= amount;
		Save();
	}

	bool Transfer(float Amount, clsBankeClient& DestinationClient,string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		Withdraw(Amount);


		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;
	}
	
	
	

	bool Delete() {
		vector<clsBankeClient> _Clients;
		
		_Clients = _LoadClientsDataFromFile();
		for (clsBankeClient& C : _Clients) {
			if (C.AccountNumber() == _AccountNumber) {
				C._MarckForDelete = true;
				break;
			}
		}
		_SaveClientDataToFile(_Clients);
		*this = _GetEmptyClientObject();
		return true;
	}
	static vector <clsBankeClient>  GetClientList() {
		return _LoadClientsDataFromFile();
	}
	static double GetTotalBalances() {
		vector <clsBankeClient> vClients;
		double TotalBalances=0;
		vClients = GetClientList();
		for  (clsBankeClient &C : vClients)
		{
			TotalBalances += C._AccountBalance;
		}
		return TotalBalances;
	}
	static clsBankeClient Finde(string AccountNumber) {
		fstream myFile;
		//vector <clsBankeCliente> vClients;
		myFile.open("Clients.txt", ios::in);//read mode
		if (myFile.is_open()) {
			string line;
			while (getline(myFile,line))
			{
				clsBankeClient Cliente = _ConvertLineToClientObject(line);
				if (Cliente.AccountNumber() == AccountNumber) {
					myFile.close();
					return Cliente;
				}
				//vClients.push_back(Cliente);
			}
			myFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankeClient Finde(string AccountNumber,string PinCode) {
		fstream myFile;
		//vector <clsBankeCliente> vClients;
		myFile.open("Clients.txt", ios::in);//read mode
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line))
			{
				clsBankeClient Cliente = _ConvertLineToClientObject(line);
				if (Cliente.AccountNumber() == AccountNumber && Cliente.PinCode == PinCode) {
					myFile.close();
					return Cliente;
				}
				//vClients.push_back(Cliente);
			}
			myFile.close();
		}
		return _GetEmptyClientObject();
	}
	static bool IsClientExist(string AccountNumber) {
		clsBankeClient Client = clsBankeClient::Finde(AccountNumber);
		return (!Client.IsEmpty());
	}
	static clsBankeClient GetAddNewClientObject(string AccountNumber) {
		return clsBankeClient(enMode::AddMode, "", "", "", "", AccountNumber, "", 0);
	}
	enum enSaveResulte{svFaildEmptyObject =0 ,svSucceded=1, svFaildAccountNumberExists = 2
	};
	enSaveResulte Save() {
		switch (_Mode)
		{
		case clsBankeClient::enMode::EmptyMode: {
			return enSaveResulte::svFaildEmptyObject;
			
		}
		case clsBankeClient::enMode::updateMode: {
			_Update();
			return enSaveResulte::svSucceded;
			break;
		}
		case clsBankeClient::enMode::AddMode: {
			if (IsClientExist(_AccountNumber)) {
				return  enSaveResulte::svFaildAccountNumberExists;
			}
			_addNew();
			_Mode = enMode::updateMode;
			return enSaveResulte::svSucceded;
		}
		break;
		}
	}
	static  vector <stTrnsferLogRecord> GetTransfersLogList()
	{
		vector <stTrnsferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode
		
		if (MyFile.is_open())
		{

			string Line;

			stTrnsferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{

				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);

			}

			MyFile.close();

		}

		return vTransferLogRecord;

	}


};

