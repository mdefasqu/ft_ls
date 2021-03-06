/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:23:48 by mdefasqu          #+#    #+#             */
/*   Updated: 2014/11/17 12:01:03 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	a;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s2) + ft_strlen(s1);
	dst = (char *)malloc(sizeof(char *) * (a + 1));
	if (dst == NULL)
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		dst[a] = s1[a];
		a++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		dst[a] = s2[i];
		a++;
		i++;
	}
	dst[a] = '\0';
	return (dst);
}
