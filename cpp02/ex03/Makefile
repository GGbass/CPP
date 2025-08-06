DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = bsp

SRC =	./Point.cpp \
		./Fixed.cpp \
		./main.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address,leak

CXX = c++

all: $(NAME) show_progress

run:
	@make clean
	@echo "$(GREEN)Running $(NAME)...$(DEFAULT)"
	@make && ./$(NAME)

$(NAME): $(OBJ)

	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

show_progress:
		@for file in $(SRC); do \
			echo "$(GREEN)Compiling $$file "; \
		done; \
		echo "\nCompiled: 100%\n run: -> $(NAME) $(DEFAULT)"; \

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:
	rm -f bsp.o
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all

git:
	git add .
	git commit -m "Update"
	git push

.PHONY: clean fclean re all show_progress run
