/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyumaz <yuyumaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 03:58:24 by yuyumaz           #+#    #+#             */
/*   Updated: 2025/06/18 13:07:36 by yuyumaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	word_count(char const *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s)
				s++;
			count++;
		}
	}
	return (count);
}

static int	safe_alloc(char **lst, int pos, size_t buf_sz)
{
	int	i;

	i = 0;
	*(lst + pos) = (char *) malloc(buf_sz);
	if (*(lst + pos) == NULL)
	{
		while (i < pos)
		{
			free(*(lst + i));
			i++;
		}
		free(lst);
		return (1);
	}
	return (0);
}

static int	fill_word(char **lst, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_alloc(lst, i, (len + 1)))
				return (1);
			ft_strlcpy(*(lst + i), (s - len), (len + 1));
		}
		i++;
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char			**res;
	unsigned int	words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	res = (char **) malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	*(res + words) = NULL;
	if (fill_word(res, s, c))
		return (NULL);
	return (res);
}
