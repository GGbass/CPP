#ifndef Animal_HPP
#define Animal_HPP

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		~Animal();
		//functions
		//virtual void makeSound() const = 0; // Pure virtual function to enforce derived classes to implement it
		//virtual std::string getType() const; // Virtual function to get the type of the animal
		void makeSound() const;
		//getter and setters
		std::string getType() const;
		void setType(const std::string &type);
	protected:
		std::string type;

};

#endif // Animal_HPP
