/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:56:00 by sibrahim          #+#    #+#             */
/*   Updated: 2023/03/21 09:56:01 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	sig_handler(int sig, siginfo_t *sig_info, void *context)
{
	static int		bit_count = 0;
	static char		curr_char = 0;
	static pid_t	client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = sig_info->si_pid;
	if (sig == SIGUSR1)
		curr_char |= (0 << bit_count);
	else
		curr_char |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		bit_count = 0;
		if (!curr_char)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_printf("%c", curr_char);
		curr_char = 0;
		kill(client_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
