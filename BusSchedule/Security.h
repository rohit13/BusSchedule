#pragma once
#include<string>
#include<map>

class Security
{
public:
	Security(int, std::string &, std::string &,int, int);
	int getAssetClass();
	std::string getCreditRating();
	void setAssetClass(int assetClass);
	void setCreditRating(std::string &c);
	void setAssetName(std::string &);
	std::string getAssetName();
	int getAssetValue();
	void setAssetValue(int);
	void setAssetCount(int);
	int getAssetCount();
	//friend Security* operator<(Security const *s1, Security const *s2);
	friend bool operator<(Security& a, Security& b);
	std::map<std::string, int> getRatingPrecedenceMap();
	void populateRatingPrecedenceMap();
    
private:
	int assetClass;
	std::string creditRating;
	std::string assetName;
	int assetValue;
	int assetCount;
	//std::map<int, std::string> map;
	std::map<std::string, int> ratingPrecedenceMap;
};

