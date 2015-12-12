/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 12:49:13 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/22 15:46:43 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_long_format_2(t_infos *infos, struct stat buff)
{
	infos->user_name = ft_strdup(get_user_id(buff.st_uid));
	infos->group_name = ft_strdup(get_grp_id(buff.st_gid));
	infos->nb_link = get_nb_link(buff.st_nlink);
	infos->date = ft_strdup(get_date(buff.st_mtime));
	infos->nb_block = get_nb_blocks(buff.st_blocks);
	infos->minor = get_minor(buff.st_rdev);
	infos->major = get_major(buff.st_rdev);
}

t_infos		*ft_long_format(char *path, char *name, t_options *options)
{
	t_infos			*infos;
	struct stat		buff;

	infos = init_infos();
	if (lstat(path, &buff) == -1)
		return (NULL);
	infos->name = ft_strdup(name);
	infos->type = get_type(buff.st_mode);
	infos->epoch_time = get_epoch_time(buff.st_mtime);
	infos->nb_bytes = get_bytes(buff.st_size);
	infos->right = ft_strdup(get_right(buff.st_mode));
	if (options->l == 1 || options->o == 1)
	{
		ft_long_format_2(infos, buff);
		if (infos->type == 'l')
			infos->link = ft_strdup(get_link(path));
		infos->xattr = get_attr(path);
	}
	return (infos);
}
