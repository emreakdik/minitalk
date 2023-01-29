/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:51:15 by yakdik            #+#    #+#             */
/*   Updated: 2023/01/29 19:51:34 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_char(pid_t pid, char c)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(200);
        i--;
    }
}

int main(int argc, char **argv)
{
    pid_t pid;
    int i;

    if (argc != 3)
        write(1, "Error: wrong number of arguments\n", 33);
    else
    {
        pid = ft_atoi(argv[1]);
        i = 0;
        while (argv[2][i])
        {
            send_char(pid, argv[2][i]);
            i++;
        }
    }
}
