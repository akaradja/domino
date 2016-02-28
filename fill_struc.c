/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:14:32 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/28 03:22:49 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dom.h"

void			fill_new(t_dom *dom, char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		i++;
	dom->new_a = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	dom->new_b = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	dom->new_x = ft_atoi(line + i) + 1;
	while (ft_isdigit(line[i]))
		i++;
	i++;
	dom->new_y = ft_atoi(line + i) + 1;
	while (ft_isdigit(line[i]))
		i++;
	i++;
	dom->sense = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	dom->orient = ft_atoi(line + i);
}

void			get_size_board(int *x, int *y, char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		i++;
	*x = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	*y = ft_atoi(line + i);
	return ;
}

int				get_nb_piece(char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		i++;
	return (ft_atoi(line + i));
}

void			init_dom(t_dom **dom)
{
	if ((*dom = ft_memalloc(sizeof(t_dom))))
		return ;
	(*dom)->size_x = 0;
	(*dom)->size_y = 0;
	(*dom)->player = 0;
	(*dom)->nb_piece = 0;
	(*dom)->new_y = 0;
	(*dom)->new_x = 0;
	(*dom)->new_a = 0;
	(*dom)->new_b = 0;
	(*dom)->sense = 0;
	(*dom)->orient = 0;
	(*dom)->go = 0;
}

t_dom			*fill_info(char *line)
{
	static t_dom	*dom = NULL;

	if (!(dom))
		init_dom(&dom);
	if (ft_strstr(line, "player"))
		dom->player = ft_atoi(line + ft_strlen(line) - 1);
	if (ft_strstr(line, "board"))
		get_size_board(&dom->size_x, &dom->size_y, line);
	if (ft_strstr(line, "pieces"))
		dom->nb_piece = get_nb_piece(line);
	if (ft_strstr(line, "go"))
		dom->go = 1;
	if (ft_strstr(line, "new"))
		fill_new(dom, line);
	if (ft_strstr(line, "end"))
		exit(0);
	return (dom);
}
