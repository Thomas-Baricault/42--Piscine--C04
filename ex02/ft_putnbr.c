/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:55:29 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/03 13:12:47 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	nbl;
	char	c;

	nbl = nb;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = -nbl;
	}
	if (nbl > 9)
	{
		ft_putnbr(nbl / 10);
	}
	c = '0' + (nbl % 10);
	write(1, &c, 1);
	return ;
}
