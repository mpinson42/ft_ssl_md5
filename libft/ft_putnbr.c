/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:36:07 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/28 20:12:49 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	display_min_int1(void)
{
	ft_putchar('-');
	ft_putchar(2 + 48);
	ft_putchar(1 + 48);
	ft_putchar(4 + 48);
	ft_putchar(7 + 48);
	ft_putchar(4 + 48);
	ft_putchar(8 + 48);
	ft_putchar(3 + 48);
	ft_putchar(6 + 48);
	ft_putchar(4 + 48);
	ft_putchar(8 + 48);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		display_min_int1();
	else
	{
		if (nb < 0 && nb != -2147483648)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
			ft_putchar(nb + 48);
	}
}
