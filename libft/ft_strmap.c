/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:22:07 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/12 18:44:12 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	char	*temp_dest;

	if (s == NULL)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	temp_dest = dest;
	while (*s != '\0')
		*temp_dest++ = (*f)(*s++);
	*temp_dest = '\0';
	return (dest);
}
