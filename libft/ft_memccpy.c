/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:28:16 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/09 19:10:25 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest1;
	char	*src1;

	dest1 = (char*)dest;
	src1 = (char*)src;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		if (dest1[i] == c)
			return (dest1 + i + 1);
		i++;
	}
	return (NULL);
}
