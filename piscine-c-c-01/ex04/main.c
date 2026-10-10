/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:06:23 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/08 15:10:02 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	num1;
	int	num2;

	num1 = 187;
	num2 = 13;
	printf("Before: a = %d, b = %d\n", num1, num2);
	ft_ultimate_div_mod(&num1, &num2);
	printf("After:  a = %d, b = %d\n", num1, num2);
	return (0);
}
