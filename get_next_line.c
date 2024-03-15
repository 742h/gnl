/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:38:29 by hassaleh          #+#    #+#             */
/*   Updated: 2024/03/16 02:35:16 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_rightnow(char *result, char *buffer)
{
	char	*joined;

	if (!result)
	{
		result = strdup(buffer);
		return (result);
	}
	else
	{
		joined = ft_strjoin(result, buffer);
		return (joined);
	}
}

char	*get_next_line(int fd)
{
	ssize_t		bytes;
	char		*buffer;
	char static	*result;

	bytes = 1;
	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			result = ft_rightnow(result, buffer);
		}
		else if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			break ;
		ft_bzero(buffer, bytes);
	}
	free (buffer);
	return (result);
}

int main()
{
	int fd = open("test1.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
}
