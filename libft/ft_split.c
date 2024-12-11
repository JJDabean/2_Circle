/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:51:28 by djoung            #+#    #+#             */
/*   Updated: 2024/10/13 19:20:57 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

char	*inner_sp(char *s, char c)
{
	char	*inner_sp;
	int		s_len;
	int		i;

	s_len = 0;
	i = 0;
	while (s[s_len] && s[s_len] != c)
		s_len++;
	inner_sp = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!inner_sp)
		return (NULL);
	while (i < s_len)
	{
		inner_sp[i] = s[i];
		i++;
	}
	inner_sp[i] = '\0';
	return (inner_sp);
}

void	ft_fill_str(char **sp_str, char *s, char c)
{
	int	i;
	int	sp;

	i = 0;
	sp = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			sp_str[sp] = inner_sp(&s[i], c);
			if (!sp_str[sp])
			{
				while (sp > 0)
					free(sp_str[--sp]);
				free(sp_str);
				return ;
			}
			sp++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	sp_str[sp] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**sp_str;

	sp_str = (char **)malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (!sp_str)
		return (NULL);
	ft_fill_str(sp_str, (char *)s, c);
	return (sp_str);
}
