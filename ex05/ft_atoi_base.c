/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:45:59 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/03 13:20:23 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

int	str_find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	is_valid_base(char *base)
{
	if (str_len(base) < 2)
		return (0);
	while (*base)
	{
		if (str_find("+- \t\n\v\f\r", *base) != -1)
			return (0);
		if (str_find(base + 1, *base) != -1)
			return (0);
		base++;
	}
	return (1);
}

int	change_sign(int *is_negative, char c)
{
	if (c == '-')
	{
		*is_negative = 1 - *is_negative;
		return (1);
	}
	else
	{
		return (c == '+');
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	r;
	int	i;
	int	is_negative;

	if (is_valid_base(base) == 0)
		return (0);
	r = 0;
	is_negative = 0;
	while (str_find(" \t\n\v\f\r", *str) != -1)
		str++;
	while (change_sign(&is_negative, *str))
		str++;
	i = 0;
	while (i != -1)
	{
		i = str_find(base, *str);
		if (i != -1)
			r = r * str_len(base) + str_find(base, *str++);
	}
	if (is_negative)
		return (-r);
	else
		return (r);
}
