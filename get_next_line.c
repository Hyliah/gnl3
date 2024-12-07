/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:30:15 by hlichten          #+#    #+#             */
/*   Updated: 2024/12/07 22:14:14 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	**ft_free(char *str)
{
	free(str);
	str = (NULL);
	return (NULL);
}
static char *beg_of_line(char *buffer)
{
	int	i;
	char *tmp;

	i = 0;
	if (!buffer[i])
		return(ft_free(&buffer));
	tmp = calloc(ft_strlen_gnl(buffer) + 2, sizeof(char));
	while(buffer[i] || buffer[i] != '\n')
		tmp[i++] = buffer[i++];
	tmp[i] = '\n';
	i++;
	tmp[i] = '\0';
	ft_free(&buffer);
	return(tmp);
}
static char	*find_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*tmp;
	
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i != '\n'])
		i++;
	if (!buffer[i])
		return (ft_free(&buffer));
	tmp = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!tmp)
		return (NULL);
	i++;
	while (buffer[i])
		tmp[j++] = buffer[i++];
	tmp[j] = '\0';
	ft_free(&buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*next_line;
	char		*ret;
	int			rd;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!next_line)
		next_line = ft_calloc(1, sizeof(char));
	if (!ret)
		ret = ft_calloc(1, sizeof(char));
	rd = 1;
	while (rd > 0 || ft_strchr(buffer, '\n') == 0) // si il n y a pas de \n dans le buffer, on va tout copier dans le next line --> gerer le malloc dans une nouvelle fonction
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		next_line = ft_strjoin(next_line, buffer);
	}
	if (rd > 0 || ft_strchr(buffer, '\n') == 1)
	{
		// recup le debu jusqu a \n dans next line a la suite de donc de concatener les 2 ++ mettre dans le ret le reste
		// vider next line ++ mettre dans la static next line ce qui se passe apres le \n sans l inclure
	} 
	//free ??
	
	return (buffer);
}

int    main (int ac, char **av)
{
    int     fd;
    char    *line;

    fd = open(*(++ av), O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free (line);
    }
	return 0;
}