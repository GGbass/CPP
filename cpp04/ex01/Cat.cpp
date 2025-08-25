#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "A cat it's created\n";
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
	this->type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type = other.type;
		//*this->brain = *other.brain;
		if (this->brain != NULL)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	if (this->brain)
		delete this->brain;
	std::cout << "Cat: Deleting this " << this->type << " Class \n";
}

void	Cat::makeSound() const {std::cout << this->type << " Meeeowww \n";}

Brain* Cat::getBrain() {return (this->brain);}

std::string Cat::getIdea(int i) const
{
	if (i < 0 || i >= 100)
	{
		std::cout << "Wrong index to get idea\n";
		return "";
	}
	return (this->brain->getIdea(i));
}

void	Cat::setIdeas()
{
	std::string ideas[10] = {
		"Chase the mouse",
		"Climb the tree",
		"Scratch the furniture",
		"Sleep in the sun",
		"Meow at the door",
		"Play with a ball of yarn",
		"Watch birds from the window",
		"Hide in a box",
		"Lick my paws",
		"Demand food"
	};
	for (int i = 0; i < 10; i++)
		this->brain->setIdea(i, ideas[i]);
	for (int i = 11; i < 100; i++)
		this->brain->setIdea(i, "Empty idea");
	std::cout << "Cat: Ideas set in the brain\n";
}

void Cat::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Wrong index to set idea\n";
		return;
	}
	if (idea.empty() || this->brain == NULL)
	{
		std::cout << "Invalid idea or brain is not initialized\n";
		return;
	}
	this->brain->setIdea(index, idea);
	std::cout << "Cat: Idea set at index " << index << ": " << idea << "\n";
}
