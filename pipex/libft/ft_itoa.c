/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:52:14 by djoung            #+#    #+#             */
/*   Updated: 2024/10/13 21:49:26 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	cnt;

	cnt = 0;
	if (n <= 0)
	{
		cnt += 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		n_len;
	int		num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_len = ft_len(n);
	itoa = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!itoa)
		return (NULL);
	itoa[n_len] = '\0';
	if (n < 0)
	{
		itoa[0] = '-';
		n = -n;
	}
	if (n == 0)
		itoa[0] = '0';
	while (n > 0)
	{
		num = n % 10;
		n /= 10;
		itoa[--n_len] = num + '0';
	}
	return (itoa);
}
