/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:13:18 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/04 21:15:35 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <strings.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// This function ft_atoi converts the string to an int.The string may begin with
// an arbitrary amount of white space (as determined by isspace(3)) followed
// by a single optional '+' or '-' sign.
// Return: The converted string number as int.

int		ft_atoi(const char *str);

// This function bzero erases n bytes in the memory from the pointer
// by overwriting it with '\0'
// Return: None.
void	ft_bzero(void *prt, size_t n);

// This function ft_calloc allocates memory for an array of nmemb elements of
// size bytes each. The memory is set to zero.
// Return: If nmemb or size is 0, then calloc() returns NULL. If the multi-
// plication of nmemb and size would result in integer overflow, then calloc()
// returns an error. By sucsess returns a pointer to the allocated memory.
void	*ft_calloc(size_t nmemb, size_t size);

// This function ft_isalpha checks if the character is alphabetic (a-z && A-Z).
// No locale.
// Return: 1 if yes 0 if not as int.
int		ft_isalpha(int c);

// This function ft_isalnum checks if the character is digit (0-9)
// or alphabetic (a-z && A-Z).
// Return: 1 if yes 0 if not as int.
int		ft_isalnum(int c);

// This function ft_isascii checks if the character is an ASCII (0-127).
// Return: 1 if yes 0 if not as int.
int		ft_isascii(int c);

// This function ft_isdigit checks if the character is digit (0-9).
// Return: 1 if yes 0 if not as int.
int		ft_isdigit(int c);

// This function ft_isprint checks if the character is a printable character.
// Return: 1 if yes 0 if not as int.
int		ft_isprint(int c);

// This function ft_itoa converts an int to a string.
// Return: The string representing the integer. NULL if the allocation fails.

char	*ft_itoa(int n);

// This function ft_memset overwrites n bytes in the memory from the pointer
// by constant byte c. 
// Return: pointer to memory area prt.
void	*ft_memset(void *prt, int c, size_t n);

// This function ft_memchr scans n bytes of the memory area pointed to by prt
// for the first instance of c.
// Return: A pointer to the matching byte or NULL if the character
// does not occur in the given memory area.
void	*ft_memchr(const void *prt, int c, size_t n);

// This function ft_memcmp compares the first n bytes (each interpreted 
// as unsigned char) of the memory areas s1 and s2.
// Return: Difference between the first pair of bytes (interpreted as unsigned 
//char)that differ in s1 and s2 as int. If n is zero, the return value is zero.
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// This function ft_memcpy copies n bytes from memory area src to memory area 
// dest. The memory areas shall not overlap.
// Return: A pointer to the copy.
void	*ft_memcpy(void *dest, const void *src, size_t n);

// This function ft_memmove copies n bytes from memory area src to memory area
// dest and is able to use overlap src and dest.
// Return: A pointer to the copy.
void	*ft_memmove(void *dest, const void *src, size_t len);

// This function ft_lstadd_back adds the node ’new’ at the end of the list.
// Return: None.
void	ft_lstadd_back(t_list **lst, t_list *new);

// This function ft_lstadd_front adds the node ’new’ at the beginning of the 
// list.
// Return: None.
void	ft_lstadd_front(t_list **lst, t_list *new);

// This function ft_lstclear deletes and frees the given node and every
// successor of that node, using the function ’del’ and free(3). Finally, the
// pointer to the list must be set to NULL.
// Return: None.
void	ft_lstclear(t_list **lst, void (*del)(void *));

// This function ft_lstdelone takes as a parameter a node and frees the memory
// of the node’s content using the function ’del’ given as a parameter and free
// the node. The memory of ’next’ is not freed.
// Return: None.
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// This function ft_lstiter Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.
// Return: None.
void	ft_lstiter(t_list *lst, void (*f)(void *));

// This function ft_lstlast returns the last node of the list.
// Return: Last node of the list as t_list.
t_list	*ft_lstlast(t_list *lst);

// This function ft_lstmap iterates the list ’lst’ and applies the function ’f’
// on the content of each node. Creates a new list resulting of the successive
// applications of the function ’f’. The ’del’ function is used to delete the
// content of a node if needed.
// Return: The new list. NULL if the allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// This function ft_lstnew creates a new node. The member variable ’content’ is
// initialized with the value of the parameter ’content’. The variable ’next’
// is initialized to NULL.
// Return: The new node as t_list.
t_list	*ft_lstnew(void *content);

// This function ft_lstsize Counts the number of nodes in a list.
// Return: The length of the list as int.
int		ft_lstsize(t_list *lst);

// This function ft_putchar_fd outputs the character ’c’ to the given file
// descriptor.
// Return: None.
void	ft_putchar_fd(char c, int fd);

// This function ft_putendl_fd outputs the string ’s’ to the given file
// descriptor followed by a newline.
// Return: None.
void	ft_putendl_fd(char *s, int fd);

// This function ft_putendl_fd outputs the integer ’n’ to the given file
// descriptor.
// Return: None.
void	ft_putnbr_fd(int n, int fd);

// This function ft_putchar_fd outputs the string ’s’ to the given file
// descriptor.
// Return: None.
void	ft_putstr_fd(char *s, int fd);

// This function ft_split creates a new array of strings that have been split
// from a string seperated by a char. The array ends with a NULL pointer.
// Return: Pointer to the new array of new strings resulting from the split.
// NULL if the allocation fails.
char	**ft_split(char const *s, char c);

// This function ft_strchr searchs the first occurance of the character
// in a string s.
// Return: A pointer to the matching character or NULL if it is not found.
char	*ft_strchr(const char *s, int c);

// This function ft_strdup duplicates a string.
// Return: A pointer to the duplicated string. It returns NULL if insufficient
// memory was available.
char	*ft_strdup(const char *src);

// This function ft_striteri applies function f to each character of the string,
// so that it can be manipulated.
// Return: None.
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// This function ft_strjoin create a new string by concatenate two strings.
// Return: Pointer to new string or NULL if memory allocation fails.
char	*ft_strjoin(char const *s1, char const *s2);

// This function ft_strlcat copies n-1 bytes to the end of dest string 
// by 0 terminating the results. src and dest must be NUL-terminated.
// Return: The total length of the string they tried to create (initial length
// of dest plus length of src).
size_t	ft_strlcat(char *dest, const char *src, size_t size);

// This function ft_strlcpy copies n-1 bytes to a dest string by 0 terminating
// the results. src must be NUL-terminated.
// Return: The total length of the string they tried to create (length of src).
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

// This function ft_strlen is checking the length of a string.
// Return: length of a string as int.
size_t	ft_strlen(const char *str);

// This function ft_strmapi creats a new string with the results of appling th
// function f to each character of the string s.
// Return: A pointer to the string created from the successive applications
// of ’f’. Returns NULL if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// This function ft_strncmp compares the first n bytes of string s1 and s2.
// Return: Difference between the first pair of bytes that differ in
// s1 and s2 as int. If n is zero, the return value is zero.
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// This function ft_strnstr search for a string in another string withhin the
// first n characters.
// Return: A pointer to the start of the searched string or NULL if the string
// is not found or the srource string if to_find is emty.
char	*ft_strnstr(const char *ccstr, const char *ccto_find, size_t n);

// This function ft_strrchr searchs the last occurance of the character
// in a string s.
// Return: A pointer to the matching character or NULL if it is not found.
char	*ft_strrchr(const char *s, int c);

// This function ft_strtrim creates a copy of a string, but removed the
// characters specified in set from the beginning and end of the string.
// Return: Pointer to the trimmed string. NULL if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set);

// This function ft_substr creates a new substring out of a strings.
// The substring begins at index ’start’ and is of maximum size ’len’.
// Return: Pointer to new substring or NULL if memory allocation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len);

// This function ft_tolower convert uppercase letters to lowercase.
// No locale.
// Return: 1 if yes 0 if not as int.
int		ft_tolower(int c);

// This function ft_toupper convert lowercase letters to uppercase.
// No locale.
// Return: 1 if yes 0 if not as int.
int		ft_toupper(int c);
#endif
