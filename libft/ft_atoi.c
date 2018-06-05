/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:01:53 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/09 19:12:57 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_atoi(const char *str)
{
	int i;
	int res;
	int neg;

	neg = 1;
	res = 0;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f'
				|| str[i] == '\r' || str[i] == '\v') && str[i])
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] <= '9' && str[i] >= '0') && str[i])
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
}
