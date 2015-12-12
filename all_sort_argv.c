/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_sort_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 14:13:19 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 18:11:49 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_int_taille(int i, char **finish_argv, t_options *options)
{
	char	*tmp;
	int		y;
	t_infos	*infos;
	t_infos	*infos2;

	tmp = NULL;
	while (finish_argv[i])
	{
		y = i + 1;
		while (finish_argv[y])
		{
			infos = ft_long_format(finish_argv[i], finish_argv[i], options);
			infos2 = ft_long_format(finish_argv[y], finish_argv[y], options);
			if (infos != NULL && infos2 != NULL)
			{
				if (infos->nb_bytes < infos2->nb_bytes &&
					type_cmp(infos->type) == type_cmp(infos2->type))
					swap_str(&finish_argv[i], &finish_argv[y], &tmp);
			}
			y++;
		}
		i++;
	}
}

void	sort_by_int_time(int i, char **finish_argv, t_options *options)
{
	char	*tmp;
	int		y;
	t_infos	*infos;
	t_infos	*infos2;

	tmp = NULL;
	while (finish_argv[i])
	{
		y = i + 1;
		while (finish_argv[y])
		{
			infos = ft_long_format(finish_argv[i], finish_argv[i], options);
			infos2 = ft_long_format(finish_argv[y], finish_argv[y], options);
			if (infos != NULL && infos2 != NULL)
			{
				if (infos->epoch_time < infos2->epoch_time &&
					type_cmp(infos->type) == type_cmp(infos2->type))
					swap_str(&finish_argv[i], &finish_argv[y], &tmp);
			}
			y++;
		}
		i++;
	}
}

void	sort_by_int(int i, char **finish_argv, t_options *options)
{
	char	*tmp;
	int		y;
	t_infos	*infos;
	t_infos	*infos2;

	if (finish_argv == NULL)
		return ;
	tmp = NULL;
	while (finish_argv[i])
	{
		y = i + 1;
		while (finish_argv[y])
		{
			infos = ft_long_format(finish_argv[i], finish_argv[i], options);
			infos2 = ft_long_format(finish_argv[y], finish_argv[y], options);
			if (infos != NULL && infos2 != NULL)
			{
				if (ft_strcmp(finish_argv[i], finish_argv[y]) > 0
					&& type_cmp(infos->type) == type_cmp(infos2->type))
					swap_str(&finish_argv[i], &finish_argv[y], &tmp);
			}
			y++;
		}
		i++;
	}
}

void	sort_by_type(int i, char **finish_argv, t_options *options)
{
	char	*tmp;
	int		y;
	t_infos	*infos;
	t_infos	*infos2;

	if (finish_argv == NULL)
		return ;
	tmp = NULL;
	while (finish_argv[i])
	{
		y = i + 1;
		while (finish_argv[y])
		{
			infos = ft_long_format(finish_argv[i], finish_argv[i], options);
			infos2 = ft_long_format(finish_argv[y], finish_argv[y], options);
			if (infos != NULL && infos2 != NULL)
			{
				if (infos->type == 'd' && (infos2->type == '-' ||
					infos2->type == 'l'))
					swap_str(&finish_argv[i], &finish_argv[y], &tmp);
			}
			y++;
		}
		i++;
	}
}

char	**sort_argv(int i, char **argv, t_options *options)
{
	char	**finish_argv;
	int		y;

	y = 0;
	finish_argv = (char **)malloc(sizeof(char *) *
		(options->nb_flag + options->nb_arg_real + 2));
	while (argv[y])
	{
		finish_argv[y] = ft_strdup(argv[y]);
		y++;
	}
	finish_argv[y] = NULL;
	sort_by_int_error(i, finish_argv, options);
	sort_by_type(i, finish_argv, options);
	sort_by_int(i, finish_argv, options);
	if (options->t == 1 && options->s_maj == 0 && finish_argv != NULL)
		sort_by_int_time(i, finish_argv, options);
	if (options->s_maj == 1 && finish_argv != NULL)
		sort_by_int_taille(i, finish_argv, options);
	if (options->r == 1 && finish_argv != NULL)
		sort_by_int_rev(i, finish_argv, options);
	return (finish_argv);
}
