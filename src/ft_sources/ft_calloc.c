/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyumaz <yuyumaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:43:18 by yuyumaz           #+#    #+#             */
/*   Updated: 2025/06/18 13:04:36 by yuyumaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if ((size != 0 && nmemb > ((size_t) -1) / size))
		return (NULL);
	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	return (ft_memset(ret, 0, (nmemb * size)));
}
