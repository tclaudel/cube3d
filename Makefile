# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/02 14:12:32 by tclaudel     #+#   ##    ##    #+#        #
#    Updated: 2019/12/09 17:28:00 by tclaudel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

BLUE =\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[0;38;5;121m
LIGHT_RED = \033[0;31;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m
GREY = \033[3;90m
ORANGE = \033[3;91m
YELLOW = \033[0;33m

SRCS_CONVERT	= $(addprefix converters/, ft_r_convert.c ft_no_convert.c ft_so_convert.c ft_we_convert.c ft_ea_convert.c ft_s_convert.c)

SRCS_GRAPHIC	= $(addprefix graphic/, ft_lunch_window.c)

SRCS_CORE		= cube3d.c ft_arg_error.c ft_arg_analyser.c ft_error.c ft_convert_line.c

SRCS_NAME	= $(SRCS_CONVERT) $(SRCS_GRAPHIC) $(SRCS_CORE) 

SRC_PATH	=	srcs/

SRCS		=	$(addprefix $(SRC_PATH), $(SRCS_NAME))

HEADER		=	./includes

OBJ_NAME	=	${SRCS_NAME:.c=.o}

OBJ_PATH	=	bin/

OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

NAME		=	cube3D

CC			=	cc

RM			=	rm -rf

FLAG		=	-Wall -Wextra -Werror -g3 #-fsanitize=address

LIBFT		=	libft/libft.a

minilibx	=	minilibx/libmlx.a

FRAMEWORK	=	-l mlx -framework OpenGL -framework AppKit -L minilibx  -I minilibx

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@if test ! -f $(LIBFT); then $(MAKE) relib ; fi
	@if test ! -f minilibx/libmlx.a; then make -C ./minilibx; fi
	@gcc $(FLAG) $(FRAMEWORK) $(LIBFT) $(OBJ) -o $(NAME)
	@printf "	\033[2K\r$(DARK_BLUE)cube3D:	$(LIGHT_GREEN)Updated\033[0m"
	@echo ""

$(OBJ_PATH):
	@mkdir -p bin/ 2> /dev/null
	@mkdir -p bin/ 2> /dev/null
	@mkdir -p bin/converters 2> /dev/null
	@mkdir -p bin/graphic 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) Makefile
	@printf "\033[2K\r$(LIGHT_RED)Compiling...	\033[37m$<\033[36m \033[0m"
	@sleep 0.1
	@gcc $(FLAG) -I $(HEADER) -I minilibx -c $< -o $@

clean:
	@printf "\33[2K\r$(LIGHT_RED)Deleting Cleaning cub3D srcs	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting Cleaning cub3D srcs.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting Cleaning cub3D srcs..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting Cleaning cub3D srcs...	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting Cleaning cub3D srcs	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting Cleaning cub3D srcs.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting Cleaning cub3D srcs..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting Cleaning cub3D srcs...	\033[37m"
	@sleep 0.1
	@${RM} ${OBJ_PATH}
	@printf "\33[2K\r$(LIGHT_RED)Deleted successfully!\n\033[0m"

fclean: clean
	@${RM} ${NAME}

re: fclean all

norme:
	@norminette $(SRC_PATH) $(OBJ_PATH)

push:
	$(MAKE) fcleanlib
	git push github master
	git push origin master

cleanlib:
	@$(MAKE) clean
	@make -C libft/ clean

fcleanlib:
	@$(MAKE) fclean
	@make -C libft/ fclean

relib:
	@$(MAKE) fclean
	@make -C libft/ re
	@$(MAKE) all

continue:
	@echo ""
	@while [ -z "$$CONTINUE" ]; do \
		read -r -p "Press [y/N] to continue : " CONTINUE; \
	done ; \
	[ $$CONTINUE == "y" ] || [ $$CONTINUE == "Y" ] || (echo "Exiting."; exit 2 2>/dev/null || true;)

git-%:
	@$(MAKE) norme
	@$(MAKE) continue
	git add .
	git status
	@$(MAKE) continue
	git commit -m "$(@:git-%=%)"
	@$(MAKE) push

.PHONY: all clean fclean re bonus norme push cleanlib fcleanlib relib continue git-%
