#include "ft_printf.h"

int put_x(va_list arg)
{
    char    *base;
    char    store[12];
    unsigned int    nbr;
    int     i;

    i = 0;
    base = "0123456789abcdef";
    nbr = va_arg(arg, unsigned int);
    if (nbr == 0)
        return (write(1, "0", 1));
    while (nbr > 0)
    {
        store[i] = base[nbr % 16];
        nbr /= 16;
        i++;
    }
    store[i] = '\0';
    return (print_reverse(store, i - 1));
}

int put_p(va_list arg)
{
    char    *base;
    char    store[16];
    unsigned long    nbr;
    int     i;
    int     count;

    i = 0;
    count = 0;
    base = "0123456789abcdef";
    nbr = va_arg(arg, unsigned long);
    if (nbr == 0)
        return (write(1, "(nil)", 5));
    while (nbr > 0)
    {
        store[i] = base[nbr % 16];
        nbr /= 16;
        i++;
    }
    store[i] = '\0';
    count += write(1, "0x", 2);
    count += print_reverse(store, i - 1);
    return (count);
}

int put_X(va_list arg)
{
    char    *base;
    char    store[12];
    unsigned int    nbr;
    int     i;

    i = 0;
    base = "0123456789ABCDEF";
    nbr = va_arg(arg, unsigned int);
    if (nbr == 0)
        return (write(1, "0", 1));
    while (nbr > 0)
    {
        store[i] = base[nbr % 16];
        nbr /= 16;
        i++;
    }
    store[i] = '\0';
    return (print_reverse(store, i - 1));
}
int put_u(va_list arg)
{
    int             i;
    unsigned int     nbr;
    char    store[12];

    nbr = va_arg(arg, unsigned int);
    i = 0;
    if (nbr == 0)
        return (write(1, "0", 1));
    while (nbr > 0)
    {
        store[i] = (nbr % 10) + '0';
        nbr /= 10;
        i++;
    }
    store[i] = '\0';
    return (print_reverse(store, i - 1));
}
