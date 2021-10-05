/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:18:03 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/30 21:18:03 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"

static void	handle_msg(int pid, unsigned char num);
static void	end(int sig);

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
		herror("Invalid arguments.");
	pid = atoi(av[1]);
	if (pid < 0)
		herror("Invalid pid.");
	ft_printf("Sending...\n");
	signal(SIGUSR1, end);
	while (*av[2])
	{
		handle_msg(pid, *av[2]);
		av[2]++;
	}
	handle_msg(pid, 0);
}

static void	handle_msg(int pid, unsigned char num)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		if (num % 2 == 0 || num == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		num /= 2;
	}
}

static void	end(int sig)
{
	(void)sig;
	ft_printf("\n--Sent.\n");
	exit(0);
}
