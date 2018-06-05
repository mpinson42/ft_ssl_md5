/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:43:04 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/09 18:05:10 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	char			*temp_dest;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	temp_dest = dest;
	while (*s != '\0')
		*temp_dest++ = (*f)(i++, *s++);
	*temp_dest = '\0';
	return (dest);
}
