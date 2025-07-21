#ifndef REPLACER_HPP
#define REPLACER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <cstdio>
# include <fstream>

class	Replacer
{
	private:
		std::string		fileName;
		std::string		search;
		std::string		replace;
		std::string		newFile;
		std::ifstream	inFile;
		std::ofstream	outFile;

		std::string		checkCurrentLine(std::string line);
		int				checkInfile(void);
		void			writeOnOutFile(void);

	public:
		Replacer(std::string fileName, std::string search, std::string replace);
		void	fileMaker(void);

};

#endif