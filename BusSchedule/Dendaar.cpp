#include "Dendaar.h"
#include<iostream>

Lender::Lender(int amount, std::string acceptRating)
{
	this->totalAmount = amount;
	this->acceptableRating = acceptRating;
}
std::string Lender::getlenderName()
{
	return this->lenderName;
}

int Lender::getlenderID()
{
	return this->lenderID;
}

int Lender::getlendedAmount()
{
	return this->lendedAmount;
}

void Lender::setlendedAmount(int a)
{
	this->lendedAmount = a;
}

void Lender::setlenderID(int id)
{
	this->lenderID = id;
}

void Lender::setlenderName(std::string &name)
{
	this->lenderName = name;
}

void Lender::setUpLenderInventory(std::vector<std::string> &v)
{
	for (int i = 0, j = 0; i < v.size(); i += 2, j++)
	{
		std::string cRatingA = "A";
		std::string cRatingB = "B";
		std::string cRatingC = "C";
		if (j < 4)
		{
			Security * tmpSec = new Security(j, cRatingA, v[i], std::atoi(v[i + 1].c_str()), 10);
			this->inventoryLender.insert(std::make_pair(j, tmpSec));
		}

		if (j > 4 && j<10)
		{
			Security * tmpSec = new Security(j, cRatingB, v[i], std::atoi(v[i + 1].c_str()), 10);
			this->inventoryLender.insert(std::make_pair(j, tmpSec));
		}

		if (j > 10)
		{


			Security * tmpSec = new Security(j, cRatingC, v[i], std::atoi(v[i + 1].c_str()), 10);
			this->inventoryLender.insert(std::make_pair(j, tmpSec));

		}
	}
	
}

std::map<int, Security*> Lender::getLenderInventory()
{
	return this->inventoryLender;
}

void Lender::addToLenderInventory(std::vector<Security*> &secVector)
{
	for (auto s: secVector)
	{
		if (inventoryLender.find(s->getAssetClass()) != inventoryLender.end())
		{
			inventoryLender[s->getAssetClass()]->setAssetCount(inventoryLender[s->getAssetClass()]->getAssetCount() + s->getAssetCount());
		}
		else
		{
			inventoryLender.insert(std::make_pair(s->getAssetClass(), s));
		}
	}
}


void Lender::populateLenderInventory()
{
	std::map<int, Security*>::iterator it;

	for (it = this->inventoryLender.begin(); it != this->inventoryLender.end(); it++)
	{
		std::cout << "AssetID:" << it->second->getAssetClass() << std::endl;
		std::cout << "AssetName:" << it->second->getAssetName() << std::endl;
		std::cout << "Asset Credit Rating:" << it->second->getCreditRating() << std::endl;
		std::cout << "Asset Value:" << it->second->getAssetValue() << std::endl;
		std::cout << "Asset Count:" << it->second->getAssetCount() << std::endl;
		std::cout << std::endl;
	}
}

std::string Lender::getAcceptableRating()
{
	return this->acceptableRating;
}
