# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/31 22:14:13 by itkimura          #+#    #+#              #
#    Updated: 2022/08/24 14:45:41 by itkimura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TARGET
NAME	= libft.a

# GCC
CC		= gcc -Wall -Wextra -Werror

# DIRECTORIES
INC_DIR	= ./includes/
OBJ_DIR	= ./objects/
SRC_DIR = ./srcs/

# FILES
SRCS	=	ft_putchar.c	ft_putchar_fd.c		ft_putendl.c	ft_tolower.c	\
			ft_putendl_fd.c	ft_putnbr.c			ft_putnbr_fd.c	ft_toupper.c	\
			ft_putstr.c		ft_putstr_fd.c		ft_strlen.c		ft_atoi.c		\
			ft_isalpha.c	ft_itoa.c			ft_strjoin.c	ft_bzero.c		\
			ft_isalnum.c	ft_isascii.c		ft_isdigit.c	ft_isprint.c	\
			ft_memccpy.c	ft_strnew.c			ft_memcpy.c		ft_memset.c		\
			ft_strcat.c		ft_strchr.c			ft_strcmp.c		ft_strcpy.c		\
			ft_strdup.c		ft_strlcat.c		ft_strncat.c	ft_strncmp.c	\
			ft_strncpy.c	ft_strnstr.c		ft_strrchr.c	ft_strstr.c		\
			ft_strequ.c		ft_strnequ.c		ft_strtrim.c	ft_isspace.c	\
			ft_strclr.c		ft_strdel.c			ft_strsub.c		ft_striter.c	\
			ft_striteri.c	ft_memalloc.c		ft_memchr.c		ft_memcmp.c		\
			ft_memdel.c		ft_memmove.c		ft_strmapi.c	ft_strmap.c		\
			ft_strsplit.c	ft_lstnew.c			ft_lstadd.c		ft_lstdelone.c	\
			ft_lstdel.c		ft_lstiter.c		ft_lstmap.c		ft_atoli.c
OBJ		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# GNT
GNT = get_next_line
GNT_DIR = ./get_next_line/
GNT_SRC = get_next_line.c
GNT_OBJS = $(addprefix $(OBJ_DIR), $(GNT_SRC:.c=.o))

# COLORS
GREEN  := $(shell tput -Txterm setaf 2)
YELLOW := $(shell tput -Txterm setaf 3)
WHITE  := $(shell tput -Txterm setaf 7)
RESET  := $(shell tput -Txterm sgr0)
BOLD := $(shell tput bold)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -I$(INC_DIR) -I$(GNT_DIR) -o $(GNT_OBJS) -c $(GNT_DIR)$(GNT_SRC)
	@ar rc $(NAME) $(OBJ) $(GNT_OBJS)
	@echo "${BOLD}[libft]${RESET}\t\tCompiled!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I$(INC_DIR) -I$(GNT_DIR) -o $@ -c $^


clean:
	@rm -rf $(OBJ_DIR)
	@echo "${BOLD}[libft]${RESET}\t\tObject files has been deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "${BOLD}[libft]${RESET}\t\tExecutable file has been deleted"

re: clean fclean all

.PHONY: all clean fclean re
