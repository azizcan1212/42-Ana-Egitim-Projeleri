#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

static int	ft_atoi(const char *str)
{
	int	sign;
	int	count;
	int	result;

	count = 0;
	sign = 1;
	result = 0;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
		count ++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count ++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		result *= 10;
		result += str[count] - '0';
		count ++;
	}
	return (sign * result);
}

static void send_signal(pid_t id, char *str)
{
	int i ;
	int j ;

	i = 0;
	while(str[i])
	{
		j = 7;
		while(j >=0)
		{
			if((str[i] >> j) & 1)
				kill(id,SIGUSR1);
			else
				kill(id,SIGUSR2);
			usleep(150);
			j --;
		}
		i ++;
	}
}
int main(int argc, char *argv[])
{
	pid_t s_id;
	int i;

	if(argc == 3)
	{
		i = 0;
		while(argv[2][i])
		{
			if ((unsigned char)argv[2][i] > 127)
        	{
            	write(1, "Hata: Sadece ASCII karakterler desteklenir.\n", 44);
            	return 1;
        	}
			i++;
		}
		s_id = ft_atoi(argv[1]);
		send_signal(s_id,argv[2]);
	}

	else
		write(1,"Argüman sayisi hatali",22);

}