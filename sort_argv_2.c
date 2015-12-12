/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_argv_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 12:34:37 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/24 12:34:38 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_str(char **s1, char **s2, char **s3)
{
	*s3 = ft_strdup(*s1);
	*s1 = ft_strdup(*s2);
	*s2 = ft_strdup(*s3);
}

int		type_cmp(char c)
{
	if (c == '-')
		return (0);
	else if (c == 'l')
		return (0);
	else if (c == 'd')
		return (1);
	return (-1);
}

void	sort_by_int_error(int i, char **finish_argv, t_options *options)
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
			if (infos2 == NULL)
			{
				if (ft_strcmp(finish_argv[i], finish_argv[y]) > 0)
					swap_str(&finish_argv[i], &finish_argv[y], &tmp);
			}
			y++;
		}
		i++;
	}
}

void	sort_by_int_rev(int i, char **finish_argv, t_options *options)
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
				if (ft_strcmp(finish_argv[i], finish_argv[y]) < 0
					&& type_cmp(infos->type) == type_cmp(infos2->type))
					swap_str(&finish_argv[i], &finish_argv[y], &tmp);
			}
			y++;
		}
		i++;
	}
}
