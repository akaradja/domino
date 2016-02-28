/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaradja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 04:33:08 by akaradja          #+#    #+#             */
/*   Updated: 2016/02/28 15:19:47 by akaradja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	first_pi(t_pi *pieces)
{
	t_pi	*solution;

	solution = ft_memalloc(sizeof(t_pi));
	solution->a = -1;
	while (pieces->next)
	{
		if ((pieces->a == 5) && (pieces->b == 5))
		{
			fpf("put:5:5\n");
			return ;
		}
		if ((pieces->a == pieces->b) && (pieces->a > solution->a))
			solution = pieces;
	}
	if (solution->a == -1)
		fpf("sulk\n");
	else
		fpf("put:%d:%d\n", solution->a, solution->b);
}

t_ext	*where(char **tab, t_dom *info)
{
	int		i;
	int		j;
	t_ext	*libres;
	t_ext	fin;

	libres = ft_memalloc(sizeof(t_ext));
	libres->carac = -1;
	while (i < info->size_x)
	{
		if (isfree(tab, i, j))
			ft_lstadd(ft_lstend(libres), add_sol(tab[i][j], i, j));
		if (isspecial(tab, i, j))
			ft_lstadd(ft_lstend(libres), add_sol(tab[i][j], i, j));
		if (tab[i][j] == '\n')
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	fin = ft_lstend(libres);
	fin->next = NULL;
	return (libres);
}

int		sum_extr(char **tab, t_dom *info)
{
	int i;
	int j;
	int somme;

	i = 0;
	j = 0;
	somme = 0;
	while (i < info->size_x)
	{
		if (isfree(tab, i, j))
			somme += ft_atoi(tab[i][j]);
		if (tab[i][j] == '\n')
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (somme);
}

void	resolution(char **tab, t_pi *pieces, t_dom *info)
{
	t_sol	*sol;

	sol = ft_memalloc(sizeof(t_sol));
	if (info->go)
	{
		if (info->go == 2)
		{
			first_pi(pieces);
			return ;
		}
		if (sol = multiple(pieces, where(tab, info), tab, info))
		{
			fpf("put:%d:%d:%d:%d:%d:%d\n", sol->a, sol->b, sol->col, sol->lin,\
			sol->sen, sol->ori);
			return ;
		}
		if (sol = doubl(pieces, where(tab, info), tab))
		{
			fpf("put:%d:%d:%d:%d:%d:%d\n", sol->a, sol->b, sol->col, sol->lin,\
			sol->sen, sol->ori);
			return ;
		}
		else
			resolubis(tab, , pieces, info, sol);
	}
}
