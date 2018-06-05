/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:01:04 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/11 13:38:15 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*intmax(char *str)
{
	if (!(str = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	str[0] = '-';
	str[1] = 2 + 48;
	str[2] = 1 + 48;
	str[3] = 4 + 48;
	str[4] = 7 + 48;
	str[5] = 4 + 48;
	str[6] = 8 + 48;
	str[7] = 3 + 48;
	str[8] = 6 + 48;
	str[9] = 4 + 48;
	str[10] = 8 + 48;
	str[11] = '\0';
	return (str);
}

static char	*zero(char *str)
{
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*other(char *str, int i, size_t n, int neg)
{
	if (neg == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * i + 2)))
			return (NULL);
		str[0] = '-';
		str[i + 1] = '\0';
		while (i > 0)
		{
			str[i] = n % 10 + 48;
			n = n / 10;
			i--;
		}
	}
	else
	{
		if (!(str = (char *)malloc(sizeof(char) * i + 1)))
			return (NULL);
		str[i] = '\0';
		while (i >= 0)
		{
			str[i-- - 1] = n % 10 + 48;
			n = n / 10;
		}
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		len;
	int		neg;
	char	*str;

	neg = 1;
	len = n;
	i = 0;
	str = NULL;
	if (n < 0)
	{
		neg = 0;
		n = -n;
	}
	if (n == 0)
		return (zero(str));
	if (n == -2147483648)
		return (intmax(str));
	while (len != 0)
	{
		len = len / 10;
		i++;
	}
	str = other(str, i, n, neg);
	return (str);
}
