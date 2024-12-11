/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:49:46 by djoung            #+#    #+#             */
/*   Updated: 2024/10/11 16:23:10 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*carray;

	carray = (void *)malloc(nmemb * size);
	if (!carray)
		return (NULL);
	ft_bzero(carray, (nmemb * size));
	return (carray);
}
