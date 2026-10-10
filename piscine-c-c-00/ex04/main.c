/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:07:56 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/07 16:25:50 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_is_negative(int n);
void	ft_putchar(char c);

int	main(void)
{
	ft_is_negative(-42);
	ft_putchar(' ');
	ft_is_negative(0);
	ft_putchar(' ');
	ft_is_negative(42);
	ft_putchar('\n');
	return (0);
}
