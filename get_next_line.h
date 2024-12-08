/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:30:21 by hlichten          #+#    #+#             */
/*   Updated: 2024/12/08 18:03:20 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

// a supprimer pour les tests
#include <stdio.h> 
#include <stdio.h>
#include <fcntl.h>

int main (int argc, char **argv);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif 

char	*ft_free(char **str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen_gnl(char *str);
char 	*beg_of_line(char *buffer);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
#endif