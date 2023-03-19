#include <signal.h>
#include "libft/libft.h"

static void	bytes_received(int sig)
{
	static int	bytes = 0;

	if (sig == SIGUSR1)
	bytes++;
	else
	{
		ft_printf("String received. (%d bytes)", bytes);
		exit(0);
	}
}

static void	end_message(pid_t s_pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		kill(s_pid, SIGUSR1);
		usleep(100);
		j++;
	}
}

static void	send_string(char *str, pid_t server_pid)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	bit = 0;
	while (i < (int)(ft_strlen(str)))
	{
		j = 0;
		while (j < 8)
		{
			bit = (str[i] >> j) & 1;
			if (!bit)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(100);
			j++;
		}
		i++;
	}
	end_message(server_pid);
}

int	main(int argc, char **argv)
{
	if (argc == 3 && ft_strlen(argv[2]) > 0)
	{
		signal(SIGUSR1, bytes_received);
		signal(SIGUSR2, bytes_received);
		send_string(argv[2], ft_atoi(argv[1]));
	}
	else
		ft_printf("Error\n");
	while (1)
		pause();
	return (0);
}
