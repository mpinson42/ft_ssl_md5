/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_putchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:51:51 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/14 19:51:56 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_uni_putchar_5(wchar_t n)
{
	unsigned char	octets[4];
	char			*str;
	int				i;
	char			*bite[4];

	str = ft_itoa_base(n, 2);
	i = ft_strlen(str);
	bite[0] = ft_strjoin("10", ft_strsub(str, i - 6, 6));
	bite[1] = ft_strjoin("10", ft_strsub(str, i - 12, 6));
	bite[2] = ft_strsub(str, 0, i - 12);
	if ((i = ft_strlen(bite[2])) < 6)
	{
		i = 6 - i;
		bite[2] = ft_pushback(bite[2], i, '0');
	}
	bite[2] = ft_strjoin("10", bite[2]);
	octets[0] = (char)ft_atoi_base(bite[0], 2);
	octets[1] = (char)ft_atoi_base(bite[1], 2);
	octets[2] = (char)ft_atoi_base(bite[2], 2);
	octets[3] = (char)ft_atoi_base("11110000", 2);
	write(1, &octets[3], 1);
	write(1, &octets[2], 1);
	write(1, &octets[1], 1);
	write(1, &octets[0], 1);
}

void	ft_uni_putchar_4(wchar_t n)
{
	unsigned char	octets[4];
	char			*str;
	int				i;
	char			*bite[4];

	str = ft_itoa_base(n, 2);
	i = ft_strlen(str);
	bite[0] = ft_strjoin("10", ft_strsub(str, i - 6, 6));
	bite[1] = ft_strjoin("10", ft_strsub(str, i - 12, 6));
	bite[2] = ft_strjoin("10", ft_strsub(str, i - 18, 6));
	bite[3] = ft_strsub(str, 0, i - 18);
	if ((i = ft_strlen(bite[3])) < 3)
	{
		i = 3 - i;
		bite[3] = ft_pushback(bite[3], i, '0');
	}
	bite[3] = ft_strjoin("11110", bite[3]);
	octets[0] = (char)ft_atoi_base(bite[0], 2);
	octets[1] = (char)ft_atoi_base(bite[1], 2);
	octets[2] = (char)ft_atoi_base(bite[2], 2);
	octets[3] = (char)ft_atoi_base(bite[3], 2);
	write(1, &octets[3], 1);
	write(1, &octets[2], 1);
	write(1, &octets[1], 1);
	write(1, &octets[0], 1);
}

int		ft_uni_putchar_3(wchar_t n)
{
	unsigned char	octets[4];
	char			*str;
	int				i;
	char			*bite[4];

	str = ft_itoa_base(n, 2);
	i = ft_strlen(str);
	bite[0] = ft_strjoin("10", ft_strsub(str, i - 6, 6));
	bite[1] = ft_strjoin("10", ft_strsub(str, i - 12, 6));
	bite[2] = ft_strsub(str, 0, i - 12);
	if ((i = ft_strlen(bite[2])) < 4)
	{
		i = 4 - i;
		bite[2] = ft_pushback(bite[2], i, '0');
	}
	bite[2] = ft_strjoin("1110", bite[2]);
	octets[0] = (char)ft_atoi_base(bite[0], 2);
	octets[1] = (char)ft_atoi_base(bite[1], 2);
	octets[2] = (char)ft_atoi_base(bite[2], 2);
	write(1, &octets[2], 1);
	write(1, &octets[1], 1);
	write(1, &octets[0], 1);
	return (3);
}

int		ft_uni_putchar_2(wchar_t n)
{
	unsigned char	octets[4];
	char			*str;
	int				i;
	char			*bite[4];

	str = ft_itoa_base(n, 2);
	i = ft_strlen(str);
	bite[0] = ft_strjoin("10", ft_strsub(str, i - 6, 6));
	bite[1] = ft_strsub(str, 0, i - 6);
	if ((i = ft_strlen(bite[1])) < 5)
	{
		i = 5 - i;
		bite[1] = ft_pushback(bite[1], i, '0');
	}
	bite[1] = ft_strjoin("110", bite[1]);
	octets[0] = (char)ft_atoi_base(bite[0], 2);
	octets[1] = (char)ft_atoi_base(bite[1], 2);
	write(1, &octets[1], 1);
	write(1, &octets[0], 1);
	return (2);
}

int		ft_uni_putchar(wchar_t n)
{
	int i;

	i = ft_strlen(ft_itoa_base(n, 2));
	if (i <= 7)
	{
		ft_putchar(n);
		return (1);
	}
	if (i > 7 && i <= 11)
		return (ft_uni_putchar_2(n));
	if (i > 11 && i <= 16)
		return (ft_uni_putchar_3(n));
	if (i > 16 && i <= 18)
	{
		ft_uni_putchar_5(n);
		return (4);
	}
	if (i > 18 && i <= 21)
	{
		ft_uni_putchar_4(n);
		return (4);
	}
	return (0);
}
