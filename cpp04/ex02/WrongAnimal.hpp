#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		~WrongAnimal();
		std::string getType() const;
		void makeSound() const;
	
	protected:
		std::string type;
};

#endif // WrongAnimal_HPP
