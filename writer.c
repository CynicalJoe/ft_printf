#include "ft_printf.h"

t_flags *writer(t_flags *param)
{
    while (param->print[param->len])
    {
        write(1, &param->print[param->len], 1);
        param->len++;
    }
    if (param->is_term)
    {
       write(1, '\0', 1);
       param->len++;
       return (param);
    }
    return (param);
}