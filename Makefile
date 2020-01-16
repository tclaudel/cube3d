# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/02 14:12:32 by tclaudel     #+#   ##    ##    #+#        #
#    Updated: 2020/01/16 16:44:25 by tclaudel    ###    #+. /#+    ###.fr      #
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

SRCS_CONVERT	=	$(addprefix converters/, ft_r_convert.c ft_no_convert.c \
					ft_so_convert.c ft_we_convert.c ft_ea_convert.c ft_s_convert.c \
					ft_f_convert.c ft_c_convert.c ft_convert_map.c)

SRCS_CUB		=	$(addprefix cub/, ft_init_window.c ft_cub.c ft_init_player.c ft_move.c \
					ft_load_textures.c ft_raycast.c ft_key.c ft_draw.c ft_sort_sprites.c \
					ft_raycast_sprites.c ft_draw_sprite.c ft_save_bitmap.c ft_close.c \
					ft_draw_lifebar.c ft_draw_hud.c)

SRCS_PARSING	=	$(addprefix parsing/, ft_check_map.c ft_arg_error.c ft_arg_analyser.c \
					ft_error.c ft_convert_line.c ft_set_struct.c ft_set_sprites.c)

SRCS_NAME		=	cube3d.c $(SRCS_CONVERT) $(SRCS_CUB) $(SRCS_PARSING)

SRC_PATH		=	srcs/

SRCS			=	$(addprefix $(SRC_PATH), $(SRCS_NAME))

HEADER			=	includes/

OBJ_NAME		=	${SRCS_NAME:.c=.o}

OBJ_PATH		=	bin/

OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

NAME			=	cub3D

CC				=	cc

RM				=	rm -rf

FLAG			=	-Wall -Wextra -Werror -g3 #-fsanitize=address

LIBFT			=	libft/libft.a

MINILIBX		=	minilibx/libmlx.a

FRAMEWORK		=	-l mlx -framework OpenGL -framework AppKit -L minilibx -O3 -I minilibx

all: $(OBJ_PATH) $(LIBFT) $(MINILIBX) $(NAME) includes/config.h includes/cube3d.h includes/keycode.h
	@:

$(LIBFT):
	@make -C libft/

$(MINILIBX):
	make -C minilibx/

$(NAME): $(OBJ) $(HEADER)
	@gcc $(FLAG) $(FRAMEWORK) $(LIBFT) $(OBJ) -o $(NAME)
	@printf "	\033[2K\r$(DARK_BLUE)cube3D\t:\t$(LIGHT_GREEN)Updated\n\033[0m"

$(OBJ_PATH):
	@mkdir -p bin/ 2> /dev/null
	@mkdir -p bin/converters 2> /dev/null
	@mkdir -p bin/cub 2> /dev/null
	@mkdir -p bin/parsing 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) Makefile includes/config.h includes/cube3d.h includes/keycode.h
	@printf "\033[2K\r$(LIGHT_RED)Compiling...	\033[37m$<\033[36m \033[0m"
	@gcc $(FLAG) -I $(HEADER) -I minilibx -c $< -o $@

clean:
	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/...	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/...	\033[37m"
	@sleep 0.1
	@${RM} ${OBJ_PATH} cube3D.dSYM
	@printf "\33[2K\r$(LIGHT_RED)Deleted successfully!\n\033[0m"

fclean: clean
	@${RM} ${NAME}

re: fclean all

norme:

	@norminette $(SRC_PATH) $(HEADER)
normed:

	@norminette $(SRC_PATH) $(HEADER)
	@$(MAKE) continue
	@echo ""
	@git add .
	@git commit -m "normed" 1>/dev/null
	@printf "\33[2K\r$(YELLOW)Push on repositories ?\n\033[0m"
	@$(MAKE) continue
	@echo ""
	@$(MAKE) push

push:

	@printf "\33[2K\r$(LIGHT_RED)Pushing 	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing .	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing ..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing ...	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing 	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing .	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing ..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing ...	\033[37m"
	@sleep 0.1
	@git push github master 2>/dev/null
	@printf "\33[2K\r$(FLASH_GREEN)Pushed successfully on github !\n\033[0m"
	@git push origin master 2>/dev/null
	@printf "\33[2K\r$(FLASH_GREEN)Pushed successfully on vogsphere !\n\033[0m"

lib:
	@make -C libft/

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
	[ $$CONTINUE == "y" ] || [ $$CONTINUE == "Y" ] || (echo "Exiting ..."; $(MAKE) ew ; exit 1 2> /dev/null)

git-%:
	@$(MAKE) norme
	@$(MAKE) continue
	@echo ""
	@git add .
	@git status
	@$(MAKE) continue
	@echo ""
	@printf "\33[2K\r$(FLASH_GREEN)Commit name :\t[$(@:git-%=%)]\n\033[0m"
	@$(MAKE) continue
	@git commit -m "$(@:git-%=%)" 1>/dev/null
	@printf "\33[2K\r$(YELLOW)\nPush on repositories ?\033[0m"
	@echo ""
	@$(MAKE) continue
	@echo ""
	@$(MAKE) push
	@echo ""
	@printf "\33[2K\r$(GREEN)Everything done\n\n\033[0m"

call: all
	@nm -g $(addprefix ${OBJ_PATH}, ${OBJ_NAME})

ew:
	@say -v Fiona ew

full_check: all
	@$(MAKE) norme
	@$(MAKE) continue
	@echo ""
	@$(MAKE) call
	@$(MAKE) continue
	@echo ""
	@$(MAKE) relib
	@printf "\33[2K\r$(FLASH_GREEN)\nCommit ?\n\033[0m"
	@$(MAKE) continue
	@echo ""
	@git add .
	@git commit -m "full checked" 1>/dev/null
	@printf "\33[2K\r$(YELLOW)Push on repositories ?\n\033[0m"
	@$(MAKE) continue
	@echo ""
	@$(MAKE) push

.PHONY: all clean fclean re bonus norme push cleanlib fcleanlib relib continue git-%