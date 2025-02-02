#include "ft_printf.h"

int ft_putstr(va_list arg)
{
    char *str;

    str = va_arg(arg, char *);
    if (!str)
        return (write(1, "(null)", 6));
    return (write(1, str, ft_strlen(str)));
}
int mod(va_list arg)
{
    (void)arg;
    return (write(1, "%", 1));
}

int ft_putnbr(va_list arg)
{
    int     written;
    char    *ascii;

    ascii = ft_itoa(va_arg(arg, int));
    written = write(1, ascii, ft_strlen(ascii));
    if (ascii)
        free(ascii);
    return (written);
}

int ft_putchar(va_list arg)
{
    char c;
    
    c = va_arg(arg, int);
    return (write(1, &c, 1));
}