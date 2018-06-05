/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:21:05 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/10 17:39:38 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lapin;

	if (lst != NULL)
	{
		lapin = (t_list*)malloc(sizeof(f(lst)));
		if (lapin == NULL)
			return (NULL);
		lapin = f(lst);
		lapin->next = ft_lstmap(lst->next, f);
		return (lapin);
	}
	return (NULL);
}
