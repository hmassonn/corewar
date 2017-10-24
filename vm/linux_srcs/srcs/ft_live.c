#include "corewar.h"

t_cpu	*ft_live(t_mars **mars, t_cpu *cpu)
{
 unsigned int	uid;
 int		i;

 uid = 0;
 uid |= (*mars)->arena[++cpu->pc % MEM_SIZE];
 uid <<= 8;
 uid |= (*mars)->arena[++cpu->pc % MEM_SIZE];
 uid <<= 8;
 uid |= (*mars)->arena[++cpu->pc % MEM_SIZE];
 uid <<= 8;
 uid |= (*mars)->arena[++cpu->pc % MEM_SIZE];
 ++cpu->pc;
 i = 0;
 while (i < 4)
 {
   if ((*mars)->players[i++] == uid)
   {
     if (!((*mars)->opt & 0b00100000))
       ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
     cpu->color, cpu->name);
     (*mars)->last_live = uid;
   }
 }
 (*mars)->modif = true;
 ++cpu->live;
 return (cpu);
}
