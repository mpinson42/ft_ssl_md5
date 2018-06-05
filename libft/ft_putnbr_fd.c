/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:33:02 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/09 18:59:35 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		display_min_int(int fd)
{
	ft_putchar_fd('-', fd);
	ft_putchar_fd(2 + 48, fd);
	ft_putchar_fd(1 + 48, fd);
	ft_putchar_fd(4 + 48, fd);
	ft_putchar_fd(7 + 48, fd);
	ft_putchar_fd(4 + 48, fd);
	ft_putchar_fd(8 + 48, fd);
	ft_putchar_fd(3 + 48, fd);
	ft_putchar_fd(6 + 48, fd);
	ft_putchar_fd(4 + 48, fd);
	ft_putchar_fd(8 + 48, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		display_min_int(fd);
	else
	{
		if (n < 0 && n != -2147483648)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
			ft_putchar_fd(n + 48, fd);
	}
}
