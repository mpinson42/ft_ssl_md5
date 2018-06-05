/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:42:18 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/09 18:55:10 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	char	*temp_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2));
	if (!(str = (char *)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	temp_str = str;
	while (*s1 != '\0')
		*temp_str++ = *s1++;
	while (*s2 != '\0')
		*temp_str++ = *s2++;
	*temp_str++ = '\0';
	return (str);
}
