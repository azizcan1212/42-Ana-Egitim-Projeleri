#include <unistd.h>
#include <signal.h>
#include <sys/types.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putunbr(pid_t nb)
{
	if(nb < 0)
        write(1,"Pid negatif olamaz",18);
	else if (nb > 9)
	{
		ft_putunbr(nb / 10);
		ft_putunbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

static void	signal_handler(int signal)
{
	static char	chr = 0;
	static int	i = 0;

	i++;
	if (signal == SIGUSR1)
		chr = chr | 1;
	if (i == 8)
	{
		write(1, &chr, 1);
		i = 0;
		chr = 0;
	}
	chr = chr << 1;
}
int	main(void)
{
	pid_t	server_id;

	server_id = getpid();
	ft_putunbr(server_id);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}