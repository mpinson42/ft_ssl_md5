/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:27:12 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/11 13:59:05 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_trimlen(char *str)
{
	size_t i;
	size_t space;
	size_t len;

	len = ft_strlen(str);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	space = i;
	if (str[i] != '\0')
	{
		i = len - 1;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			i--;
			space++;
		}
	}
	return (len - space);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	trim_len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	trim_len = ft_trimlen((char *)s);
	if (!(str = (char *)malloc(sizeof(char) * (trim_len + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (j < trim_len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
