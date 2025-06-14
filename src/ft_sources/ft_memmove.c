/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyumaz <yuyumaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:01:01 by yuyumaz           #+#    #+#             */
/*   Updated: 2025/06/12 18:21:45 by yuyumaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isoverlap(void *a, void *b, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				diff;

	p1 = (const unsigned char *) a;
	p2 = (const unsigned char *) b;
	if (p1 > p2)
		diff = p1 - p2;
	else
		diff = p2 - p1;
	return (diff < n);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (d == s || n == 0)
		return (dest);
	if (!ft_isoverlap(dest, (void *) src, n))
		return (ft_memcpy(dest, src, n));
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
