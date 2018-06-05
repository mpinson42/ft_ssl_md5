/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:57:23 by mpinson           #+#    #+#             */
/*   Updated: 2016/12/28 10:06:16 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_joinfree(char *s1, char *s2, int mode)
{
	if (s1 && mode == 0)
		ft_strdel(&s1);
	if (s2 && mode == 1)
		ft_strdel(&s2);
	if (s1 && s2 && mode == 2)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
}

char		*ft_strjoin_free(char *s1, char *s2, int mode)
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
	ft_joinfree(s1, s2, mode);
	return (str);
}
