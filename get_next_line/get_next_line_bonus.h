/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:00:57 by chris             #+#    #+#             */
/*   Updated: 2023/02/02 10:54:11 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 65536
# endif

char	*get_next_line(int fd);
char	*gnl_strdup(const char *s, char end);
char	*gnl_strjoin(char *s1, char *s2);
int		gnl_strlen(const char *s, char end);
void	cpy_len(const char *src, char *dest, int len);
int		line_counter(const char *str);
char	*reduce_tmp(char *str, int start);
int		read_new_line(char **tmp, int fd);
int		fill_buffer(char **buf, int fd);

#endif
