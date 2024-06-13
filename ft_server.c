/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:38:04 by nfararan          #+#    #+#             */
/*   Updated: 2024/06/13 17:27:14 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void	mt_server(int sig)
{
	static char	*str = NULL;
	static char	c = 0;
	static int	byte_len = 0;

	if (byte_len == 8)
		c = 0;
	if (sig == SIGUSR2)
		c |= 1;
	if (byte_len > 1)
		c <<= 1;
	byte_len--;
	if (byte_len == 0)
	{
		byte_len = 8;
		if (c == 0)
		{
			// print the message
			return ;
		}
		// join character into str
	}
}

static void	mt_handle_interrupt(int sig)
{
	(void)sig;
	mt_puts("\n[Program interrupted]\n");
	exit(0);
}

int	main(void)
{
	mt_putnbr((int)getpid());
	signal(SIGUSR1, &mt_server);
	signal(SIGUSR2, &mt_server);
	signal(SIGINT, &mt_handle_interrupt);
	while (1)
	{
	}
}
