/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:51:21 by yakdik            #+#    #+#             */
/*   Updated: 2023/01/29 19:51:36 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	put_bin(char *str)
{
	int		base;
	char	res;
	int		i;

	base = 128;
	res = 0;
	i = 0;
	while (str[i] != '\0' && base != 0)
	{
		if (str[i] == '1')
		{
			res += base;
			base /= 2;
		}
		else
			base /= 2;
		i++;
	}
	ft_putchar_fd(res, 1);
}

static void	sighandler(int signal)
{
	static int	byte;
	static char	*binary;

	if (binary == NULL)
	{
		binary = ft_strdup("");
		byte = 0;
	}
	if (signal == SIGUSR1)
		binary = ft_strjoin(binary, "0");
	else
		binary = ft_strjoin(binary, "1");
	if (++byte == 8)
	{
		put_bin(binary);
		free(binary);
		binary = NULL;
		byte = 0;
	}
}

int main(int argc, char **argv)
{
    pid_t pid;
    
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
    pid = getpid();
    ft_putnbr_fd(pid,1);
    write(1, "\n", 1);

    while(1)
        pause();
}
