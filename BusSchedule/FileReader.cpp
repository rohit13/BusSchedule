#include"FileReader.h"
#include<fstream>
#include<sstream>
#include<iostream>
#include<windows.data.json.h>


std::vector<std::string>& FileReader::readFile(std::string &filePath)
{
	std::vector<std::string> temp;              
	std::string line;
	std::ifstream file(filePath);
	if (file.is_open())                                             //open file
	{
		while (getline(file, line))                                // read file line by line
		{
			//std::cout << line << std::endl;
			//std::string tempLine = line;
			std::size_t nameBegin = line.find("name");
			std::size_t nameEnd = line.find("ticker");
			std::size_t valueBegin = line.find("value");
			
			//std::cout << " &  " << valueEnd;
			if (nameBegin != std::string::npos)
			{
				//std::cout << "name found";
				this->v.push_back(line.substr(nameBegin+8, nameEnd-18));
			}

			if (valueBegin != std::string::npos)
			{
				std::string tempLine = line.substr(valueBegin);
				//std::cout << tempLine << " % ";
				std::size_t comma = tempLine.find(",");
				
				//std::cout << comma<<"      ";
				//std::cout << "name found";
				this->v.push_back(line.substr(valueBegin+8,comma-8));
			}

			/*std::stringstream ss(line);                            // put string 'line' in stringstream
			std::string currS,lastS;
			while (ss>> currS>>std::skipws )                                      // read stringstream one string at a time     
			{   
				
				if (lastS == "{\"name\":" )                        // change here to check for string being generated 
				{   
					currS.erase(currS.begin());                     // clean string
					this->v.push_back(currS);                       // push it in vector
				}

				if (lastS == "\"value\":")
				{
					currS.erase(currS.end()-1);
					this->v.push_back(currS);
				}

				lastS = currS;
			}		*/
		}
		file.close();
	}

	
	return v;                                                          // return the vector containing info

}