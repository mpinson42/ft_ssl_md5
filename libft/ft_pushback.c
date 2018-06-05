/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:02:24 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 18:02:29 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pushback(char *str, int i, char c)
{
	char	*tmp;
	int		j;
	int		k;

	k = 0;
	j = ft_strlen(str);
	tmp = str;
	if (!(str = (char *)malloc(sizeof(char) * (j + i + 1))))
		return (NULL);
	while (i > 0)
	{
		str[k] = c;
		k++;
		i--;
	}
	while (tmp[i])
	{
		str[k] = tmp[i];
		k++;
		i++;
	}
	str[k] = 0;
	return (str);
}
