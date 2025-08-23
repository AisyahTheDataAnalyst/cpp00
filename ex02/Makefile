# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 18:50:01 by aimokhta          #+#    #+#              #
#    Updated: 2025/08/23 22:39:19 by aimokhta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++

#compilation flags
CFLAG = -Wall -Werror -Wextra -std=c++98 -g -O0
# -g3 -O3 -O0 -fsanitize=address -fsanitize-recover=leak
# valgrind --leak-check=full --show-leak-kinds=all
# -g = gives error messages for debugging, needed by gdb / valgrind / helgrind

# directory that contains source files
# SRC_DIR = src

SRC =	Account.cpp \
		tests.cpp
	
# INC = -I include
# this is what is caused to not write explicit path for all #includes in all header and c files
# -I means it will search the header in that directory that is mentioned in the each file's #include

OBJ_FOLDER = obj_files

# patsubst : pattern substitution function
# create a list of .o files in the object folder
OBJ_SRC = $(patsubst %.c, $(OBJ_FOLDER)/%.o, $(SRC))

# color
GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m  	#white

all: $(NAME)

$(NAME) : $(OBJ_SRC)
	$(CC) $(CFLAG) $(INC) $(OBJ_SRC) -o $(NAME)
	@echo "${GREEN}----------COMPILED DONE----------\n${RESET}"

$(OBJ_FOLDER)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAG) $(INC) -c $< -o $@
# add $(INC) to not do explicit path to all #include of all header and c files

clean:
	@rm -rf $(OBJ_FOLDER)
	@echo "${GREEN}----------CLEANED----------\n${RESET}"

fclean : clean
	rm -f $(NAME)
	@echo "${GREEN}----------FULLY REMOVE----------\n${RESET}"

re : fclean all

.PHONY : all clean fclean re