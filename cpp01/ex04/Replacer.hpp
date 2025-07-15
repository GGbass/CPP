#ifndef REPLACER_HPP
#define REPLACER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <fstream>

class	Replacer
{
	private:
		std::string	fileName;
		std::string	search;
		std::string	replace;
		std::string	newFile;

	public:
		Replacer(std::string fileName, std::string search, std::string replace);
		void	loadFile(void);
		void	replaceInFile(void);
		void	writeToFile(std::string content);
};

#endif