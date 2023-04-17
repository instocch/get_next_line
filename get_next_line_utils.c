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
#include <stdio.h>

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

	if (!s1 || !s2)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		buffer[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		buffer[j++] = s2[i];
		i++;
	}
	buffer[j] = '\0';
	free(s1);
	return (buffer);
}
