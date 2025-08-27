#ifndef Cat_HPP
# define Cat_HPP
#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat();

		void	makeSound() const;
		Brain*	getBrain();
		void	setIdeas();
		void	setIdea(int i, std::string idea);
		std::string getIdea(int i) const;

	private:
		Brain *brain;
};

#endif // Cat_HPP
