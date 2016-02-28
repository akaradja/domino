/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 21:35:30 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/28 00:45:06 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dom.h"

int			fill_a(char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		i++;
	return (ft_atoi(line + i));
}

int			fill_b(char *line)
{
	int		i;

	i = ft_strlen(line) - 1;
	while (ft_isdigit(line[i]))
		i--;
	return (ft_atoi(line + i + 1));
}

void		add_piece(t_pi **pi, char *line)
{
	t_pi	*save;

	if (*pi == NULL)
	{
		if (!(*pi = ft_memalloc(sizeof(t_pi))))
			return ;
		(*pi)->a = fill_a(line);
		(*pi)->b = fill_b(line);
		(*pi)->next = NULL;
	}
	else
	{
		save = *pi;
		while ((save)->next)
			save = save->next;
		if (!(save->next = ft_memalloc(sizeof(t_pi))))
			return ;
		save = save->next;
		save->a = fill_a(line);
		save->b = fill_b(line);
		save->next = NULL;
	}
}
