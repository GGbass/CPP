#ifndef Animal_HPP
# define Animal_HPP
# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const;

	protected:
		std::string type;
};

#endif // Animal_HPP
