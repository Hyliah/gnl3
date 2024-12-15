/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:30:12 by hlichten          #+#    #+#             */
/*   Updated: 2024/12/13 20:10:52 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str, int gnl)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	
	if (gnl == 0)
	{
		while (str[i])
		i++;
	}
	else
	{
		while (str[i] && str[i] != '\n') // verifier comment gerer le \n
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_gnl(s1, 0) + ft_strlen_gnl(s2, 0);
	str = (char *)malloc(sizeof (char) * len);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[len] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;

	c1 = (unsigned char)c;
	while (*s)
	{
		if (*s == c1)
			return ((char *)s);
		s++;
	}
	if (c1 == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	char			*str;

	i = count * size;
	str = (char *)malloc(sizeof(char) * (i));
	if (!str)
		return (NULL);
	ft_bzero(str, i);
	return (str);

}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str =(char *)s;
	i = 0;
	while (i < n)
		str[i++] = '\0';
}

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	if (!str)
// 		return (0);
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }