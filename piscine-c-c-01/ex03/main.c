/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:14:56 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/08 14:54:23 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	num1;
	int	num2;
	int	div;
	int	mod;

	num1 = 187;
	num2 = 13;
	div = 0;
	mod = 0;
	printf("Before: div = %d, mod = %d\n", div, mod);
	ft_div_mod(num1, num2, &div, &mod);
	printf("After:  div = %d, mod = %d\n", div, mod);
	return (0);
}
