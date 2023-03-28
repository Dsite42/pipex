# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:39:27 by cgodecke          #+#    #+#              #
#    Updated: 2023/03/27 18:35:58 by cgodecke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CC_FLAGS = -Wall -Wextra -Werror
AR = ar
AR_FLAGS = -crs
OBJDIR = obj
INFILES = 		ft_isalpha.c\
				ft_memcmp.c\
				ft_putendl_fd.c\
				ft_strdup.c\
				ft_strlen.c\
				ft_strtrim.c\
 				ft_atoi.c\
				ft_isascii.c\
				ft_memcpy.c\
				ft_putnbr_fd.c\
				ft_striteri.c\
				ft_strmapi.c\
				ft_substr.c\
				ft_bzero.c\
				ft_isdigit.c\
				ft_memmove.c\
				ft_putstr_fd.c\
				ft_strjoin.c\
				ft_strncmp.c\
  				ft_tolower.c\
				ft_calloc.c\
				ft_isprint.c\
				ft_memset.c \
				ft_split.c \
				ft_strlcat.c\
				ft_strnstr.c\
				ft_toupper.c\
				ft_isalnum.c\
				ft_itoa.c\
				ft_memchr.c\
				ft_putchar_fd.c\
				ft_strchr.c\
				ft_strlcpy.c\
				ft_strrchr.c\

OBJFILES = $(INFILES:%.c=$(OBJDIR)/%.o)

get_next_line =	get_next_line/get_next_line_bonus.c\
				get_next_line/get_next_line_utils_bonus.c\
				
get_next_line_OBJ = $(get_next_line:%.c=$(OBJDIR)/%.o)

ft_printf =		ft_printf/ft_printf_bonus.c\
				ft_printf/ft_put_single.c\
				ft_printf/ft_putnbr_base.c\
				ft_printf/ft_print_flags_bonus.c\
				ft_printf/ft_put_str.c\

ft_printf_OBJ = $(ft_printf:%.c=$(OBJDIR)/%.o)


BONUSFILES = 	ft_lstadd_back.c\
				ft_lstlast.c\
				ft_lstadd_front.c\
				ft_lstmap.c\
				ft_lstclear.c\
				ft_lstnew.c\
				ft_lstdelone.c\
				ft_lstsize.c\
				ft_lstiter.c\

BONUSOBJFILES = $(BONUSFILES:%.c=$(OBJDIR)/%.o)

NAME = libft.a

all: setup $(NAME)

$(NAME): $(OBJFILES) $(BONUSOBJFILES) $(get_next_line_OBJ) $(ft_printf_OBJ)
#$(CC) -c $(CC_FLAGS) $(OBJFILES) $(Get_Next_Line_OBJ)
	$(AR)  $(AR_FLAGS) $(NAME) $(OBJFILES) $(BONUSOBJFILES) $(get_next_line_OBJ) $(ft_printf_OBJ)

$(OBJDIR)/%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

setup:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/get_next_line/
	@mkdir -p $(OBJDIR)/ft_printf/

clean:
	rm -f $(OBJFILES) $(get_next_line_OBJ) $(ft_printf_OBJ) $(BONUSOBJFILES)
	rm -r -f obj/

fclean: clean
	rm -f $(NAME)

bonus: 
	$(CC) -c $(CC_FLAGS) $(BONUSFILES)
	$(AR)  $(AR_FLAGS) $(NAME) $(BONUSOBJFILES)

re: fclean all

.PHONY: all clean fclean bonus re