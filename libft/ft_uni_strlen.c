/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:58:25 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:58:27 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		counter(wchar_t n)
{
	int i;

	i = ft_strlen(ft_itoa_base(n, 2));
	if (i <= 7)
		return (1);
	if (i > 7 && i <= 11)
		return (2);
	if (i > 11 && i <= 16)
		return (3);
	if (i > 16 && i <= 21)
		return (4);
	return (0);
}

size_t	ft_uni_strlen(const wchar_t *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		count = count + counter(s[i]);
		i++;
	}
	return (count);
}
