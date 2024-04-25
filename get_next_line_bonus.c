/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:21:56 by hassaleh          #+#    #+#             */
/*   Updated: 2024/04/23 19:32:59 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_remains(char *saved)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] != '\n' || (saved[i] == '\n' && !saved[i + 1]))
	{
		free(saved);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(saved) - i + 1));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (saved[i])
		str[j++] = saved[i++];
	free(saved);
	str[j] = '\0';
	return (str);
}

char	*ft_extract(char *saved)
{
	int		i;
	char	*str;

	i = 0;
	if (!saved[i])
		return (0);
	while (saved[i] && saved[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		str[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		str[i] = saved[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_rightnow(int fd, char *result)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (0);
	bytes = 1;
	while (!ft_strchr(result, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(result);
			free(buffer);
			return (0);
		}
		buffer[bytes] = '\0';
		result = ft_strjoin(result, buffer);
		if (!result)
			return (NULL);
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	char static	*result[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX || BUFFER_SIZE > INT_MAX)
		return (0);
	result[fd] = ft_rightnow(fd, result[fd]);
	if (!result[fd])
		return (0);
	line = ft_extract(result[fd]);
	result[fd] = ft_remains(result[fd]);
	return (line);
}
