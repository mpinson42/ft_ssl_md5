/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:23:04 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/09 17:56:45 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_str2(const char *s1, const char *s2, int i)
{
	int		j;

	j = 0;
	while (s2[j] == s1[i] && s1[i] != '\0' && s2[j] != '\0')
	{
		i++;
		j++;
		if (s2[j] == '\0')
			return (1);
	}
	return (0);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (s2[0] == '\0' && s1[0] == '\0')
		return ((char *)s1);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s2[0] == s1[i])
		{
			if (ft_str2(s1, s2, i) == 1)
				return ((char *)s1 + i);
		}
		i++;
	}
	return (0);
}
