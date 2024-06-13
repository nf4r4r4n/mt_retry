/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:37:39 by nfararan          #+#    #+#             */
/*   Updated: 2024/06/13 17:20:06 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	mt_handle_args(int argc, char **argv)
{
	int	i;

	if (argc != 3 || mt_strlen(argv[2]) == 0)
	{
		mt_puts("Usage: ./client <pid> <msg>\n");
		exit(1);
	}
	i = 0;
	while (argv[1][i])
		if (!mt_isdigit(argv[1][i++]))
		{
			mt_puts("Usage: ./client <pid> <msg>\n");
			exit(1);
		}
}

static void	mt_client(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		mt_send_char(pid, msg[i++]);
	mt_send_char(pid, 0);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	mt_handle_args(argc, argv);
	pid = mt_atoi(argv[1]);
	msg = argv[2];
	mt_client(pid, msg);
}
