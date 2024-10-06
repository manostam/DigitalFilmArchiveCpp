#pragma once
#include <string>
#include "config.h"
#include <iostream>
#include <fstream>

class Movie
{
public:
	std::string* getMovieInfo(std::string pathInfo)
	{
		std::string* movieInfo = new std::string[9]; // 0-name, 1-director, 2-date, 3-stars, 4-genre, 5-6-7-8 description
		std::string myText; // where I'll be saving the text
		std::ifstream myReadFile(std::string(ASSET_PATH) + pathInfo); // reading from the text file
		int ct = 0;
		while (std::getline(myReadFile, myText))
		{
			movieInfo[ct] = myText;
			ct++;
		}
		myReadFile.close();
		return movieInfo; // In this case you return a pointer of the position in the heap. All the memory in the heap has to free manually. So it is now your work to delete the memory, if you don't need it anymore: delete[] movieInfo
	}

};