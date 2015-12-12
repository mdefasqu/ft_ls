/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 16:47:07 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/24 16:47:08 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_argv(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

t_list	*get_info_list(t_list *list, char *str, t_options *options)
{
	list = init_list();
	list->infos = ft_long_format(str, str, options);
	return (list);
}

void	only_print_l_3(t_list *list, t_options *options)
{
	t_check	*check;

	check = init_check();
	check = creat_check(list);
	ft_print_l_3(list, check, options);
}

char	**perror_check_argv(char **argv, int i, t_options *options)
{
	char *error;

	error = ft_strjoin("./ft_ls: ", get_final_path(argv[i]));
	perror(error);
	free(error);
	argv = del_argv_check(options, argv, i);
	return (argv);
}

char	**fu_25_lign(char **argv, t_options *options, int i, t_list *list)
{
	if (options->l == 1)
		only_print_l_3(list, options);
	else
		print_argv(argv[i]);
	argv = del_argv_check(options, argv, i);
	return (argv);
}
