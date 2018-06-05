/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 01:07:11 by mpinson           #+#    #+#             */
/*   Updated: 2016/08/08 01:07:14 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb > 12)
		nb = 0;
	else if (nb > 1)
		nb *= ft_recursive_factorial(nb - 1);
	else if (nb == 0)
		nb = 1;
	else if (nb < 0)
		nb = 0;
	return (nb);
}
