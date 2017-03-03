#include "corewar.h"

long long int		ft_get_sti_arg(t_mars *mars, t_cpu *cpu, int type, int *n)
{
 long long int	arg;

 if (type == 1)
   return (mars->arena[(cpu->pc + (*n)++) % MEM_SIZE] - 1);
 else if (type == 2)
 {
   arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
   arg <<= 8;
   arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
   if (arg >> 15)
     arg -= 0x10000;
   return (arg);
 }
 arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
 arg <<= 8;
 arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE] + cpu->pc;
 return (mars->arena[(cpu->pc + arg % IDX_MOD) % MEM_SIZE]);
}

void	ft_abs_mars_color(t_mars **mars)
{
 int	i;

 i = 0;
 while (i < 4096)
 {
   if ((*mars)->arena_color[i] < 0)
     (*mars)->arena_color[i] = (*mars)->arena_color[i] < -4
     ? (*mars)->arena_color[i] + 5 : ft_abs((*mars)->arena_color[i]);
   i++;
 }
}

void	ft_print_on_mars(t_mars **pmars, unsigned int value, int address, int uid)
{
 t_mars	*mars;

 mars = *pmars;
 if (mars->opt & 1 || mars->opt & 2)
   ft_abs_mars_color(pmars);
 if (address < 0)
   address = MEM_SIZE + address;
 mars->arena[address % MEM_SIZE] = value >> 24;
 mars->arena_color[address++ % MEM_SIZE] = uid * -1 - 500;
 if (address < 0)
   address = MEM_SIZE + address;
 mars->arena[address % MEM_SIZE] = value >> 16 & 0xff;
 mars->arena_color[address++ % MEM_SIZE] = uid * -1 - 500;
 if (address < 0)
   address = MEM_SIZE + address;
 mars->arena[address % MEM_SIZE] = value >> 8 & 0xff;
 mars->arena_color[address++ % MEM_SIZE] = uid * -1 - 500;
 if (address < 0)
   address = MEM_SIZE + address;
 mars->arena[address % MEM_SIZE] = value & 0xff;
 mars->arena_color[address % MEM_SIZE] = uid * -1 - 500;
}

int	ft_check_type(unsigned char type, char a1, char a2, char a3)
{
 if ((!(a1 & 0b100) && type >> 6 == 1)
 || (!(a1 & 0b010) && type >> 6 == 2)
 || (!(a1 & 0b001) && type >> 6 == 3))
   return (0);
 else if ((!(a2 & 0b100) && (type >> 4 & 0b11) == 1)
 || (!(a2 & 0b010) && (type >> 4 & 0b11) == 2)
 || (!(a2 & 0b001) && (type >> 4 & 0b11) == 3))
   return (0);
 else if ((!(a3 & 0b100) && (type >> 2 & 0b11) == 1)
 || (!(a3 & 0b010) && (type >> 2 & 0b11) == 2)
 || (!(a3 & 0b001) && (type >> 2 & 0b11) == 3))
   return (0);
 return (1);
}

t_cpu	*ft_sti(t_mars **mars, t_cpu *cpu)
{
 long long int	arg1;
 long long int	arg2;
 long long int	arg3;
 unsigned char	type;
 int		n;

 (*mars)->modif = true;
 type = (*mars)->arena[++cpu->pc % MEM_SIZE];
 if ((n = 1) && !ft_check_type(type, 0b100, 0b111, 0b110))
   return (cpu);
 arg1 = ft_get_sti_arg(*mars, cpu, 1, &n);
 arg2 = ft_get_sti_arg(*mars, cpu, type >> 4 & 0b11, &n);
 arg3 = ft_get_sti_arg(*mars, cpu, type >> 2 & 0b11, &n);
 if (arg1 > 15 || ((type >> 4 & 0b11) == 1 && arg2 > 15)
 || ((type >> 2 & 0b11) == 1 && arg3 > 15))
   return (cpu);
 arg1 = cpu->reg[arg1];
 if ((type >> 4 & 0b11) == 1)
   arg2 = cpu->reg[arg2];
 if ((type >> 2 & 0b11) == 1)
   arg3 = cpu->reg[arg3];
 ft_print_on_mars(mars, arg1, (cpu->pc - 1) + (arg2 + arg3)
 % IDX_MOD, cpu->color);
 cpu->pc += n;
 return (cpu);
}
