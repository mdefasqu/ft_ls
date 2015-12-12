/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 16:40:50 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 15:17:37 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_l6(t_list *list, t_check *check)
{
	ft_putchar(' ');
	print_blank_int(nbr_len(list->infos->major), check->max_major, 1);
	ft_putnbr(list->infos->major);
	ft_putchar(',');
}

void		ft_print_l5(t_list *list, t_check *check)
{
	if (list->infos->type != 'c' && list->infos->type != 'b')
	{
		if (check->if_device > 0)
		{
			ft_putstr("  ");
			print_blank_int(0, check->max_major, 1);
			print_blank_int_2(nbr_len_long(list->infos->nb_bytes),
				check->max_minor, 'Q', 1);
			ft_putnbr_long(list->infos->nb_bytes);
		}
		else
		{
			print_blank_int(nbr_len_long(list->infos->nb_bytes),
				check->t_nb_byte, 1);
			ft_putnbr_long(list->infos->nb_bytes);
		}
	}
	else
	{
		ft_print_l6(list, check);
		print_blank_int_2(nbr_len(list->infos->minor),
			check->max_minor, 'Q', 1);
		ft_putnbr(list->infos->minor);
	}
}

void		ft_print_l4(t_list *list, t_check *check, t_options *options)
{
	if (options->g == 1)
		change_color(list);
	ft_putchar(list->infos->type);
	ft_putstr(list->infos->right);
	if (list->infos->xattr)
		ft_putchar(list->infos->xattr);
	print_blank_int_2(nbr_len(list->infos->nb_link), check->t_nb_link,
		list->infos->xattr, check->if_xattr);
	ft_putnbr(list->infos->nb_link);
	ft_putstr(" ");
	ft_putstr(list->infos->user_name);
	print_blank_char(ft_strlen(list->infos->user_name), check->t_user_name);
	if (options->o != 1)
	{
		ft_putstr(list->infos->group_name);
		print_blank_char(ft_strlen(list->infos->group_name),
			check->t_group_name);
	}
	ft_print_l5(list, check);
}

void		ft_print_permission(t_list *list_parent)
{
	if (list_parent->infos->right[2] != 'x' &&
		list_parent->infos->right[0] == 'r' && list_parent->infos->type == 'd')
	{
		ft_putstr_fd("./ft_ls: ", 2);
		ft_putstr_fd(get_final_path(list_parent->path), 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
}

void		ft_print_on_wr_maj(t_list *list, t_options *options)
{
	if (options->l == 0)
	{
		while (list != NULL)
		{
			if (options->g == 1)
				change_color(list);
			ft_putstr(list->infos->name);
			if (options->p == 1 && list->infos->type == 'd')
				ft_putchar('/');
			ft_putchar('\n');
			list = list->next;
		}
	}
	else
		ft_print_l2(list, options);
}
