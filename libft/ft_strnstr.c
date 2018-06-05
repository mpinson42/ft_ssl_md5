/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:21:53 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/07 11:02:20 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_str2(const char *s1, const char *s2, size_t i, size_t n)
{
	size_t	j;

	j = 0;
	while (s2[j] == s1[i] && s1[i] != '\0' && s2[j] != '\0' && i < n)
	{
		i++;
		j++;
		if (s2[j] == '\0')
			return (1);
	}
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s2[0] == '\0' && s1[0] == '\0')
		return ((char *)s1);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s2[0] == s1[i])
		{
			if (ft_str2(s1, s2, i, n) == 1)
				return ((char *)s1 + i);
		}
		i++;
	}
	return (0);
}
