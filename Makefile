# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 15:09:43 by abourgue          #+#    #+#              #
#    Updated: 2023/06/20 14:32:22 by abourgue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src/

SRC = \
	push_swap.c push_swap_func_a.c push_swap_func_b.c \
	push_swap_func_utils.c push_swap_algo.c negToPos.c \
	raddix_sort.c

SOURCES = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

G		= \033[0;90m #gray
R		= \033[0;91m #red
GR		= \033[0;92m #green
Y		= \033[0;93m #yellow
B		= \033[0;94m #blue
M		= \033[0;95m #magenta
C		= \033[0;96m #cyan
W		= \033[0;97m #white
ENDCOLOR	= \033[0m #reset
BG_G		= \033[42m #bg_g

all: print $(NAME)

print:

	@echo "${GR}"
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗${Y}"
	@echo "██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ ${R}"
	@echo "██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║ "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "
	@echo "                                                                   ${M}    "
	@echo " █████╗ ██████╗  ██████╗ ██╗   ██╗██████╗  ██████╗ ██╗   ██╗███████╗       "
	@echo "██╔══██╗██╔══██╗██╔═══██╗██║   ██║██╔══██╗██╔════╝ ██║   ██║██╔════╝   ${B}"
	@echo "███████║██████╔╝██║   ██║██║   ██║██████╔╝██║  ███╗██║   ██║█████╗         "
	@echo "██╔══██║██╔══██╗██║   ██║██║   ██║██╔══██╗██║   ██║██║   ██║██╔══╝ ${C}    "
	@echo "██║  ██║██████╔╝╚██████╔╝╚██████╔╝██║  ██║╚██████╔╝╚██████╔╝███████╗       "
	@echo "╚═╝  ╚═╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝       "
	@echo "${ENDCOLOR}"

$(NAME): $(OBJS)
	@echo "${GR}"
	@make -C ./libft/
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

%.o: %.c
	@$(CC) -c $(CFLAGS) -c $< -o $@

clean:
	@make -C ./libft fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo fclean: OK

re: fclean all