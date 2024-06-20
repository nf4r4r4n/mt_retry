/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:07:40 by nfararan          #+#    #+#             */
/*   Updated: 2024/06/20 18:44:52 by nfararan         ###   ########.fr       */
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

int	mt_send_char(int pid, int c)
{
	int	mask;
	int	byte_flag;

	mask = 0b10000000;
	byte_flag = 8;
	while (byte_flag)
	{
		if (c & mask)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		usleep(100);
		byte_flag--;
		mask >>= 1;
	}
	return (1);
}

char	*mt_strappend(char *str, char c)
{
	char	*append;
	int		i;
	int		j;

	if (!str)
		append = (char *)malloc(sizeof(char) * 2);
	else
		append = (char *)malloc(sizeof(char) * (mt_strlen(str) + 2));
	if (!append)
	{
		if (str)
			return (str);
		return (NULL);
	}
	i = -1;
	j = 0;
	while (str[++i])
		append[j++] = str[i];
	if (str)
		free(str);
	append[j++] = c;
	append[j] = 0;
	return (append);
}
