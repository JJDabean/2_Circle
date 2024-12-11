/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:58:44 by djoung            #+#    #+#             */
/*   Updated: 2024/10/03 15:34:55 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*new_s;
	unsigned char	src;
	size_t			i;

	new_s = s;
	src = c;
	i = 0;
	while (i < n)
	{
		*new_s = src;
		new_s++;
		i++;
	}
	return (s);
}
