# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:39:27 by cgodecke          #+#    #+#              #
#    Updated: 2023/03/28 13:11:01 by cgodecke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CC_FLAGS = -g -Wall -Wextra -Werror
OBJDIR = obj
INFILES = 	list/pipex_lstadd_back.c\
			list/pipex_lstclear.c\
			list/pipex_lstlast.c\
			list/pipex_lstnew.c\
				of/of_fd_printf.c\
				of/of_free_arr.c\
				of/of_nstrjoin.c\
			main.c\
			awk_split.c\
			init_cmds.c\
			pipex_error.c		
			
OBJFILES = $(INFILES:%.c=$(OBJDIR)/%.o)

BONUSFILES = 	helper/calc_single_index.c\
				
BONUSOBJFILES = $(BONUSFILES:%.c=$(OBJDIR)/%.o)

NAME = pipex
NAME_BONUS = checker

all: setup $(NAME)

$(NAME): $(OBJFILES)
	cd libft && $(MAKE)
	$(CC) $(CC_FLAGS) $(INFILES) -o $(NAME)  libft/libft.a

$(OBJDIR)/%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

setup:
	@mkdir -p $(OBJDIR)/obj
	@mkdir -p $(OBJDIR)/list
	@mkdir -p $(OBJDIR)/of

clean:
	rm -f $(OBJFILES) $(BONUSOBJFILES)
	rm -r -f obj/
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	cd libft && $(MAKE) fclean
	
#bonus: all $(BONUSOBJFILES)
#	$(CC) $(CC_FLAGS) $(BONUSOBJFILES) -o $(NAME_BONUS)  libft/libft.a

re: fclean all

.PHONY: all clean fclean bonus re