/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:05:27 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/09 18:51:20 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = ft_strlen(dest);
	while (src[i] && i < n)
	{
		dest[a + i] = src[i];
		i++;
	}
	dest[a + i] = '\0';
	return (dest);
}
