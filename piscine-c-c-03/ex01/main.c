/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:13:20 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/13 14:26:25 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_strncmp_test(char *s1, char *s2, unsigned int n)
{
	int	res;

	res = ft_strncmp(s1, s2, n);
	ft_putstr("s1: \"");
	ft_putstr(s1);
	ft_putstr("\" | s2: \"");
	ft_putstr(s2);
	ft_putstr("\" | n: ");
	ft_putnbr(n);
	ft_putstr(" -> Result: ");
	ft_putnbr(res);
	ft_putstr("\n");
}

int	main(void)
{
	ft_print_strncmp_test("abcdef", "abcXYZ", 3);
	ft_print_strncmp_test("abcdef", "abcXYZ", 4);
	ft_print_strncmp_test("Hello", "Hello", 10);
	ft_print_strncmp_test("42Berlin", "42Network", 0);
	ft_print_strncmp_test("test", "text", 3);
	return (0);
}
