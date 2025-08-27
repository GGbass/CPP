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
		virtual ~Dog();

		void	makeSound() const;
		Brain*	getBrain();
		void	setIdeas();
		void	setIdea(int i, std::string idea);
		std::string getIdea(int i) const;

	private:
		Brain *brain;
};

#endif // Dog_HPP
