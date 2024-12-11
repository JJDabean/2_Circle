/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:36:39 by djoung            #+#    #+#             */
/*   Updated: 2024/10/11 17:02:45 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_letsatoi(const char **str, int sign)
{
	long	result;

	result = 0;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		if (result * sign > 2147483647)
			return (-1);
		if (result * sign < -2147483648)
			return (0);
		(*str)++;
	}
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	n;

	n = 0;
	sign = 1;
	while (*str >= 9 && (*str <= 13 || *str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign = -1;
	}
	n = ft_letsatoi(&str, sign);
	return (n);
}
