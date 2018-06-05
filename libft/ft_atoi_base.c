/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:00:23 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/06 15:00:28 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char *str, int base)
{
	int	i;
	int nb;

	nb = 0;
	i = 0;
	while (ft_isdigit(str[i]) || (str[i] >= 97 && str[i] <= 122) ||
		(str[i] >= 65 && str[i] <= 90))
	{
		nb = nb * base;
		if (str[i] >= 48 && str[i] <= 57)
		{
			nb = nb + (str[i] - 48);
		}
		else if (str[i] >= 97 && str[i] <= 122)
			nb = nb + (str[i] - 97 + 10);
		else if (str[i] >= 65 && str[i] <= 90)
			nb = nb + (str[i] - 65 + 10);
		i++;
	}
	return (nb);
}

int	ft_atoi_base(char *str, int base)
{
	int i;
	int neg;

	i = 0;
	neg = 1;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	return (check(&str[i], base) * neg);
}
