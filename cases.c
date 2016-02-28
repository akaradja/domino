/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaradja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 12:56:51 by akaradja          #+#    #+#             */
/*   Updated: 2016/02/28 15:53:31 by akaradja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sol	*mult(t_pi *pieces, t_ext *libres, int somme, t_sol *solution)
{
	if (((pieces->a == libres->carac) && ((pieces->b - pieces->a + somme) \
	% 5 == 0)) && ((pieces->a + pieces->b) > (solution->a + solution->b)))
	{
		solution->a = pieces->a;
		solution->b = pieces->b;
	}
	if (((pieces->b == libres->carac) && ((pieces->a - pieces->b + somme) \
	% 5 == 0)) && ((pieces->a + pieces->b) > (solution->a + solution->b)))
	{
		solution->a = pieces->b;
		solution->b = pieces->a;
	}
	return (solution);
}


t_sol	*multiple(t_pi *pieces, t_ext *libres, char **tab, t_dom info)
{
	t_sol	*solution;
	t_ext	*temp;
	t_ext	*temppi;
	int		somme;

	temp = libres;
	temppi = pieces;
	solution = ft_memalloc(sizeof(t_sol));
	solution->a = -1;
	somme = sum_extr(tab, info);
	while (temppi)
	{
		while (temp)
		{
			solution = mult(temppi, temp, somme, solution);
			solution = parametres(temp, solution, tab);
			temp = temp->next;
		}
		temppi = temppi->next;
	}
	if (solution->a = -1)
		solution = NULL;
	return (solution);
}

t_sol	*doubl(t_pi *pieces, t_ext *libres, char **tab)
{
	t_sol	*solution;
	t_ext	*temp;
	t_ext	*temppi;

	temp = libres;
	temppi = pieces;
	solution = ft_memalloc(sizeof(t_sol));
	solution->a = -1;
	while (temppi)
	{
		while (temp)
		{
			if ((temppi->a == temp->carac) && (temppi->a == temppi->b) && \
					(temppi->a > solution->a))
			{
				solution->a = temppi->a;
				solution->b = temppi->a;
				solution = parametres(libres, solution, tab);
			}
			temp = temp->next;
		}
		temppi = temppi->next;
	}
		if (solution->a = -1)
			solution = NULL;
		return (solution);
}

t_sol	*norm(t_pi *pieces, t_ext *libres, t_sol solution, char **tab)
{
	if (temppi->a == temp->carac) && ((temppi->a + temppi->b) > (solution->a + solution->b))
	{
		solution->a = temppi->a;
		solution->b = temppi->b;
	}
	if (temppi->b == temp->carac) && ((temppi->a + temppi->b) > (solution->a + solution->b))
	{
		solution->a = temppi->b;
		solution->b = temppi->a;
	}
	solution = parametres(libres, solution, tab);
	return (solution);
}

t_sol	*normal(t_pi *pieces, t_ext *libres, char **tab)
{
	t_sol	*solution;
	t_ext	*temp;
	t_ext	*temppi;

	temp = libres;
	temppi = pieces;
	solution = ft_memalloc(sizeof(t_sol));
	solution->a = -1;
	while (temppi)
	{
		while (temp)
		{
			solution = norm(temppi, temp, solution, tab);
			temp = temp->next;
		}
		temppi = temppi->next;
	}
	if (solution->a = -1)
		solution = NULL;
	return (solution);
}
