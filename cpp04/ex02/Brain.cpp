#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Creating a brain to someone\n";
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100 ; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	std::cout << "Copying a brain to someone\n";
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100 ; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
		std::cout << "Assigning a brain to someone\n";
	}
	return (*this);
}

Brain::~Brain(){std::cout << "My ideaaas  noo!! \n" ;}

std::string Brain::getIdea(int i) const { return  (this->ideas[i]);}

void	Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i > 100)
	{
		std::cout << "Wrong index to set\n";
		return ;
	}
	this->ideas[i] = "checking index";
	this->ideas[i].clear();
	this->ideas[i] = idea;
}

