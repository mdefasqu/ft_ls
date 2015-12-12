/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 13:44:08 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 14:46:22 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		read_directory_2(t_options *options, char *path, int i)
{
	if (options->finish_argv[i] != NULL)
	{
		if ((ft_strcmp(options->finish_argv[i], path) != 0
			&& options->r_maj == 1) || (options->del_argv > 0 &&
				options->nb_arg_real == 1) || options->nb_arg_real > 1)
		{
			ft_putstr(path);
			ft_putstr(":\n");
		}
		else if (ft_strcmp(options->finish_argv[i], path) == 0
			&& options->r_maj == 0 && options->nb_arg_real > 1)
		{
			ft_putstr(path);
			ft_putstr(":\n");
		}
	}
}

void		add_to_list(t_list *list, t_list **prev, t_list **head)
{
	if (list->infos != NULL)
	{
		if (*prev == NULL)
		{
			*prev = list;
			*head = list;
		}
		else
		{
			list->prev = *prev;
			(*prev)->next = list;
			*prev = list;
		}
	}
	else
	{
		ft_putstr("./ft_ls: ");
		ft_putstr(get_final_path(list->path));
		ft_putstr(": Premission denied\n");
	}
}

t_list		*read_all_file(t_options *options, DIR *current_dir, char *path)
{
	struct dirent	*read_dir;
	t_list			*list;
	t_list			*prev;
	t_list			*head;

	prev = NULL;
	head = NULL;
	while ((read_dir = readdir(current_dir)) != NULL)
	{
		if ((read_dir->d_name[0] == '.' && options->a == 1) ||
			read_dir->d_name[0] != '.')
		{
			list = init_list();
			list->infos = ft_long_format(ft_strjoin_path(path,
				read_dir->d_name), read_dir->d_name, options);
			list->path = ft_strjoin_path(path, read_dir->d_name);
			add_to_list(list, &prev, &head);
		}
	}
	return (head);
}

t_list		*read_directory(char *path, t_options *options, int i)
{
	DIR		*current_dir;
	t_list	*list;
	char	*error;

	current_dir = opendir(path);
	if (options->g == 1)
		ft_putstr("\033[0;33m");
	read_directory_2(options, path, i);
	if (current_dir == NULL)
	{
		error = ft_strjoin("./ft_ls: ", get_final_path(path));
		perror(error);
		free(error);
		return (NULL);
	}
	list = read_all_file(options, current_dir, path);
	if (closedir(current_dir) == -1)
	{
		ft_putstr(path);
		ft_putstr("\nCas non gere qui se realisera un jour ?\n");
		exit(0);
	}
	return (list);
}
