#include "Replacer.hpp"

Replacer::Replacer(std::string fileName, std::string search, std::string replace)
{
	this->fileName = fileName;
	this->search = search;
	this->replace = replace;
	this->newFile = fileName + ".replace";
}

void	Replacer::loadFile()
{
	std::ifstream in(this->fileName.c_str());
	if (!in.is_open())
	{
		std::cerr << "Error opening file: " << this->fileName << std::endl;
		exit(1);
	}
	
}
