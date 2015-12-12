/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 12:24:59 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/21 15:38:14 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_infos(t_infos *infos)
{
	free(infos->name);
	free(infos->right);
	free(infos->link);
	free(infos->user_name);
	free(infos->group_name);
	free(infos->date);
	free(infos->lien_symb);
	free(infos);
}

void	free_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free_infos(list->infos);
		free(list->next);
		free(list->prev);
		free(list->path);
		free(list);
		list = next;
	}
}

void	free_options(t_options *options)
{
	free(options->username);
	free(options);
}
