#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Creating a brain to someone\n";
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; 1 < 100 ; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; 1 < 100 ; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "My ideaaas !! \n" ;
}

std::string Brain::getIdea(int i) const { return  (this->ideas[i]);}

void	Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i > 100)
	{
		std::cout << "Wrong index to set\n";
		return ;
	}
	this->ideas[i] = idea;
}

