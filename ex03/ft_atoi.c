/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:59:44 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/03 13:19:32 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (
		c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
	);
}

int	is_digit(char c)
{
	return ('0' <= c && c <= '9');
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

int	ft_atoi(char *str)
{
	int	r;
	int	is_negative;

	r = 0;
	is_negative = 0;
	while (is_space(*str))
		str++;
	while (change_sign(&is_negative, *str))
		str++;
	while (is_digit(*str))
		r = r * 10 + (*str++ - '0');
	if (is_negative)
		return (-r);
	else
		return (r);
}
