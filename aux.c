/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaradja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 08:56:20 by akaradja          #+#    #+#             */
/*   Updated: 2016/02/28 15:53:28 by akaradja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ext	*add_sol(char c, int i, int j)
{
	t_ext	*new;

	new->carac = c;
	new->column = j;
	new->line = i;
	return (new);
}

int		isfree(char **tab, int i, int j)
{
	if ((ft_isdigit(tab[i][j])) && (!(ft_isdigit(tab[i + 1][j])) || \
	!(ft_isdigit(tab[i - 1][j])) || !(ft_isdigit(tab[i][j + 1])) ||\
	!(ft_isdigit(tab[i][j - 1]))))
		return (1);
	else
		return (0);
}

int		isspecial(char **tab, int i, int j)
{
	if ((tab[i][j] == '|') && ((tab[i + 1][j] == tab[i - 1][j]) && \
	(!(ft_isdigit(tab[i][j + 1])) || (!(ft_isdigit(tab[i][j - 1]))))))
		return (1);
	else if ((tab[i][j] == '|') && ((tab[i][j + 1] == tab[i][j - 1]) && \
		(!(ft_isdigit(tab[i + 1][j])) || (!(ft_isdigit(tab[i - 1][j]))))))
		return (1);
	else
		return (0);
}


t_sol	*parametres(t_ext *libres, t_sol *solution, char **tab, t_dom *info)
{
	if (tab[libres->line - 1][libres->column] == '|')
	{
		solution->sen = 1;
		solution->ori = 2;
		if (line + 3 <= info->size_x)
		{
			solution->column = libres->column;
			solution->line = libres->line + 1;
		}
		else
	}
	if (tab[libres->line + 1][libres->column] == '|')
	{
		solution->sen = 1;
		solution->ori = 1;
		if (line - 3 >= 0)
		{
			solution->column = libres->column;
			solution->line = libres->line - 1;
		}
		else
	}
	if (tab[libres->line][libres->column - 1] == '|')
	{
		solution->sen = 2;
		solution->ori = 2;
		if (column + 3 <= info->size_y)
		{
			solution->column = libres->column + 1;
			solution->line = libres->line;
		}
		else
	}
	if (tab[libres->line][libres->column + 1] == '|')
	{
		solution->sen = 2;
		solution->ori = 1;
		if (column - 3 >= 0)
		{
			solution->column = libres->column - 1;
			solution->line = libres->line;
		}
	}

	return (solution);
}
