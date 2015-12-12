/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 16:25:21 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/22 17:00:34 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_wr_maj(t_options *options, t_list *list,
				t_list *list_parent, int i)
{
	t_list *head;
	t_list *list_r;

	head = list;
	list = sort_list(list, options);
	ft_print_permission(list_parent);
	ft_print_on_wr_maj(list, options);
	list = head;
	while (list != NULL)
	{
		if (list->infos->type == 'd' && ft_strcmp(list->infos->name, ".") != 0
			&& ft_strcmp(list->infos->name, "..") != 0)
		{
			ft_putchar('\n');
			list_r = read_directory(list->path, options, i);
			ft_print_wr_maj(options, list_r, list, i);
			list = list->next;
		}
		else
			list = list->next;
	}
	free_list(list);
	list_parent = list_parent->next;
}

void		ft_print_no_l_r(t_options *options, t_list *list, char *name, int i)
{
	list = sort_list(list, options);
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
	if (i - options->nb_flag < options->nb_arg_real)
		ft_putchar('\n');
	(void)name;
}

void		ft_print_l_3(t_list *list, t_check *check, t_options *options)
{
	ft_print_l4(list, check, options);
	ft_putstr(" ");
	ft_putstr(list->infos->date);
	ft_putstr(" ");
	ft_putstr(list->infos->name);
	if (options->p == 1 && list->infos->type == 'd')
		ft_putchar('/');
	if (list->infos->link != NULL)
	{
		ft_putstr(" -> ");
		ft_putstr(list->infos->link);
	}
	ft_putchar('\n');
}

void		ft_print_l2(t_list *list, t_options *options)
{
	t_check		*check;

	check = creat_check(list);
	if (list != NULL)
	{
		ft_putstr("total ");
		ft_putnbr(check->nb_block);
		ft_putchar('\n');
	}
	while (list != NULL)
	{
		ft_print_l_3(list, check, options);
		list = list->next;
	}
}

void		ft_print_l(t_options *options, t_list *list, char *name, int i)
{
	list = sort_list(list, options);
	ft_print_l2(list, options);
	if (i - options->nb_flag < options->nb_arg_real)
	{
		ft_putchar('\n');
	}
	(void)name;
}
