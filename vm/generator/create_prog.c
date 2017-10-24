#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int		ft_atoi_base(const char *str, int base)
{
	int i;
	int n;
	int neg;

	n = 0;
	neg = 0;
	i = 0;
	if (!str)
		return (0);
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F')))
	{
		n *= base;
		n += str[i] > '9' ? (int)str[i] - '7' : (int)str[i] - '0';
		i++;
	}
	return (neg == 1 ? -n : n);
}

int main(int ac, char **av)
{
	int	i;
	int	fd;
	char	c;

	fd = open("prog", O_RDWR | O_CREAT | O_TRUNC);
	i = 1;
	while (i < ac)
	{
		c = (char)ft_atoi_base(av[i++], 16);
		write(fd, &c, 1);
	}
	return (0);
	close(fd);
}
