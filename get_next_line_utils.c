/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:19:19 by hassaleh          #+#    #+#             */
/*   Updated: 2024/04/22 09:51:07 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	int				i;
	int				k;
	char			*str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	k = 0;
	str = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
		str[k++] = s1[i++];
	free(s1);
	i = 0;
	while (s2[i])
		str[k++] = s2[i++];
	str[k] = '\0';
	return (str);
}

char	*ft_strdup(const char *src)
{
	int				i;
	int				j;
	char			*dest;
	unsigned char	*s1;

	s1 = (unsigned char *) src;
	j = 0;
	i = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * i +1);
	if (!(dest))
		return (0);
	while (s1[j] != '\0')
	{
		dest[j] = s1[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int a)
{
	if (!str)
		return(0);
	if (a == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (*str)
	{
		if (*str == (char)a)
			return ((char *)str);
		str++;
	}
	return (0);
}