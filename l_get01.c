/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_get01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 12:48:48 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 12:38:38 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_right(mode_t buff)
{
	char	*right;

	right = (char*)malloc(sizeof(*right) * 10);
	right[9] = '\0';
	right[0] = (buff & S_IRUSR) ? 'r' : '-';
	right[1] = (buff & S_IWUSR) ? 'w' : '-';
	right[2] = geturight(buff);
	right[5] = getgright(buff);
	right[3] = (buff & S_IRGRP) ? 'r' : '-';
	right[4] = (buff & S_IWGRP) ? 'w' : '-';
	right[6] = (buff & S_IROTH) ? 'r' : '-';
	right[7] = (buff & S_IWOTH) ? 'w' : '-';
	right[8] = getoright(buff);
	return (right);
}

char		get_type(mode_t buff)
{
	char	c;

	c = '0';
	if (S_ISDIR(buff))
		c = 'd';
	else if (S_ISFIFO(buff))
		c = 'p';
	else if (S_ISCHR(buff))
		c = 'c';
	else if (S_IFLNK & buff)
	{
		if (S_ISREG(buff))
			c = '-';
		else if (S_ISBLK(buff))
			c = 'b';
		else if (S_ISSOCK(buff))
			c = 's';
		else
			c = 'l';
	}
	return (c);
}

char		*get_user_id(uid_t buff)
{
	struct passwd *pwd;

	if ((pwd = getpwuid(buff)) != NULL)
		return (pwd->pw_name);
	else
		return (ft_itoa(buff));
}

char		*get_grp_id(gid_t buff)
{
	struct group *grp;

	if ((grp = getgrgid(buff)) != NULL)
		return (grp->gr_name);
	else
		return (ft_itoa(buff));
}
