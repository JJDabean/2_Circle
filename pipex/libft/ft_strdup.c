/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:24:23 by djoung            #+#    #+#             */
/*   Updated: 2024/10/11 17:00:31 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*cpy_src;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	cpy_src = (char *)malloc(src_len + 1 * sizeof(char));
	if (!(cpy_src))
		return (0);
	while (src[i])
	{
		cpy_src[i] = src[i];
		i++;
	}
	cpy_src[i] = '\0';
	return (cpy_src);
}
