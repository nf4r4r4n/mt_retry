/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:07:40 by nfararan          #+#    #+#             */
/*   Updated: 2024/06/13 17:18:13 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	mt_atoi(const char *n)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (n[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (n[i] == '+')
		i++;
	while (n[i] && mt_isdigit(n[i]))
	{
		result = result * 10 + (n[i] - '0');
		i++;
	}
	return (result * sign);
}

void	mt_send_char(int pid, int c)
{
	int	mask;
	int	byte_flag;

	mask = 0b10000000;
	byte_flag = 8;
	while (byte_flag)
	{
		if (c & mask)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		byte_flag--;
		mask >>= 1;
	}
}
