/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:03:33 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 18:03:39 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(float chiffre, int decimal)
{
	char	*tmp;
	int		i;

	i = 0;
	if (decimal < 0)
		decimal = 6;
	tmp = ft_itoa(chiffre);
	chiffre = chiffre - (int)chiffre;
	while (i < decimal)
	{
		chiffre = chiffre * 10;
		i++;
	}
	tmp = ft_strjoin(tmp, ".");
	tmp = ft_strjoin(tmp, ft_itoa(ft_absolut(chiffre)));
	return (tmp);
}
