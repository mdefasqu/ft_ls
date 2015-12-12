/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_get02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 12:48:54 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 13:06:51 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_bytes(off_t buff)
{
	return (buff);
}

int		get_nb_link(nlink_t buff)
{
	return (buff);
}

time_t	get_epoch_time(time_t buff)
{
	return (buff);
}

char	*ft_ls_trim(char *str, int start, int end)
{
	char	*ret;
	int		i;

	i = 0;
	if (start < 0 || (end - start) < 0)
		return (NULL);
	if (end > (int)ft_strlen(str))
		end = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (end - start) + 1);
	while (start <= end)
	{
		ret[i] = str[start];
		start++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_date(time_t buff)
{
	char	*ret;
	char	*tmp;
	time_t	local;

	local = time(NULL);
	ret = ctime(&buff);
	if ((local - buff) > 15778463)
	{
		tmp = ft_ls_trim(ret, 4, 10);
		ret = ft_strjoin(tmp, ft_ls_trim(ret, 19, 23));
	}
	else
		ret = ft_ls_trim(ret, 4, 15);
	return (ret);
}
