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
		~Cat();

		void	makeSound() const;
		Brain*	getBrain();
		void	setIdeas();

	private:
		Brain *brain;
};

#endif // Cat_HPP
