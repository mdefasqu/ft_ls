/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 13:26:26 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 13:04:43 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*init_list(void)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	list->infos = NULL;
	list->next = NULL;
	list->prev = NULL;
	list->path = NULL;
	list->error = 0;
	return (list);
}

t_options	*init_option(void)
{
	t_options *options;

	options = (t_options *)malloc(sizeof(t_options));
	options->a = 0;
	options->l = 0;
	options->r = 0;
	options->t = 0;
	options->o = 0;
	options->g = 0;
	options->p = 0;
	options->s_maj = 0;
	options->r_maj = 0;
	options->nb_arg_real = 0;
	options->nb_flag = 0;
	options->username = NULL;
	options->finish_argv = NULL;
	options->del_argv = 0;
	return (options);
}

t_infos		*init_infos(void)
{
	t_infos *infos;

	infos = (t_infos *)malloc(sizeof(t_infos));
	infos->name = NULL;
	infos->right = NULL;
	infos->nb_link = 0;
	infos->link = NULL;
	infos->user_name = NULL;
	infos->group_name = NULL;
	infos->nb_bytes = 0;
	infos->epoch_time = 0;
	infos->date = NULL;
	infos->lien_symb = NULL;
	infos->type = '0';
	infos->minor = 0;
	infos->major = 0;
	return (infos);
}

t_check		*init_check(void)
{
	t_check *check;

	check = (t_check *)malloc(sizeof(t_check));
	check->t_nb_link = 0;
	check->t_user_name = 0;
	check->t_group_name = 0;
	check->t_nb_byte = 0;
	check->if_xattr = 0;
	check->nb_block = 0;
	check->max_minor = 0;
	check->max_minor = 0;
	check->if_device = 0;
	return (check);
}
