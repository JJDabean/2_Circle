/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:18:14 by djoung            #+#    #+#             */
/*   Updated: 2024/10/13 19:21:14 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	new_len;

	if (!s1 || !s2)
		return (NULL);
	new_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(sizeof(char) * new_len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, new_len);
	ft_strlcat(new_str, s2, new_len);
	return (new_str);
}
