/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:38:04 by nfararan          #+#    #+#             */
/*   Updated: 2024/06/20 18:47:21 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

t_server g_server = (t_server){.msg = NULL, .c = 0, .byte_len = 0};

static void	mt_server(int sig)
{
	if (g_server.byte_len == 8)
		g_server.c = 0;
	if (sig == SIGUSR2)
		g_server.c |= 1;
	if (g_server.byte_len > 1)
		g_server.c <<= 1;
	g_server.byte_len--;
	if (g_server.byte_len == 0)
	{
		g_server.byte_len = 8;
		if (g_server.c == 0)
		{
			// print the message
			mt_puts(g_server.msg);
			mt_puts("\n");
			return ;
		}
		// join character into str
		g_server.msg = mt_strappend(g_server.msg, g_server.c);
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
	mt_puts("Server PID -> ");
	mt_putnbr((int)getpid());
	mt_puts("\n");
	signal(SIGUSR1, &mt_server);
	signal(SIGUSR2, &mt_server);
	signal(SIGINT, &mt_handle_interrupt);
	while (1)
	{
	}
}
