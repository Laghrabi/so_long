#include "ft_printf.h"

void    op(t_op (*arr)[10])
{
    (*arr)[0].format = 'c';
    (*arr)[0].f = ft_putchar;
    (*arr)[1].format = 's';
    (*arr)[1].f = ft_putstr;
    (*arr)[2].format = 'i';
    (*arr)[2].f = ft_putnbr;
    (*arr)[3].format = 'd';
    (*arr)[3].f = ft_putnbr;
    (*arr)[4].format = '%';
    (*arr)[4].f = mod;
    (*arr)[5].format = 'x';
    (*arr)[5].f = put_x;
    (*arr)[6].format = 'X';
    (*arr)[6].f = put_X;
    (*arr)[7].format = 'p';
    (*arr)[7].f = put_p;
    (*arr)[8].format = 'u';
    (*arr)[8].f = put_u;
    (*arr)[9].format = '\0';
    (*arr)[9].f = NULL;
}
int which_opr(t_op arr[10], char format, va_list arg)
{
    int i;

    i = 0;
    while (arr[i].format)
    {
        if (format == arr[i].format)
            return (arr[i].f(arg));
        i++;
    }
    return (0);
}
