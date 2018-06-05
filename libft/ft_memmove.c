/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:23:26 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/10 12:54:56 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_cp(const void *s1, const void *s2, size_t n)
{
	char	*s11;
	char	*s22;

	s11 = (char *)s1;
	s22 = (char *)s2;
	while (n--)
	{
		s11[n] = s22[n];
	}
	return (s11);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		dest = ft_memcpy(dest, src, n);
	if (dest > src)
		dest = ft_cp(dest, src, n);
	return (dest);
}
