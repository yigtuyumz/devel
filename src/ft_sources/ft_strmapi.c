/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyumaz <yuyumaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:40:54 by yuyumaz           #+#    #+#             */
/*   Updated: 2025/06/18 13:06:39 by yuyumaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(ret + i) = f(i, *(s + i));
		i++;
	}
	*(ret + i) = 0;
	return (ret);
}
