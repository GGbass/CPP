# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 14:58:03 by marvin            #+#    #+#              #
#    Updated: 2025/04/18 14:58:03 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = violence

SRC =	./Weapon.cpp \
		./HumanB.cpp \
		./HumanA.cpp \
		./main.cpp

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address,leak

CC = c++

all: $(NAME) show_progress

run:
	@make && ./$(NAME)

$(NAME): $(OBJ)

	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

show_progress:
		@for file in $(SRC); do \
			echo "$(GREEN)Compiling $$file "; \
		done; \
		echo "\nCompiled: 100%\n run: -> $(NAME) $(DEFAULT)"; \

clean:
	rm -f $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all


.PHONY: clean fclean re all
