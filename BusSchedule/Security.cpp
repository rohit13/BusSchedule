#include"Security.h"

Security::Security(int assetId, std::string & credR, std::string & aName, int v, int count)
{
	setAssetClass(assetId);
	setAssetName(aName);
	setCreditRating(credR);
	setAssetValue(v);
	setAssetCount(count);
	populateRatingPrecedenceMap();
	
}

void Security::setAssetClass(int a)
{
	this->assetClass = a;
}

void Security::setAssetValue(int v)
{
	this->assetValue = v;
}

void Security::setCreditRating(std::string &c)
{
	this->creditRating = c;
}

void Security::setAssetName(std::string &aName)
{
	this->assetName = aName;
}

int Security::getAssetClass()
{
	return this->assetClass;
}

int Security::getAssetValue()
{
	return this->assetValue;
}

std::string Security::getCreditRating()
{
	return this->creditRating;
}

std::string Security::getAssetName()
{
	return this->assetName;
}

void Security::setAssetCount(int count)
{
	this->assetCount = count;
}

int Security::getAssetCount()
{
	return this->assetCount;
}


std::map<std::string, int> Security::getRatingPrecedenceMap()
{
	return this->ratingPrecedenceMap;
}
void Security::populateRatingPrecedenceMap()
{
	this->ratingPrecedenceMap.insert(std::make_pair("DDD", 0));
	this->ratingPrecedenceMap.insert(std::make_pair("D", 1));
	this->ratingPrecedenceMap.insert(std::make_pair("CCC", 2));
	this->ratingPrecedenceMap.insert(std::make_pair("C", 3));
	this->ratingPrecedenceMap.insert(std::make_pair("BBB", 4));
	this->ratingPrecedenceMap.insert(std::make_pair("B", 5));
	this->ratingPrecedenceMap.insert(std::make_pair("A", 6));
	this->ratingPrecedenceMap.insert(std::make_pair("AAA", 7));

}

bool operator<(Security &a, Security & b)
{
	int ratingA = a.getRatingPrecedenceMap()[a.getCreditRating()];
	int ratingB = b.getRatingPrecedenceMap()[b.getCreditRating()];
	if (ratingA < ratingB)
	return true;
	else
	return false;
}
