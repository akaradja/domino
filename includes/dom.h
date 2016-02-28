/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dom.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:59:42 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/28 14:36:12 by akaradja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOM_H
# define DOM_H

# include "libft.h"
# include <errno.h>

# define DEBUG fpf("%d - %s - %s\n", __LINE__, __func__, __FILE__);

typedef	struct		s_ext
{
	int				carac;
	int				column;
	int				line;
	struct s_ext	*next;
}					t_ext;

typedef	struct		s_sol
{
	int				a;
	int				b;
	int				col;
	int				lin;
	int				sen;
	int				ori;
}					t_sol;

typedef struct		s_dom
{
	int				size_x;
	int				size_y;
	int				player;
	int				nb_piece;
	int				new_y;
	int				new_x;
	int				new_a;
	int				new_b;
	int				sense;
	int				orient;
	int				go;
}					t_dom;

typedef struct		s_pi
{
	int				a;
	int				b;
	struct s_pi		*next;
}					t_pi;

t_dom				*fill_info(char *line);
void				add_piece(t_pi **pi, char *line);
void				dom_error(int flag);
void				update_tab(char **tab, char *line, t_dom *info);
void				show_me_tab(char **tab, t_dom *info);
char				**malloc_tab(t_dom *info);
void				resolution(char **tab, t_pi *pieces, t_dom *info);
int					sum_extr(char **tab, t_dom *info);
t_ext				where(char **tab, t_dom info);
void				first_pi(t_pi *pieces);
t_sol				*normal(t_pi *pieces, t_ext *libres, char **tab);
t_sol				*norm(t_pi *pieces, t_ext *libres, t_sol solution, char **tab);
t_sol				*doubl(t_pi *pieces, t_ext*libres, char **tab);
t_sol				*multiple(t_pi *pieces, t_ext *libres, char **tab, t_dom info);
t_sol				*mult(t_pi *pieces, t_ext *libres, int somme, t_sol *solution);
t_ext				*add_sol(char c, int i, int j);
int					isfree(char **tab, int i, int j);
int					isspecial(char **tab, int i, int j);
t_sol				*parametres(t_ext *libres, t_sol *solution, char **tab);

#endif
