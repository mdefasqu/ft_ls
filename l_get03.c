/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_get03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 12:48:59 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 16:16:41 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_link(char *path)
{
	char		*buff;
	ssize_t		n;

	buff = (char*)malloc(sizeof(char) * 1024);
	ft_memset(buff, 0, sizeof(buff));
	if ((n = readlink(path, buff, 1024)) < 0)
		return (NULL);
	else
	{
		buff[n] = '\0';
		return (buff);
	}
}

int			get_nb_blocks(blkcnt_t buff)
{
	return (buff);
}

char		get_attr(char *path)
{
	char		buff[256];

	if (listxattr(path, buff, 256, XATTR_NOFOLLOW) > 0)
		return ('@');
	else if (acl_get_file(path, ACL_TYPE_EXTENDED))
		return ('+');
	return ('\0');
}
