#ifndef Base_HPP
# define Base_HPP
# include <iostream>
# include <cstdlib> // for rand
# include <ctime> // for time
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

class Base
{
	public:
		virtual		~Base(void);
		static Base*	generate(void);
		static void		identify(Base* p);
		static void		identify(Base& p);	// Using a pointerinside this function is forbidden.
};

#endif
