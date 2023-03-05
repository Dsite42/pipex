# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chris <chris@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:39:27 by cgodecke          #+#    #+#              #
#    Updated: 2023/03/01 15:24:34 by chris            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CC_FLAGS = -g #-Wall -Wextra -Werror
OBJDIR = obj
INFILES = 	*.c\
			get_next_line/get_next_line_bonus.c\
			get_next_line/get_next_line_utils_bonus.c\


OBJFILES = $(INFILES:%.c=$(OBJDIR)/%.o)

BONUSFILES = 	helper/calc_single_index.c\
				
BONUSOBJFILES = $(BONUSFILES:%.c=$(OBJDIR)/%.o)

NAME = pipex
NAME_BONUS = checker

all: $(NAME)

$(NAME):
	cd libft && $(MAKE)
	$(CC) $(CC_FLAGS) $(INFILES) -o $(NAME)  libft/libft.a

$(OBJDIR)/%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

setup:
	@mkdir -p $(OBJDIR)/obj
#@mkdir -p $(OBJDIR)/helper
#@mkdir -p $(OBJDIR)/list
#@mkdir -p $(OBJDIR)/operations
#@mkdir -p $(OBJDIR)/bonus
	@mkdir -p $(OBJDIR)/get_next_line/

clean:
	rm -f $(OBJFILES) $(BONUSOBJFILES)
	rm -r -f obj/
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	cd libft && $(MAKE) fclean
	
bonus: all $(BONUSOBJFILES)
	$(CC) $(CC_FLAGS) $(BONUSOBJFILES) -o $(NAME_BONUS)  libft/libft.a

re: fclean all

.PHONY: all clean fclean bonus re