#include "corewar.h"

t_cpu	*ft_zjmp(t_mars **mars, t_cpu *cpu)
{
 int	address;

 address = (*mars)->arena[(cpu->pc + 1) % MEM_SIZE];
 address <<= 8;
 address += (*mars)->arena[(cpu->pc + 2) % MEM_SIZE];
 if (address >> 15)
   address -= 0x10000;
 (*mars)->modif = true;
 cpu->pc += cpu->carry ? address % IDX_MOD : 3;
 return (cpu);
}
