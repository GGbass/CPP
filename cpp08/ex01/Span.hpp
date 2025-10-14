#ifndef Span_HPP
#define Span_HPP

class Span
{
	private:
		unsigned int *_n;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		/* methods */
		void	addNumber(unsigned int n);
};

#endif // Span_HPP
