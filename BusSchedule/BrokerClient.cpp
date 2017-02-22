/*

#include"Borrower.h"
#include"FileReader.h"
#include "Lender.h"
#include "OptimizationEngine.h"
#include<iostream>
#include<map>
int main() {

	FileReader fr;
	
	std::vector<std::string> tempVector;
	std::string filePath = "C:\\Users\\Ishan\\Documents\\Visual Studio 2015\\Projects\\OptimizedCollateralAllocation\\OptimizedCollateralAllocation\\stocks.json";
	tempVector = fr.readFile(filePath);

	Borrower* bor= new Borrower();
	bor->setUpBorrowerInventory(tempVector);
	std::cout << "===========================BORROWER INVENTORY======================================================" << std::endl << std::endl;
	bor->populateBorrowerInventory();
	bor->setBorrowedAmount(2000);
	std::cout << "===========================LENDER INVENTORY======================================================" << std::endl << std::endl;
	std::cout << "=================================================================================" << std::endl << std::endl;
	//std::map<int, Security*> borrowerInvetory = bor.getBorrowerInventory();
	Lender *lend = new Lender(10000, "C");
	
	OptimizationEngine oE;
	oE.optimize(lend, bor);

	std::cout << "=================================================================================" << std::endl << std::endl;
	std::cout << "===========================BORROWER INVENTORY======================================================" << std::endl << std::endl;
	bor->populateBorrowerInventory();


	std::cout << "=================================================================================" << std::endl << std::endl;
	std::cout << "===========================LENDER INVENTORY======================================================" << std::endl << std::endl;
	lend->populateLenderInventory();


	return 0;
}

*/

