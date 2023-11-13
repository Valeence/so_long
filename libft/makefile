# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vandre <vandre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:54:22 by vandre            #+#    #+#              #
#    Updated: 2023/11/09 17:54:46 by vandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		:=		src
OBJ_DIR		:=		obj
INCLUDE		=		../include

NAME		=		libft.a
SRC			=		$(wildcard $(SRC_DIR)/*.c)
OBJ			=		$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)	

FLAGS		=		-Wall -Werror -Werror -I

$(NAME):			$(OBJ)
					ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

all:				$(NAME)

clean:
					rm -rf $(OBJ_DIR)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
