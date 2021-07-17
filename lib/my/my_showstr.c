/*
** EPITECH PROJECT, 2020
** shostr
** File description:
** sagz
*/

void my_putchar(char c);
int my_strlen(char *str);
int my_putnbr_base(int nbr, char *base);

void special_put(char c)
{
    my_putchar('\\');
    if (c <= 15)
        my_putchar('0');
    my_putnbr_base((int)c, "0123456789ABCDEF");
}

int my_putnbr_base(int nbr, char *base)
{
    int unit;
    int bas = my_strlen(base);
    int count = 1;

    if (nbr == 0)
        return (0);
    if (nbr < 0) {
        count = -1;
        my_putchar('-');
    }
    nbr = nbr * count;
    unit = nbr % bas;
    my_putnbr_base(nbr / bas, base);
    my_putchar(base[unit]);
    return (0);
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127)
            special_put(str[i]);
        else
            my_putchar(str[i]);
    }
    return (0);
}
