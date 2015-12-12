/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blank.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 11:45:37 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 13:29:55 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			nbr_len(int i)
{
	int cmp;
	int nb;

	nb = i;
	cmp = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		cmp++;
	}
	return (cmp + 1);
}

void		print_blank_int_2(int i, int y, char c, int v)
{
	ft_putstr(" ");
	if (v == 1)
	{
		if (c == '\0')
			ft_putstr(" ");
	}
	else
		ft_putstr(" ");
	while (i < y)
	{
		ft_putstr(" ");
		i++;
	}
}

void		print_blank_int(int i, int y, int z)
{
	if (z == 0)
		ft_putstr("  ");
	while (i < y)
	{
		ft_putstr(" ");
		i++;
	}
}

void		print_blank_char(size_t i, size_t y)
{
	ft_putstr(" ");
	while (i <= y)
	{
		ft_putstr(" ");
		i++;
	}
}

t_check		*creat_check(t_list *list)
{
	t_check *check;

	check = init_check();
	while (list != NULL)
	{
		if (nbr_len(list->infos->nb_link) > check->t_nb_link)
			check->t_nb_link = nbr_len(list->infos->nb_link);
		if (ft_strlen(list->infos->user_name) > check->t_user_name)
			check->t_user_name = ft_strlen(list->infos->user_name);
		if (ft_strlen(list->infos->group_name) > check->t_group_name)
			check->t_group_name = ft_strlen(list->infos->group_name);
		if (nbr_len_long(list->infos->nb_bytes) > check->t_nb_byte)
			check->t_nb_byte = nbr_len_long(list->infos->nb_bytes);
		if (nbr_len(list->infos->major) > check->max_major)
			check->max_major = nbr_len(list->infos->major);
		if (nbr_len(list->infos->minor) > check->max_minor)
			check->max_minor = nbr_len(list->infos->minor);
		if (list->infos->xattr != '\0')
			check->if_xattr = 1;
		if (list->infos->type == 'b' || list->infos->type == 'c')
			check->if_device = 1;
		check->nb_block = check->nb_block + list->infos->nb_block;
		list = list->next;
	}
	return (check);
}
