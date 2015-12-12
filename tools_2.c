/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 15:28:25 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 17:27:09 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**del_argv_check(t_options *options, char **argv, int i)
{
	options->del_argv = 1;
	argv = del_one_argv(argv, i);
	options->nb_arg_real = options->nb_arg_real - 1;
	if (options->nb_arg_real == 0)
		exit(0);
	return (argv);
}

void	check_argv_3(t_list *list, char **argv, t_options *options, int i)
{
	t_check	*check;

	check = init_check();
	list = init_list();
	list->infos = ft_long_format(argv[i], argv[i], options);
	check = init_check();
	check = creat_check(list);
	ft_print_l_3(list, check, options);
}

int		nbr_len_long(unsigned int i)
{
	int				cmp;
	unsigned int	nb;

	nb = i;
	cmp = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		cmp++;
	}
	return (cmp + 1);
}

void	change_color(t_list *list)
{
	if (list->infos->type == 'c')
		ft_putstr("\033[0;34m");
	if (list->infos->type == 'p')
		ft_putstr("\033[0;38m");
	if (list->infos->type == '-')
		ft_putstr("\033[0;32m");
	if (list->infos->type == 'd')
		ft_putstr("\033[0;36m");
	if (list->infos->type == 'l')
		ft_putstr("\033[0;35m");
	if (list->infos->type == 'b')
		ft_putstr("\033[0;31m");
	if (list->infos->type == 's')
		ft_putstr("\033[0;30m");
}

char	**del_one_argv(char **argv, int i)
{
	char	**finish;
	int		y;

	y = 0;
	while (argv[y])
		y++;
	finish = (char **)malloc(sizeof(char *) * (y));
	y = 0;
	while (y < i)
	{
		finish[y] = ft_strdup(argv[y]);
		y++;
	}
	i++;
	while (argv[i])
	{
		finish[y] = ft_strdup(argv[i]);
		y++;
		i++;
	}
	finish[y] = NULL;
	return (finish);
}
