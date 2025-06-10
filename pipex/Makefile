# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xzhang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 13:26:08 by xzhang            #+#    #+#              #
#    Updated: 2023/11/19 13:26:10 by xzhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
RED    = '\033[1;31m'
GREEN  = '\033[1;32m'
BLUE   = '\033[1;34m'
CYAN   = '\033[0;36m'

#Variables
NAME   = pipex
NAME_B = pipex_bonus

SRCS = pipex.c pipex_utils.c
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
MAIN = srcs/pipex.c

B_SRCS = pipex_bonus.c pipexbonus_utils.c
B_SRC = $(addprefix $(SRC_DIR), $(B_SRCS))
B_OBJS = $(addprefix $(OBJ_DIR), $(B_SRCS:.c=.o))
B_MAIN = srcs/pipex_bonus.c

SRC_DIR = srcs/
OBJ_DIR = objs/

HEADER = -Iinclude

LIBFT = ./libft/libft.a
LIB_DIR = libft

CC     = gcc
RM     = rm -rf
CFLAGS = -Wall -Wextra -Werror -g

#Main targets
all: ${NAME}
	@echo " $(CYAN)\33[1m>>===================================================<<"
	@echo " ||██╗  ██╗███████╗██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ||"
	@echo " ||╚██╗██╔╝╚══███╔╝██║  ██║██╔══██╗████╗  ██║██╔════╝ ||"
	@echo " || ╚███╔╝   ███╔╝ ███████║███████║██╔██╗ ██║██║  ███╗||"
	@echo " || ██╔██╗  ███╔╝  ██╔══██║██╔══██║██║╚██╗██║██║   ██║||"
	@echo " ||██╔╝ ██╗███████╗██║  ██║██║  ██║██║ ╚████║╚██████╔╝||"
	@echo " ||╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ||"
	@echo " ||                                                   ||"
	@echo " ||             ██████╗ ██╗██████╗ ███████╗██╗  ██╗   ||"
	@echo " ||		██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝   ||"
	@echo " ||		██████╔╝██║██████╔╝█████╗   ╚███╔╝    ||"
	@echo " ||		██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗    ||"
	@echo " ||		██║     ██║██║     ███████╗██╔╝ ██╗   ||"
	@echo " ||		╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝   ||"
	@echo " >>===================================================<<"
	@echo 		Hello Welcome to pipex!

bonus: $(NAME_B)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(CYAN)\33[1mPipex made!"

$(NAME_B): $(B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(NAME_B)
	@echo "$(CYAN)\33[1mBonus made!"

$(LIBFT):
	make re -C ./libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C ./$(LIB_DIR)
	${RM} $(OBJ_DIR)

fclean: clean
	make fclean -C ./$(LIB_DIR)
	${RM} $(NAME) $(NAME_B)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus
