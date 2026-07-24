/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:16:17 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/03 13:16:47 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *str)
{
	int	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

int	str_contains(char *str, char c)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

int	is_valid_base(char *base)
{
	if (str_len(base) < 2)
		return (0);
	if (str_contains(base, '+') || str_contains(base, '-'))
		return (0);
	while (*base)
	{
		if (str_contains(base + 1, *base))
			return (0);
		base++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbrl;
	int		length;

	nbrl = nbr;
	length = str_len(base);
	if (is_valid_base(base) == 0)
		return ;
	if (nbrl < 0)
	{
		write(1, "-", 1);
		nbrl = -nbrl;
	}
	if (nbrl >= length)
	{
		ft_putnbr_base(nbrl / length, base);
	}
	write(1, base + (nbrl % length), 1);
	return ;
}
