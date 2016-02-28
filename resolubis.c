/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolubis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaradja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 15:13:16 by akaradja          #+#    #+#             */
/*   Updated: 2016/02/28 15:18:40 by akaradja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	resolubis(char **tab, t_pi *pieces, t_dom *info, t_sol *sol)
{
	if (sol = normal(pieces, where(tab, info), tab))
	{
		fpf("put:%d:%d:%d:%d:%d:%d\n", sol->a, sol->b, sol->col, sol->lin, \
		sol->sen, sol->ori);
		return ;
	}
	else
	fpf("sulk\n");
}
