/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 17:46:58 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/18 11:06:44 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swapi(t_list *tmp, t_list *tmp2)
{
	t_list	*tmp3;

	tmp3 = init_list();
	tmp3->infos = tmp2->infos;
	tmp2->infos = tmp->infos;
	tmp->infos = tmp3->infos;
	tmp3->path = tmp2->path;
	tmp2->path = tmp->path;
	tmp->path = tmp3->path;
}

void	sort_rev(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;
	int		y;

	if (*list == NULL)
		return ;
	i = 0;
	y = 0;
	tmp = *list;
	tmp2 = *list;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
		i++;
	}
	while (y <= i / 2)
	{
		swapi(tmp, tmp2);
		tmp = tmp->next;
		tmp2 = tmp2->prev;
		y++;
	}
}

void	sort_by_order_name(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*list == NULL)
		return ;
	tmp = *list;
	tmp2 = *list;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (ft_strcmp(tmp->infos->name, tmp2->infos->name) > 0)
			{
				swapi(tmp, tmp2);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	sort_by_taille(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*list == NULL)
		return ;
	tmp = *list;
	tmp2 = *list;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->infos->nb_bytes < tmp2->infos->nb_bytes)
			{
				swapi(tmp, tmp2);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	sort_by_date(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*list == NULL)
		return ;
	tmp = *list;
	tmp2 = *list;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->infos->epoch_time < tmp2->infos->epoch_time)
				swapi(tmp, tmp2);
			else if (tmp->infos->epoch_time == tmp2->infos->epoch_time)
			{
				if (ft_strcmp(tmp->infos->name, tmp2->infos->name) > 0)
					swapi(tmp, tmp2);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
