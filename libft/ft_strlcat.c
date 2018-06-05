/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:06:22 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/28 18:32:27 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int len;
	int j;
	int save;
	int save_1;
	int save_2;

	j = 0;
	while (dest[j])
		j++;
	save_1 = ft_strlen(dest);
	save_2 = ft_strlen(src);
	save = j;
	len = 0;
	while (src[len] && (len + save_1) < (int)size - 1)
	{
		dest[j] = src[len];
		++j;
		++len;
	}
	if (j != save)
		dest[j] = '\0';
	if (save_1 > (int)size)
		return (save_2 + size);
	return (save_1 + save_2);
}
