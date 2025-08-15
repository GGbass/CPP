#ifndef Dog_HPP
# define Dog_HPP
# include "Animal.hpp"
# include "Brain.hpp"


class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		void	makeSound() const;
		Brain*	getBrain();
		void	setIdeas();

		// To avoid memory leaks, we should not copy the brain pointer directly.
		// Instead, we should create a new Brain object for each Dog instance.
		// This is handled in the constructor and destructor.

	private:
		Brain *brain;
};

#endif // Dog_HPP
