#ifndef Brain_HPP
# define Brain_HPP
# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();
		std::string getIdea(int i) const;
		void	setIdea(int i, std::string str);

	private:
		std::string ideas[100];
};

#endif // Brain_HPP
