/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 14:45:57 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 18:11:38 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**check_argv_2(char **argv, t_options *options)
{
	int		i;
	DIR		*current_dir;
	t_list	*list;

	list = NULL;
	i = options->nb_flag + 1;
	while (argv[i])
	{
		current_dir = opendir(argv[i]);
		if (current_dir == NULL)
		{
			if (options->l == 1)
				check_argv_3(list, argv, options, i);
			else
				print_argv(argv[i]);
			argv = del_argv_check(options, argv, i);
		}
		else
			i = close_dir_lol(i, current_dir);
	}
	return (argv);
}

char		**check_argv(char **argv, t_options *options)
{
	int		i;
	DIR		*current_dir;
	t_list	*list;

	list = NULL;
	i = options->nb_flag + 1;
	while (argv[i])
	{
		current_dir = opendir(argv[i]);
		if (current_dir == NULL)
		{
			list = get_info_list(list, argv[i], options);
			if (list->infos != NULL && errno != 20 && errno != 13)
				argv = fu_25_lign(argv, options, i, list);
			if ((errno != 20 && list->infos == NULL) || errno == 13)
				argv = perror_check_argv(argv, i, options);
			else
				i++;
		}
		else
			i = close_dir_lol(i, current_dir);
	}
	check_argv_2(argv, options);
	return (argv);
}

void		display(t_options *options, t_list *list, char **argv)
{
	int		i;

	i = options->nb_flag + 1;
	options->finish_argv = sort_argv(i, argv, options);
	options->finish_argv = check_argv(options->finish_argv, options);
	if (options->nb_arg_real == 0)
		options->finish_argv = add_argv(options, i);
	while (options->finish_argv[i])
	{
		list = read_directory(options->finish_argv[i], options, i);
		if ((options->l == 1 || options->o == 1) && options->r_maj == 0
			&& list != NULL)
			ft_print_l(options, list, options->finish_argv[i], i);
		else if (options->r_maj == 1 && list != NULL)
			ft_print_wr_maj(options, list, list, i);
		else if (list != NULL && options->r_maj == 0 && options->l == 0)
			ft_print_no_l_r(options, list, options->finish_argv[i], i);
		i++;
	}
}

t_list		*hard_display(t_options *options, char **argv)
{
	t_list	*list;

	list = init_list();
	display(options, list, argv);
	return (list);
}
