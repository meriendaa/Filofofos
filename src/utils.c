#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 75)
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if (c == '\v' || c == '\n' || c == '\r' || c == '\f'
		|| c == '\t' || c == ' ')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	long long		num;
	int				sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str++ - '0');
		if (num < INT_MIN && sign == -1)
			return (0);
		if (num > INT_MAX && sign == 1)
			return (0);
	}
	return (sign * num);
}

long long int	get_time(void)
{
	struct timeval	i;

	gettimeofday(&i, NULL);
	return ((i.tv_sec * 1000) + (i.tv_usec / 1000));
}
