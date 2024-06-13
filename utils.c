/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:05:53 by nfararan          #+#    #+#             */
/*   Updated: 2024/06/13 17:05:09 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <unistd.h>

void	mt_putc(char c)
{
	write(1, &c, 1);
}

void	mt_putnbr(int n)
{
	if (n < 0)
	{
		mt_putc('-');
		mt_putnbr(-n);
	}
	else if (n > 9)
	{
		mt_putnbr(n / 10);
		mt_putnbr(n % 10);
	}
	else
		mt_putc(n + '0');
}

size_t	mt_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	mt_puts(const char *s)
{
	write(1, s, mt_strlen(s));
}

int	mt_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}
