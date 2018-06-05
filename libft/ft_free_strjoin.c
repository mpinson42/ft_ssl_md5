/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 10:06:31 by mpinson           #+#    #+#             */
/*   Updated: 2016/12/28 10:06:47 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strjoin(char **str, char *str2)
{
	char	*temp;

	temp = ft_strdup(*str);
	free(*str);
	*str = ft_strjoin(temp, str2);
	free(temp);
}
