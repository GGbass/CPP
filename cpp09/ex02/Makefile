DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

CLASS_DIR = .
CLASS ?= $(filter-out class,$(MAKECMDGOALS))
CLASS_NAME = $(CLASS)
HPP_FILE = $(CLASS_NAME).hpp
CPP_FILE = $(CLASS_NAME).cpp

NAME = PmergeMe
INCLUDE = PmergeMe.hpp

SRC =	./dequeMergeSort.cpp \
		./vectorMergeSort.cpp \
		./PmergeMe.cpp \
		./main.cpp


OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -Wall -Werror -Wextra -I -g3 -std=c++98 -fsanitize=address,leak

CXX = c++

all: $(NAME)

run: fclean all
	@echo "$(GREEN)Running $(NAME)...$(DEFAULT)\n"
	@./$(NAME)  2 3 1 5 4 8 7 6

class:
	@if [ -z "$(CLASS)" ]; then \
		echo "Error: CLASS variable not set. Usage: make class CLASS=YourClassName"; \
		exit 1; \
	fi
	@mkdir -p $(CLASS_DIR)
	@echo "#ifndef $(CLASS_NAME)_HPP" > $(HPP_FILE)
	@echo "#define $(CLASS_NAME)_HPP" >> $(HPP_FILE)
	@echo "" >> $(HPP_FILE)
	@echo "class $(CLASS_NAME)" >> $(HPP_FILE)
	@echo "{" >> $(HPP_FILE)
	@echo "public:" >> $(HPP_FILE)
	@echo "\t$(CLASS_NAME)();" >> $(HPP_FILE)
	@echo "\t~$(CLASS_NAME)();" >> $(HPP_FILE)
	@echo "};" >> $(HPP_FILE)
	@echo "" >> $(HPP_FILE)
	@echo "#endif // $(CLASS_NAME)_HPP" >> $(HPP_FILE)

	@echo "#include \"$(CLASS_NAME).hpp\"" > $(CPP_FILE)
	@echo "" >> $(CPP_FILE)
	@echo "$(CLASS_NAME)::$(CLASS_NAME)()" >> $(CPP_FILE)
	@echo "{" >> $(CPP_FILE)
	@echo "\t// Constructor implementation" >> $(CPP_FILE)
	@echo "}" >> $(CPP_FILE)
	@echo "" >> $(CPP_FILE)
	@echo "$(CLASS_NAME)::~$(CLASS_NAME)()" >> $(CPP_FILE)
	@echo "{" >> $(CPP_FILE)
	@echo "\t// Destructor implementation" >> $(CPP_FILE)
	@echo "}" >> $(CPP_FILE)
	@echo "✅ Class $(CLASS_NAME) created in $(CLASS_DIR)/"

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

show_progress:
		@for file in $(SRC); do \
			echo "$(GREEN)Compiling $$file "; \
		done; \
		echo "\nCompiled: 100%\n run: -> $(NAME) $(DEFAULT)"; \

clean:
	rm -f $(NAME)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all

git:
	git add .
	git commit -m "Update"
	git push

# Dummy target to handle class names passed as arguments
%:
@:

.PHONY: clean fclean re all show_progress run class
