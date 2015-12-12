/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_get04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 12:49:04 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/09/23 12:35:03 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline __int32_t	ft_major(__uint32_t x)
{
	return (__int32_t)(((__uint32_t)x >> 24) & 0xff);
}

static inline __int32_t	ft_minor(__uint32_t x)
{
	return (__int32_t)((x) & 0xffffff);
}

int						get_minor(dev_t buff)
{
	return (ft_minor(buff));
}

int						get_major(dev_t buff)
{
	return (ft_major(buff));
}
