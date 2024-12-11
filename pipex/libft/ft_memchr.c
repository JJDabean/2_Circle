/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:14:13 by djoung            #+#    #+#             */
/*   Updated: 2024/10/05 19:40:23 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*new_s;
	size_t				i;

	new_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == (unsigned char)c)
			return ((void *)new_s + i);
		i++;
	}
	return (NULL);
}
