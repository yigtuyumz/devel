/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyumaz <yuyumaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:58:00 by yuyumaz           #+#    #+#             */
/*   Updated: 2025/06/18 13:14:09 by yuyumaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char *) big);
	i = 0;
	while (i < len && *(big + i))
	{
		j = 0;
		while (i + j < len && *(little + j) && *(little + j) == *(big + i + j))
			j++;
		if (*(little + j) == 0)
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
