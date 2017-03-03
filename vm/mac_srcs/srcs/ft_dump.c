#include "corewar.h"

void	ft_dump_memory(unsigned char *arena)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%02x%c", arena[i], j == 31 ? '\n' : ' ');
		i++;
		j == 31 ? j = 0 : j++;
	}
}
