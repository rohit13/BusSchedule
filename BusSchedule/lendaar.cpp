#include"Lendaar.h"
#include<iostream>

std::string Borrower::getBorrowerName()
{
	return this->borrowerName;
}

int Borrower::getBorrowerID()
{
	return this->borrowerID;
}

int Borrower::getBorrowedAmount()
{
	return this->borrowedAmount;
}



void Borrower::setBorrowerID(int bID)
{
	this->borrowerID = bID;
}

void Borrower::setBorrowerName(std::string & bName)
{
	this->borrowerName = bName;
}

void Borrower::setBorrowedAmount(int amount)
{
	this->borrowedAmount = amount;
}

void Borrower::setUpBorrowerInventory(std::vector<std::string> &v) // could be a vector
{
	for (int i = 0,j=0; i < v.size(); i+=2,j++)
	{
		std::string cRatingA = "A";
		std::string cRatingB = "B";
		std::string cRatingC = "C";
		if (j < 4)
		{
			Security * tmpSec = new Security(j, cRatingA, v[i], std::atoi(v[i + 1].c_str()), 10);
			this->inventoryBorrower.insert(std::make_pair(j, tmpSec));
		}

		if (j > 4 && j<10)
		{
			Security * tmpSec = new Security(j, cRatingB, v[i], std::atoi(v[i + 1].c_str()), 10);
			this->inventoryBorrower.insert(std::make_pair(j, tmpSec));
		}

		if (j > 10)
		{
			
			
				Security * tmpSec = new Security(j, cRatingC, v[i], std::atoi(v[i + 1].c_str()), 10);
				this->inventoryBorrower.insert(std::make_pair(j, tmpSec));
			
		}
	}

}

std::map<int, Security*> Borrower::getBorrowerInventory()
{
	return this->inventoryBorrower;
}

void Borrower::populateBorrowerInventory()
{
	std::map<int, Security*>::iterator it;

	for (it = this->inventoryBorrower.begin(); it != this->inventoryBorrower.end(); it++)
	{   
		std::cout << "AssetID:" << it->second->getAssetClass() << std::endl;
		std::cout << "AssetName:" << it->second->getAssetName() << std::endl;
		std::cout << "Asset Credit Rating:" << it->second->getCreditRating() << std::endl;
		std::cout << "Asset Value:" << it->second->getAssetValue() << std::endl;
		std::cout << "Asset Count:" << it->second->getAssetCount() << std::endl;
		std::cout << std::endl;
	}
}