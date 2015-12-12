/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 13:29:24 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/22 17:07:16 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**add_argv(t_options *options, int i)
{
	char	**finish;
	int		y;

	y = 0;
	finish = (char **)malloc(sizeof(char *) * (i + 2));
	while (options->finish_argv[y])
	{
		finish[y] = ft_strdup(options->finish_argv[y]);
		y++;
	}
	finish[y] = ft_strdup(".");
	finish[y + 1] = NULL;
	return (finish);
}

t_list	*sort_list(t_list *list, t_options *options)
{
	if (options->t == 0 && options->s_maj == 0)
		sort_by_order_name(&list);
	if (options->t == 1 && options->s_maj == 0)
		sort_by_date(&list);
	if (options->s_maj == 1)
		sort_by_taille(&list);
	if (options->r == 1)
		sort_rev(&list);
	return (list);
}

void	ft_putnbr_long(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_long(n / 10);
		ft_putnbr_long(n % 10);
	}
	else
		ft_putchar(n + 48);
}

char	*getusername(char **env)
{
	int		i;
	int		y;
	int		x;
	char	*ret;

	i = 0;
	x = 0;
	y = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "USER=", 5) == 0)
			break ;
		else
			i++;
	}
	y = ft_strlen(env[i]);
	ret = (char *)malloc(sizeof(char) * (y - 4));
	while (x < y - 4)
	{
		ret[x] = env[i][x + 5];
		x++;
	}
	ret[x] = '\0';
	return (ret);
}

char	*get_final_path(char *str)
{
	char	*finish;
	int		i;
	int		y;

	if (str == NULL)
		return (NULL);
	i = 0;
	y = 0;
	i = ft_strlen(str);
	while (str[i] != '/' && i > 0)
		i--;
	finish = (char *)malloc(sizeof(char) * ((ft_strlen(str) - i) + 2));
	while (str[i])
	{
		finish[y] = str[i];
		i++;
		y++;
	}
	finish[y] = '\0';
	return (finish);
}
