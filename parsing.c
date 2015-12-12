/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 13:46:16 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 15:15:12 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		check_flag_all_2(char c, t_options *options)
{
	if (c == 'a')
		options->a = 1;
}

void		check_flag_all(char c, t_options *options)
{
	check_flag_all_2(c, options);
	if (c == 'l')
		options->l = 1;
	else if (c == 'r')
		options->r = 1;
	else if (c == 'R')
		options->r_maj = 1;
	else if (c == 't')
		options->t = 1;
	else if (c == '1' && options->l == 1)
		options->l = 0;
	else if (c == 'S')
		options->s_maj = 1;
	else if (c == 'o')
		options->o = 1;
	else if (c == 'p')
		options->p = 1;
	else if (c == 'G')
		options->g = 1;
	else if (c == '1' && options->o == 1)
		options->o = 0;
	else if (c == '1' || (c == 'a' && options->a == 1))
		options->a = options->a;
	else
		ft_parse_error(c);
}

void		read_flag_base(char *argument, t_options *options)
{
	int i;

	i = 1;
	while (argument[i])
	{
		check_flag_all(argument[i], options);
		i++;
	}
}

int			read_argv(char *argument, t_options *options)
{
	if (argument[0] == '-' && argument[1] != '\0' && argument[1] != '-')
	{
		read_flag_base(argument, options);
		return (1);
	}
	return (0);
}

char		**parsing(t_options *options, char **argv, int argc)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (read_argv(argv[i], options) == 0)
		{
			if (argv[i][0] == '-' && argv[i][1] == '-')
			{
				if (argv[i][2])
					ft_parse_error('-');
				argv = del_one_argv(argv, i);
				argc--;
			}
			break ;
		}
		i++;
	}
	options->nb_flag = i - 1;
	while (argv[i])
		i++;
	options->nb_arg_real = argc - options->nb_flag;
	return (argv);
}
