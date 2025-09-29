#ifndef Base_HPP
# define Base_HPP
# include <iostream>
# include <cstdlib> // for rand
# include <ctime> // for time

class A;
class B;
class C;

class Base
{
	public:
		virtual			~Base();
		//static Base*	generate(void);
};

#endif
