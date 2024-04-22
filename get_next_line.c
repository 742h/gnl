/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:38:29 by hassaleh          #+#    #+#             */
/*   Updated: 2024/04/22 09:51:18 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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
		return(0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(saved) - i + 1));
	if (!str)
		return(0);
	i++;
	j = 0;
	while (saved[i])
		str[j++] = saved[i++];
	str[j] = '\0';
	free(saved);
	return(str);
}
char	*ft_extract(char *saved)
{
	int	i;
	char *str;

	i = 0;
	if (!saved[i])
		return(0);
	while (saved[i] && saved[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return(0);
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
	return(str);
}
char	*ft_rightnow(int fd, char *result)
{
	char	*buffer;
	int	bytes;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return(0);
	bytes = 1;
	while (!ft_strchr(result, '\n') && bytes != 0)
	{
 		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return(0);
		}
		buffer[bytes] = '\0';
		result = ft_strjoin(result, buffer);
	}
	free(buffer);
	return(result);
}

char	*get_next_line(int fd)
{
	char		*line;
	char static	*result;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return(0);
	result = ft_rightnow(fd, result);
	if (!result)
		return(0);
	line = ft_extract(result);
	result = ft_remains(result);
	return(line);
}

// int main()
// {
// 	int fd = open("test1.txt", O_RDONLY);
// 	while (1) {
// 		char *line = get_next_line(fd);
// 		if (!line)
// 			break;
// 		printf("%s", line);
// 		free(line);
// 	}
// }
