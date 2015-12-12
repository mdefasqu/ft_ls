/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 13:02:20 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 14:23:30 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv, char **env)
{
	t_options		*options;

	options = init_option();
	options->username = getusername(env);
	argv = parsing(options, argv, (argc - 1));
	hard_display(options, argv);
	free_options(options);
	return (0);
}
