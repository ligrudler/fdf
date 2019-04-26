# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 16:03:44 by jmoucach          #+#    #+#              #
#    Updated: 2019/04/26 16:03:46 by jmoucach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
#								Colors										   #
################################################################################

RED= \033[31m
WHITE= \033[0m
GREEN= \033[32m
CYAN= \033[36m
BLUE= \033[34m

################################################################################
#								Macros										   #
################################################################################
NAME= fdf
CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRC_DIR= ./src
FRAMEWORK=  -framework OpenGL -framework AppKit
SRC= main.c\
	 init.c\
	 draw.c\
	 ft_parsing.c\
	 ft_mlx.c\
	 ft_bresenham.c\
	 key_handler.c
OBJ= $(SRC:.c=.o)
LIB= -L /usr/local/lib -lmlx\
	 -L libft -lft
VPATH= ./src

###############################################################################
#								Rules										  #
###############################################################################

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "Creating $(BLUE)libft$(WHITE)"
	@ make -C libft
	@ echo "$(GREEN)Libft$(WHITE) created"
	@ echo "Creating $(BLUE)$@$(WHITE) executable"
	@ $(CC) -o $@ $(CFLAGS) $(OBJ) $(LIB) $(FRAMEWORK)
	@echo "$(GREEN)$@$(WHITE) executable created"
	@ echo "$(GREEN)DONE$(WHITE)"


%.o: %.c
	@ $(CC) -o $@ -c $< $(CFLAGS)
	@ echo "$(GREEN)[✔]$(WHITE)$@"

clean:
	@ echo "Cleaning libft"
	@ make -C libft fclean
	@ echo "Objects deleted"
	@ rm -rf $(OBJ)

fclean: clean
	@ echo "Deep cleaning libft"
	@ make -C libft fclean
	@ echo "Executable deleted"
	@ rm -rf $(NAME)

re: fclean all
