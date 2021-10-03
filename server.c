/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:04:21 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/09/16 16:04:21 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"

static void	handler(int signo, siginfo_t *info, void *context);
void		herror(char *msg);

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				pid;

	if (ac == 1)
	{
		pid = getpid();
		ft_printf("PID: %d\n", pid);
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
		return (0);
	}
	else
		herror("Usage invalid.");
}

static void	handler(int signo, siginfo_t *info, void *context)
{
	static unsigned int	size;
	static unsigned int	byte;

	(void)context;
	if (signo == SIGUSR1)
		signo = 0;
	else
		signo = 1;
	byte += signo << size;
	size++;
	if (size == 8)
	{
		if (byte)
			ft_putchar_fd(byte, 1);
		else
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		byte = 0;
		size = 0;
	}
}

void	herror(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}
