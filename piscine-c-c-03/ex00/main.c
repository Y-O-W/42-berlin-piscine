/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:15:51 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/13 12:25:52 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

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

void	ft_print_test(char *s1, char *s2)
{
	int	res;

	res = ft_strcmp(s1, s2);
	ft_putstr("s1: \"");
	ft_putstr(s1);
	ft_putstr("\" | s2: \"");
	ft_putstr(s2);
	ft_putstr("\" -> Result: ");
	ft_putnbr(res);
	ft_putstr("\n");
}

int	main(void)
{
	printf("Test 1: Exactly identical strings");
	ft_print_test("Hello", "Hello");
	printf("Test 2: s1 is shorter than s2");
	ft_print_test("Hello", "Hello World");
	printf("Test 3: s1 is longer than s2");
	ft_print_test("Hello World", "Hello");
	printf("Test 4: First string is empty");
	ft_print_test("", "42");
	printf("Test 5: Character value differences (s1 > s2)");
	ft_print_test("abcde", "abCde");
	printf("Test 6: Character value differences (s1 < s2)");
	ft_print_test("abCde", "abcde");
	return (0);
}
