# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 18:50:01 by aimokhta          #+#    #+#              #
#    Updated: 2025/09/01 10:30:09 by aimokhta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook_software

CC = c++

#compilation flags
CFLAG = -Wall -Werror -Wextra -std=c++98 -g -O0
# -g3 -O3 -O0 -fsanitize=address -fsanitize-recover=leak
# valgrind --leak-check=full --show-leak-kinds=all
# -g = gives error messages for debugging, needed by gdb / valgrind / helgrind

SRC =	\
		main.cpp \
		PhoneBook.cpp 

OBJ_FOLDER = obj_files

# patsubst : pattern substitution function
# create a list of .o files in the object folder
OBJ_SRC = $(patsubst %.cpp, $(OBJ_FOLDER)/%.o, $(SRC))

# color
GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m  	#white

all: $(NAME)

$(NAME) : $(OBJ_SRC)
	$(CC) $(CFLAG) $(OBJ_SRC) -o $(NAME)
	@echo "${GREEN}----------COMPILED DONE----------\n${RESET}"

$(OBJ_FOLDER)/%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf $(OBJ_FOLDER)
	@echo "${GREEN}----------CLEANED----------\n${RESET}"

fclean : clean
	rm -f $(NAME)
	@echo "${GREEN}----------FULLY REMOVE----------\n${RESET}"

re : fclean all

.PHONY : all clean fclean re