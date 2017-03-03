#include "corewar.h"

t_cpu	*ft_new_cpucpy(t_cpu *src, int address)
{
	t_cpu	*cpu;
	int		i;

	cpu = (t_cpu*)ft_memalloc(sizeof(t_cpu));
	cpu->next = NULL;
	cpu->live = src->live;
	cpu->pc = address;
	cpu->carry = src->carry;
	cpu->color = src->color;
	cpu->uid = src->uid;
	cpu->cycle_wait = 0;
	cpu->code = NULL;
	cpu->name[0] = 0;
	ft_strcpy(cpu->name, src->name);
	cpu->comment[0] = 0;
	ft_strcpy(cpu->comment, src->comment);
	i = -1;
	while (++i < 16)
		cpu->reg[i] = src->reg[i];
	return (cpu);
}

void	ft_cpu_cpyfront(t_cpu **cpu, t_cpu *src, int address)
{
	t_cpu *lst;

	lst = ft_new_cpucpy(src, address);
	lst->next = *cpu;
	*cpu = lst;
}

t_cpu	*ft_fork(t_mars **mars, t_cpu *cpu, int *new_address, int mod)
{
 int	address;

 address = (*mars)->arena[(cpu->pc + 1) % MEM_SIZE];
 address <<= 8;
 address += (*mars)->arena[(cpu->pc + 2) % MEM_SIZE];
 if (address >> 15)
   address -= 0x10000;
 (*mars)->modif = true;
 cpu->pc += 3;
 *new_address = address - 3;
 if (mod == 0x0c)
   *new_address %= IDX_MOD;
 return (cpu);
}
