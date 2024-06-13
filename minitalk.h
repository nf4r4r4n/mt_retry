/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:10:14 by nfararan          #+#    #+#             */
/*   Updated: 2024/06/13 17:18:37 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void	mt_putc(char c);
void	mt_putnbr(int n);
size_t	mt_strlen(const char *s);
void	mt_puts(const char *s);
int		mt_isdigit(char c);
int		mt_atoi(const char *n);
void	mt_send_char(int pid, int c);

#endif