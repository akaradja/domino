/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:58:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/28 02:48:57 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dom.h"

void	show_me_tab(char **tab, t_dom *info)
{
	int		x;

	x = -1;
	while (++x < info->size_x)
		fpf("%s\n", tab[x]);
}

void	show_me(t_pi *pieces)
{
	while (pieces)
	{
		fpf("My piece:%d:%d\n", pieces->a, pieces->b);
		pieces = pieces->next;
	}
}

int		main(void)
{
	char	*line;
	t_dom	*info;
	t_pi	*pieces;
	char	**tab;

	pieces = NULL;
	tab = NULL;
	while (get_next_line(0, &line) == 1)
	{
		info = fill_info(line);
		fpf("size_x = %d\nsize_y = %d\nplayer = %d\nnb_piece = %d\ngo = %d\n",info->size_x, info->size_y, info->player, info->nb_piece, info->go);
		if (ft_strstr(line ,"piece:"))
			add_piece(&pieces, line);
		if (ft_strstr(line, "new:"))
		{
			if (tab == NULL)
				tab = malloc_tab(info);
			update_tab(tab, line, info);
			show_me_tab(tab, info);
		}
		show_me(pieces);
		free(line);
	}
}
