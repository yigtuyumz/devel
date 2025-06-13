/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyumaz <yuyumaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:40:22 by yuyumaz           #+#    #+#             */
/*   Updated: 2025/06/13 00:40:47 by yuyumaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*ret;

	str_len = ft_strlen(s);
	ret = (char *) malloc(sizeof(char) * (str_len + 1));
	if (!ret)
		return (NULL);
	return (ft_memcpy(ret, s, str_len + 1));
}
