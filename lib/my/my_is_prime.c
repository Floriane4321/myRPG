/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** prim
*/

int my_compute_square_root(int);

int my_is_prime(int nb)
{
    if (nb < 2)
        return (0);
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
