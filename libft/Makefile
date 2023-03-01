# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chris <chris@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:39:27 by cgodecke          #+#    #+#              #
#    Updated: 2023/01/09 13:57:55 by chris            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CC_FLAGS = -Wall -Wextra -Werror
AR = ar
AR_FLAGS = -crs
INFILES = 		./ft_isalpha.c\
				./ft_memcmp.c\
				./ft_putendl_fd.c\
				./ft_strdup.c\
				./ft_strlen.c\
				./ft_strtrim.c\
 				./ft_atoi.c\
				./ft_isascii.c\
				./ft_memcpy.c\
				./ft_putnbr_fd.c\
				./ft_striteri.c\
				./ft_strmapi.c\
				./ft_substr.c\
				./ft_bzero.c\
				./ft_isdigit.c\
				./ft_memmove.c\
				./ft_putstr_fd.c\
				./ft_strjoin.c\
				./ft_strncmp.c\
  				./ft_tolower.c\
				./ft_calloc.c\
				./ft_isprint.c\
				./ft_memset.c \
				./ft_split.c \
				./ft_strlcat.c\
				./ft_strnstr.c\
				./ft_toupper.c\
				./ft_isalnum.c\
				./ft_itoa.c\
				./ft_memchr.c\
				./ft_putchar_fd.c\
				./ft_strchr.c\
				./ft_strlcpy.c\
				./ft_strrchr.c\

OBJFILES = $(INFILES:.c=.o)
BONUSFILES = 	./ft_lstadd_back.c\
				./ft_lstlast.c\
				./ft_lstadd_front.c\
				./ft_lstmap.c\
				./ft_lstclear.c\
				./ft_lstnew.c\
				./ft_lstdelone.c\
				./ft_lstsize.c\
				./ft_lstiter.c\

BONUSOBJFILES = $(BONUSFILES:.c=.o)

NAME = libft.a

$(NAME):
	$(CC) -c $(CC_FLAGS) $(INFILES)
	$(AR)  $(AR_FLAGS) $(NAME) $(OBJFILES)

all: $(NAME)

clean:
	rm -f $(OBJFILES) $(BONUSOBJFILES)

fclean: clean
	rm -f $(NAME)

bonus: 
	$(CC) -c $(CC_FLAGS) $(BONUSFILES)
	$(AR)  $(AR_FLAGS) $(NAME) $(BONUSOBJFILES)

re: fclean all

.PHONY: all clean fclean bonus re