#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "A dog is created\n";
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
	this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog: deleting this  " << this->type << " class\n";
}

void	Dog::makeSound() const {std::cout << this->type << " Woof Woof!!\n";}

std::string Dog::getIdea(int i) const
{
	if (i < 0 || i >= 100)
	{
		std::cout << "Wrong index to get idea\n";
		return "";
	}
	return (this->brain->getIdea(i));
}

Brain* Dog::getBrain() {return (this->brain);}

void	Dog::setIdeas()
{
	std::string ideas[10] =
	{
		"Fetch the ball",
		"Bark at strangers",
		"Dig a hole",
		"Chase my tail",
		"Guard the house",
		"Play with a stick",
		"Sniff everything",
		"Lick my owner",
		"Roll in the grass",
		"Beg for treats"
	};
	if (this->brain != NULL)
	{

		for (int i = 0; i < 10; i++)
			this->brain->setIdea(i, ideas[i]);
		for (int i = 11; i < 100; i++)
			this->brain->setIdea(i, "Empty idea");
		std::cout << "Dog: Ideas set in the brain\n";
	}
}

void Dog::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
		return(std::cout << "Wrong index to set idea\n", void());
	if (idea.empty() || this->brain == NULL)
		return(std::cout << "Invalid idea or brain is not initialized\n", void());
	this->brain->setIdea(index, idea);
	std::cout << "Dog: Idea set at index " << index << ": " << idea << "\n";
}
