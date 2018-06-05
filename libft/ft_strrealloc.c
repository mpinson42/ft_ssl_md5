/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 09:41:19 by mpinson           #+#    #+#             */
/*   Updated: 2016/12/28 13:28:27 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *str, size_t n)
{
	int		size;
	int		i;
	char	*new;

	size = ft_strlen(str);
	if (!(new = (char *)malloc(sizeof(char) * (size + n))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = str[i];
		size++;
		i++;
	}
	ft_strdel(&str);
	return (new);
}
