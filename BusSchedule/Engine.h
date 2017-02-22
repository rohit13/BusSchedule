#pragma once
#include"Dendaar.h"
#include"Lendaar.h"
#include"Security.h"
class OptimizationEngine
{ public:
	void optimize(Lender*, Borrower*, std::vector<Security*>&);
	std::vector<int> findIndex(std::vector<int>, int);
	std::vector<int> findPair(std::vector<int>, int);
	void printAllocatedResource(std::vector<int>, Borrower *,Lender*);
	void optimizeWithRating(Lender *, Borrower *);


	std::vector<Security*> getAssets(Lender *, Borrower *); // returns vector of securities with acceptable credit ratings
	void optimizeNew(Lender*, Borrower*); // main optimize function

};

