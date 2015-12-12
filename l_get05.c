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

char		getgright(mode_t buff)
{
	if ((buff & S_ISGID) && (buff & S_IXGRP))
		return ('s');
	else if ((buff & S_ISGID) && !(buff & S_IXGRP))
		return ('S');
	else if (buff & S_IXGRP)
		return ('x');
	else
		return ('-');
}

char		geturight(mode_t buff)
{
	if ((buff & S_ISUID) && (buff & S_IXUSR))
		return ('s');
	else if ((buff & S_ISUID) && !(buff & S_IXUSR))
		return ('S');
	else if (buff & S_IXUSR)
		return ('x');
	else
		return ('-');
}

char		getoright(mode_t buff)
{
	if ((buff & S_ISVTX) && (buff & S_IXOTH))
		return ('t');
	else if ((buff & S_ISVTX) && !(buff & S_IXOTH))
		return ('T');
	else if (buff & S_IXOTH)
		return ('x');
	else
		return ('-');
}
