/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_norme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 23:38:28 by mpinson           #+#    #+#             */
/*   Updated: 2018/06/07 23:38:31 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	escape_norme2(t_gen *g, char **argv)
{
	if (ft_strcmp(argv[1], "sha256") == 0)
		go_sha256(g->stdin, g);
	else if (ft_strcmp(argv[1], "sha224") == 0)
		go_sha224(g->stdin, g);
	else
		go_md5(g->stdin, g);
	if (!g->f_q)
	{
		ft_putstr(" ");
		ft_putstr(argv[g->pars]);
		ft_putstr("\n");
	}
	else
		ft_putstr("\n");
}
