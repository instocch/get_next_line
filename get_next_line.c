/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstocche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:30:38 by mstocche          #+#    #+#             */
/*   Updated: 2023/04/13 16:50:14 by mstocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
	line = ft_calloc((ft_strlen(buffer)) - i + 1, sizeof(char));
    i++;
	j = 0;
	while (buffer[i] != '\0')
		line[j++] = buffer[i++];
	line[j] = '\0';
	free (buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof (char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	int		read_bytes;
	char	*line;

	line = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	read_bytes = 1;
	while (!ft_strchr(buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{	
			free (line);
			return (buffer);
		}
		line[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, line);
		//if (ft_strchr(line, '\n'))
			//break ;
	}
    free (line);
	if (buffer[0] == '\0')
    {
        free (buffer);
        return (0);
    }
	return (buffer);
}

char	*get_next_line(int fd)
{
	char static	*buffer;
	char	    *line;
    
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
        return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
