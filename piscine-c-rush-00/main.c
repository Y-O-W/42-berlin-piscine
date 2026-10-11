/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowfactor <yowfactor@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:09:43 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/11 12:11:55 by yowfactor        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y);

int	main(void)
{
	rush(5, 3);
	ft_putchar('\n');
	rush(5, 1);
	ft_putchar('\n');
	rush(1, 1);
	ft_putchar('\n');
	rush(1, 5);
	ft_putchar('\n');
	rush(4, 4);
	ft_putchar('\n');
	rush(123, 42);
	ft_putchar('\n');
	rush(0, 3);
	ft_putchar('\n');
	rush(3, 0);
	ft_putchar('\n');
	rush(-2, -2);
	ft_putchar('\n');
	return (0);
}
