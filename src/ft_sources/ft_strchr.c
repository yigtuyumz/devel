/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyumaz <yuyumaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:23:17 by yuyumaz           #+#    #+#             */
/*   Updated: 2025/06/18 12:27:17 by yuyumaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*d;

	d = (const unsigned char *) s;
	while (*d)
	{
		if (*d == (unsigned char) c)
			return ((char *) d);
		d++;
	}
	if ((unsigned char) c == 0)
		return ((char *) d);
	return ((char *) 0);
}
