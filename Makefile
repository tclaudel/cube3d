# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/02 14:12:32 by tclaudel     #+#   ##    ##    #+#        #
#    Updated: 2019/12/09 13:03:09 by tclaudel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

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

MINILIBX	=	-l mlx -framework OpenGL -framework AppKit -L minilibx minilibx/libmlx.a -I minilibx

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@make -C libft/
	@gcc $(FLAG) $(MINILIBX) $(LIBFT) $(OBJ) -o $(NAME)
	@echo "$'[32m\nCompiling effected successfully!"

$(OBJ_PATH):
	@mkdir -p bin/ 2> /dev/null
	@mkdir -p bin/ 2> /dev/null
	@mkdir -p bin/converters 2> /dev/null
	@mkdir -p bin/graphic 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) Makefile
	@echo "$'[31mCompiling :$'[0m $<$'[0m"
	@gcc $(FLAG) -I $(HEADER) -I minilibx -c $< -o $@

clean:
	${RM} ${OBJ_PATH}

fclean: clean
	${RM} ${NAME}

re: fclean all

norme:
	norminette srcs/ includes/

push: fclean
	git push github master
	git push origin master

cleanlib: clean
	@make -C libft/ clean

fcleanlib: fclean
	@make -C libft/ fclean

relib: re
	@make -C libft/ re

git-%: norme
	@read -p "Continue ?" module;
	git add .
	git commit -m "$(@:git-%=%)"
	git status
	@read -p "Continue ?" module;
	$(MAKE) push

.PHONY: all clean fclean re bonus norme push cleanlib fcleanlib relib
