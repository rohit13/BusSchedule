#pragma once
#include<string>
#include<map>
#include"Security.h"
#include  "ITrader.h"
#include<vector>
class Lender
{
public:
	Lender(int,std::string);
	std::string getlenderName();
	int getlenderID();
	int getlendedAmount();
	void setlenderName(std::string &);
	void setlenderID(int);
	void setlendedAmount(int);
	void setUpLenderInventory(std::vector<std::string> &v);
	std::map<int, Security*> getLenderInventory();
	void addToLenderInventory(std::vector<Security*> &);
	void populateLenderInventory();
	std::string getAcceptableRating();
private:
	std::string lenderName;
	int lenderID;
	int lendedAmount;
	int totalAmount;
	std::string acceptableRating;
	std::map<int, Security*> inventoryLender;

};