/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyumaz <yuyumaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:58:57 by yuyumaz           #+#    #+#             */
/*   Updated: 2025/06/18 13:06:24 by yuyumaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1)
		*(ret + i++) = *(s1++);
	while (*s2)
		*(ret + i++) = *(s2++);
	*(ret + i) = 0;
	return (ret);
}
