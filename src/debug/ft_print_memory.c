/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyumaz <yuyumaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:30:03 by yuyumaz           #+#    #+#             */
/*   Updated: 2025/05/31 13:43:47 by yuyumaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_puthexa(unsigned long int nb, unsigned char addrlen)
{
	unsigned char	temp;
	unsigned char	iterator;

	iterator = 0x00;
	while (iterator++ < addrlen)
	{
		temp = ((nb >> ((addrlen * 0x08) - (iterator * 0x08))) & 0xF0) >> 0x04;
		if (temp >= 0x0A)
			temp = 0x61 + (temp % 0x0A);
		else
			temp += 0x30;
		write(STDOUT_FILENO, &temp, 0x01);
		temp = (nb >> ((addrlen * 0x08) - (iterator * 0x08))) & 0x0F;
		if (temp >= 0x0A)
			temp = 0x61 + (temp % 0x0A);
		else
			temp += 0x30;
		write(STDOUT_FILENO, &temp, 0x01);
	}
	if (addrlen == 0x08)
		write(STDOUT_FILENO, ":", 0x01);
}

static void	ft_putascii(char c)
{
	if (c >= 0x20 && c <= 0x7E)
		write(STDOUT_FILENO, &c, 0x01);
	else
		write(STDOUT_FILENO, ".", 0x01);
}

static void	ft_hexaloop(void *addr, unsigned int *iter, unsigned int size)
{
	unsigned int	iternext;

	iternext = *iter + 0x10;
	while (*iter < iternext)
	{
		if (*iter % 0x02 == 0x00)
			write(0x01, " ", 0x01);
		if (*iter < size)
			ft_puthexa(((char *) addr)[*iter], 0x01);
		else
			write(STDOUT_FILENO, "  ", 0x02);
		*iter += 0x01;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	iter;
	unsigned int	iternext;

	if (!addr)
		return ((void *) 0x00);
	iter = 0x00;
	while (iter < size)
	{
		iternext = iter + 0x10;
		if (iter % 0x10 == 0x00)
		{
			ft_puthexa((unsigned long int) &((char *) addr)[iter], 0x08);
			ft_hexaloop(addr, &iter, size);
			write(STDOUT_FILENO, " ", 0x01);
			iter -= 0x10;
			while ((iter < iternext) && (iter < size))
				ft_putascii(((char *) addr)[iter++]);
			write(STDOUT_FILENO, "\n", 0x01);
		}
	}
	return (addr);
}
