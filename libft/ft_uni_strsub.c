/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_strsub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:59:05 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/24 17:59:08 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_uni_strsub(wchar_t *s, unsigned int start, size_t len)
{
	unsigned int	i;
	wchar_t			*str;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = (wchar_t *)malloc(sizeof(wchar_t) * len + 1)))
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
