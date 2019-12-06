# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/02 14:12:32 by tclaudel     #+#   ##    ##    #+#        #
#    Updated: 2019/12/06 10:52:31 by tclaudel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS_NAME	=	$(addprefix srcs/,cube3d.c ft_arg_error.c ft_arg_analyser.c ft_error.c ft_convert_line.c)

SRC_PATH	=	./

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
	@mkdir -p bin/srcs 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) Makefile
	@echo "$'[31mCompiling :$'[0m $<$'[0m"
	@gcc $(FLAG) -I $(HEADER) -I minilibx -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

norme:
	norminette srcs/*.c includes/*.c

push: fclean norme
	git push github master
	git push origin master

cleanlib: clean
	@make -C libft/ clean

fcleanlib: fclean
	@make -C libft/ fclean

relib: re
	@make -C libft/ re

git %:
	git add .
	git commit -m "$(@:git %=%)"
	push


.PHONY: all clean fclean re bonus norme push cleanlib fcleanlib relib
