/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:19:19 by hassaleh          #+#    #+#             */
/*   Updated: 2024/03/16 02:00:07 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	ptr = (void *) malloc (count * size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero (ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*j;
	size_t			i;

	j = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		j[i] = 0;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				k;
	char			*str;

	if (!s1 && !s1)
		return (NULL);
	else if (!s1)
		return (strdup(s2));
	else if (!s2)
		return (strdup(s1));
	k = 0;
	str = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
		str[k++] = s1[i++];
	i = 0;
	while (s2[i])
		str[k++] = s2[i++];
	str[k] = '\0';
	return (str);
}
