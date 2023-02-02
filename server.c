/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:51:21 by yakdik            #+#    #+#             */
/*   Updated: 2023/02/02 13:42:16 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	signal_process(int signal)
{
	static unsigned char	x;
	static int				i;

	if (signal == SIGUSR1)
		x = x | 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", x);
		i = 0;
		x = 0;
	}
	x = x << 1;
}

int	main(void)
{
	ft_printf("Server started with PID: %d\n", getpid());
	signal (SIGUSR1, signal_process);
	signal (SIGUSR2, signal_process);
	while (1)
		pause();
	return (0);
}
