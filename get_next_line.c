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

    if (buffer[0] == '\0')
    {
        free(buffer);
        return (NULL);
    }
    i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!line)
		return (NULL);
    if (buffer[i] != '\0')
        i++;
	j = 0;
	while (buffer[i] != '\0')
		line[j++] = buffer[i++];
	line[j] = '\0';
    free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
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

char	*ft_read(int fd, char *line)
{
	int		read_bytes;
	char *buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer) return NULL;
    buffer[0] = '\0';
	read_bytes = 1;
	while (!in_str(buffer, '\n') && (read_bytes = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		if (read_bytes == -1)
		{
            line[0] = '\0';
            free(buffer);
			return (line);
		}
        buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
    free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char *line;
    char *result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    if (!line)
    {
        line = (char *)malloc(sizeof(char *) * 1);
        if (!line)
            return (NULL);
        line[0] = '\0';
    }
	line = ft_read(fd, line);
	result = ft_line(line);
	line = ft_next(line);
	return (result);
}
/*
int main()
{
    get_next_line(999999);
}
*/

/*
int main()
{
    int fd;
    fd = open("./gnlTester/files/big_line_no_nl", O_RDONLY);
    char *stringa;
    stringa = get_next_line(fd);
    while (stringa){
        printf("%s", stringa);
        free(stringa);
        stringa = get_next_line(fd);
    }
    stringa = get_next_line(fd);
    if (stringa == NULL) printf("NULLO\n");
    printf("%s", stringa);
    stringa = get_next_line(fd);
    if (stringa == NULL) printf("NULLO\n");
    printf("%s", stringa);
        //free(stringa);

	return (0);
}
*/
