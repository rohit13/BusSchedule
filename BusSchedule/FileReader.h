#pragma once

#include<vector>
#include<string>
class FileReader {
public:
	std::vector<std::string>& readFile(std::string &s);

private:
	std::vector<std::string> v;
};