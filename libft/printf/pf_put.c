/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:54:44 by rle-mino          #+#    #+#             */
/*   Updated: 2016/01/30 17:56:58 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_prec_nbr(int nbr)
{
	int		k;

	if (nbr < 1)
		return (0);
	k = nbr;
	while (nbr--)
		ft_putchar('0');
	return (k);
}
