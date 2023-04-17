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

#include <stdio.h>

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
    if (!buffer[i])
        return (NULL);
	line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!line)
		return (NULL);
    i++;
	j = 0;
	while (buffer[i] != '\0')
		line[j++] = buffer[i++];
	line[j] = '\0';
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
	line = (char *)malloc(i + 2);
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

	line = (char *)malloc(BUFFER_SIZE + 1);
	read_bytes = 1;
	line = ft_strjoin(line, buffer);
	while (!ft_strchr(buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{	
			free (line);
			return (buffer);
		}
		line[ft_strlen(line)] = '\0';
		line = ft_strjoin(line, buffer);
	// printf("!!!!!!!%s\n\n", buffer);
	}
	if (line[0] == '\0')
        return (0);
	return (line);
}



char	*get_next_line(int fd)
{
	char static	buffer[BUFFER_SIZE];
	char	    *line;
	char		*ptr;
    
	ptr = buffer;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = ft_read(fd, ptr);

	if (!ptr)
        return (NULL);
	line = ft_line(ptr);
	ptr = ft_next(ptr);
	int i = 0;
	while (ptr[i])
	{
		buffer[i] = ptr[i];
		i++;
	}
	buffer[i] = '\0';
	return (line);
}


int main()
{
	int fd;
	fd = open("./test1", 0);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}