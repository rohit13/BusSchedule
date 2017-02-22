#include"Engine.h"
#include<map>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
struct compare {
	bool operator()(Security * l, Security* r)
	{
		int ratingA = l->getRatingPrecedenceMap()[l->getCreditRating()];
		int ratingB = r->getRatingPrecedenceMap()[r->getCreditRating()];
		if (ratingA > ratingB)
			return true;
		else
			return false;
	}
};

void OptimizationEngine::optimize(Lender * lender, Borrower * borrower, std::vector<Security*> & assets)
{
	std::map<int, Security*> borrowerMap = borrower->getBorrowerInventory();
	std::vector<int> assetValues;
	std::unordered_map<int, int> assetIDValMap;             // map to keep count of assets against assetID's
	int borrowedAmount = borrower->getBorrowedAmount();     // Amount to be borrowed against the assets
	std::vector<int> resVector;
	//populate map with assetID : assetValue
	for (auto m : assets)
	{
		assetIDValMap.insert(std::make_pair(m->getAssetClass(),m->getAssetValue() ));
		
		for (int i = 0; i < m->getAssetCount(); i++)
		{
			assetValues.push_back(m->getAssetValue());
		}
	}

	std::sort(assetValues.begin(), assetValues.end());

	std::vector<int> indexVector;
	
	indexVector= findIndex(assetValues, borrowedAmount);

	if (!indexVector.empty())   // contains assetValues 
	{
		for (int i = 0; i<indexVector.size(); i++)
		{
			for (auto m : assetIDValMap)
			{
				if (m.second == indexVector[i])
					resVector.push_back(m.first);
			}
		}
	}
	else   //contains assetValues 
	{
		indexVector = findPair(assetValues, borrowedAmount);
		for (int i = 0; i<indexVector.size(); i++)
		{
			for (auto m : assetIDValMap)
			{
				if (m.second == indexVector[i])
					resVector.push_back(m.first);
			}
		}
	}

	if (resVector.empty())   /// final option of getting as close to borrow amount and allocating resources
	{
		int i = 0;
		while (borrowedAmount > 0)
		{
			borrowedAmount = borrowedAmount - assetValues[i];
			indexVector.push_back(assetValues[i]);
			i++;
		}

		for (int i = 0;i< indexVector.size(); i++)
		{
			for (auto m : assetIDValMap)
			{
				if (m.second == indexVector[i])
					resVector.push_back(m.first);
			}
		}

		printAllocatedResource(resVector, borrower,lender);
	}
	else
	{
		printAllocatedResource(resVector, borrower, lender);

	}


}

// to find contigous subarray sum = sum(borrowed amount) in parameters
std::vector<int> OptimizationEngine::findIndex(std::vector<int> vec, int sum)         
{
	int curr_sum, i, j;
	std::vector<int> resVec;
	// Pick a starting point
	for (i = 0; i < vec.size(); i++)
	{
		curr_sum = vec[i];

		// try all subarrays starting with 'i'
		for (j = i + 1; j <= vec.size(); j++)
		{
			if (curr_sum == sum)
			{  
				for(int x=i;x<=j-1;x++)
				resVec.push_back(vec[x]);
				return resVec;
			}
			if (curr_sum > sum || j == vec.size())
				break;
			curr_sum = curr_sum + vec[j];
		}
	}

}

//// to find 2 elements that satisfy= sum(borrowed amount) in parameters
std::vector<int> OptimizationEngine::findPair(std::vector<int> vec, int sum)
{
	int i, temp;
	bool binMap[10000] = { 0 }; /*initialize hash map as 0*/
	std::vector<int> resVec;
	for (i = 0; i < vec.size(); i++)
	{
		temp = sum - vec[i];
		if (temp >= 0 && binMap[temp] == 1)
		{
			resVec.push_back(vec[i]);
			resVec.push_back(temp);
			return resVec;
		}
			
		binMap[vec[i]] = 1;
	}
}

void OptimizationEngine::printAllocatedResource(std::vector<int> resVector, Borrower * borrower, Lender * lender)
{

	std::map<int, Security*> bMap = borrower->getBorrowerInventory();
	std::map<int, int> resultMap; // assetID: assetCount
	std::vector<Security*> lenderVector;

	// insert in result map securites with id in resvector
	for (int i = 0; i < resVector.size(); i++)
	{
		std::map<int, int>::iterator it = resultMap.find(resVector[i]);
		if (it != resultMap.end())
		{
			it->second++ ;
		}
		else
		{
			resultMap.insert(std::make_pair(resVector[i],1));
		}
	}
	// iterate resultMap to print the allocated resource to console and make changes to lender and borrower inventory
	for (auto m : resultMap)
	{
		std::cout << "Asset Class           : " << bMap.find(m.first)->second->getAssetName()<<std::endl;
		Security * s = new Security(bMap.find(m.first)->second->getAssetClass(), bMap.find(m.first)->second->getAssetName(),
			bMap.find(m.first)->second->getCreditRating(), bMap.find(m.first)->second->getAssetValue(),m.second);
		lenderVector.push_back(s);
		
		std::cout << "Number of Used Assets :" << m.second<<std::endl;

		bMap.find(m.first)->second->setAssetCount(bMap.find(m.first)->second->getAssetCount() - m.second);

		//std::cout << m.first << std::endl;
	}

	lender->addToLenderInventory(lenderVector);
	
}

void OptimizationEngine::optimizeWithRating(Lender * l, Borrower * b)
{
	std::priority_queue<Security*, std::vector<Security*>, compare> pq;

	for (auto m : b->getBorrowerInventory())
	{
		pq.push(m.second);

		std::cout << m.second->getAssetName() << " :" << m.second->getCreditRating() << std::endl;
	}
	

	/*std::cout<<std::endl<<std::endl;
	std::cout << "pq size is :" << pq.size();
		while (!pq.empty())
	{
		std::cout << pq.top()->getAssetName()<<" :"<<pq.top()->getCreditRating()<<std::endl;
		pq.pop();
	} */
}

// return assets less than the acceptable rating
std::vector<Security*> OptimizationEngine::getAssets(Lender *l , Borrower * b)
{
	std::string tempString = "";
	Security * s= new Security(0,tempString,tempString,0,0);
	int acceptableRating = s->getRatingPrecedenceMap()[l->getAcceptableRating()];
	int currentRating;
	std::vector<Security*> assets;
	
	for (auto m : b->getBorrowerInventory())
	{
		currentRating = m.second->getRatingPrecedenceMap()[m.second->getCreditRating()];
		if (currentRating <= acceptableRating)
			assets.push_back(m.second);
	}

	

	return assets;
}

void OptimizationEngine::optimizeNew(Lender * l, Borrower *b)
{
	std::vector<Security*> vec = getAssets(l, b);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "asset Name:" << vec[i]->getAssetName() << std::endl;
		std::cout << "asset Rating" << vec[i]->getCreditRating() << std::endl;

	}

	optimize(l, b, vec);
}


