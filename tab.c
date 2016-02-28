/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 00:45:12 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/28 03:20:40 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dom.h"

char		**malloc_tab(t_dom *info)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = ft_memalloc(sizeof(char *) * (info->size_x + 1));
	while (i < info->size_x)
	{
		tab[i] = ft_memalloc(info->size_y + 1);
		ft_memset(tab[i], ' ', info->size_y);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void		update_tab(char **tab, char *line, t_dom *info)
{
	tab[info->new_x][info->new_y] = info->new_a + '0';
	if (info->sense == 2 && info->orient == 2)
	{
		DEBUG;
		tab[info->new_x][info->new_y - 1] = '|';
		tab[info->new_x][info->new_y - 2] = info->new_b + '0';
	}
	else if (info->sense == 1 && info->orient == 2)
	{
		DEBUG
		tab[info->new_x - 1][info->new_y] = '|';
		tab[info->new_x - 2][info->new_y] = info->new_b + '0';
	}
	else if (info->sense == 2 && info->orient == 1)
	{
		DEBUG
		tab[info->new_x][info->new_y + 1] = '|';
		tab[info->new_x][info->new_y + 2] = info->new_b + '0';
	}
	else if (info->sense == 1 && info->orient == 1)
	{
		DEBUG
		tab[info->new_x + 1][info->new_y] = '|';
		tab[info->new_x + 2][info->new_y] = info->new_b + '0';
	}
}
