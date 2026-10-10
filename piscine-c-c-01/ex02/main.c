/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:56:04 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/08 14:00:09 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	num1;
	int	num2;

	num1 = 42;
	num2 = 24;
	printf("Before: a = %d, b = %d\n", num1, num2);
	ft_swap(&num1, &num2);
	printf("After:  a = %d, b = %d\n", num1, num2);
	return (0);
}
