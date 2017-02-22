#pragma once
#include<string>
#include<map>
#include"Security.h"
#include  "ITrader.h"
#include<vector>
class Borrower
{
public:
	std::string getBorrowerName();
	int getBorrowerID();
	int getBorrowedAmount();
	void setBorrowerName(std::string &);
	void setBorrowerID(int);
	void setBorrowedAmount(int);
	void setUpBorrowerInventory(std::vector<std::string> &v);
	std::map<int, Security*> getBorrowerInventory();
	void populateBorrowerInventory();
private:
	std::string borrowerName;
	int borrowerID;
	int borrowedAmount;
	std::map<int, Security*> inventoryBorrower;

};