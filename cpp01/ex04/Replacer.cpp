#include "Replacer.hpp"

Replacer::Replacer(std::string fileName, std::string search, std::string replace)
{
	this->fileName = fileName;
	this->search = search;
	this->replace = replace;
	this->newFile = fileName.append(".replace");
}

void	Replacer::fileMaker()
{
	std::string	line;

	if (!this->checkInfile())
		exit(1);
	this->outFile.open(this->newFile.c_str());
	if (!this->outFile.is_open())
	{
		this->inFile.close();
		std::cerr << "Error creating .replace file: " << this->newFile << std::endl;
		exit(1);
	}
	this->writeOnOutFile();
	this->outFile.close();
	this->inFile.close();
}


int	Replacer::checkInfile(void)
{
	this->inFile.open(this->fileName.c_str());
	if (!this->inFile.is_open())
	{
		std::cerr << "Error opening file: " << this->fileName << std::endl;
		return (0);
	}
	return (1);
}

std::string	Replacer::checkCurrentLine(std::string line)
{
	size_t	pos;

	pos = 0;
	while ((pos = line.find(this->search, pos)) != std::string::npos)
	{
		line.erase(pos, this->search.length());
		line.insert(pos, this->replace);
		pos += this->replace.length();
	}
	return (line);
}

void	Replacer::writeOnOutFile(void)
{
	std::string	line;

	while (std::getline(this->inFile, line))
	{
		line = this->checkCurrentLine(line);
		this->outFile << line;
		if (!this->inFile.eof())
			this->outFile << std::endl;
	}
}
