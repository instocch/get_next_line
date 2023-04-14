/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstocche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:01:44 by mstocche          #+#    #+#             */
/*   Updated: 2023/04/13 16:56:55 by mstocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char    *ft_strchr(char *s, int c)
{
    int    i;

    i = 0;
    if (!s)
        return (0);
    while (s[i] != '\0')
    {
        if (s[i] == (char) c)
            return ((char *)(s + i));
        i++;
    }
    if (c == '\0')
        return ((char *)(s + i));
    return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buffer;

    if (s1 == 0)
    {
        s1 = (char *)malloc(1 * sizeof(char));
        s1[0] = '\0';
    }
	if (!s1 || !s2)
		return (NULL);
	buffer = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buffer)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		buffer[i] = s1[i];
	while (s2[j] != '\0')
		buffer[i++] = s2[j++];
	buffer[i] = 0;
    free(s1);
	return (buffer);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
    
    if (!count || !size)
        return (0);
	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	buffer = malloc(size * count);
	if (!buffer)
		return (NULL);
	ft_bzero (buffer, size * count);
	return (buffer);
}
