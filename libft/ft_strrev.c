/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:39:21 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/09 14:11:57 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		a;
	char	stock;
	int		div;

	i = 0;
	a = 0;
	while (str[i + 1] != '\0')
		i++;
	div = i / 2;
	while (i > div)
	{
		stock = str[i];
		str[i] = str[a];
		str[a] = stock;
		i--;
		a++;
	}
	return (str);
}
