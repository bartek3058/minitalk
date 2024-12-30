/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:46:06 by brogalsk          #+#    #+#             */
/*   Updated: 2024/12/30 08:05:50 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_handler(int sig)
{
	static int	bit;
	static int	i;
	int			bit_position;

	bit_position = 0;
	if (sig == SIGUSR1)
	{
		bit_position = (1 << bit);
		i |= bit_position;
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, error_handler);
		signal(SIGUSR2, error_handler);
		pause();
	}
	return (0);
}
