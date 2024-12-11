/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:12:32 by djoung            #+#    #+#             */
/*   Updated: 2024/10/11 17:53:52 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*new_dest;
	const unsigned char	*new_src;

	if (!src && !dest)
		return (NULL);
	new_dest = (unsigned char *)dest;
	new_src = (const unsigned char *)src;
	if (new_dest < new_src)
	{
		while (n--)
			*new_dest++ = *new_src++;
	}
	else
	{
		while (n > 0)
		{
			n--;
			new_dest[n] = new_src[n];
		}
	}
	return (dest);
}
