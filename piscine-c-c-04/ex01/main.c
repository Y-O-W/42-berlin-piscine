/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:57:02 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/15 12:02:55 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr(char *str);

int	main(void)
{
	printf("--- Test 1: Standard String ---\n");
	printf("Expected: [Hello 42 Berlin!]\n");
	printf("Output  : [");
	fflush(stdout);
	ft_putstr("Hello 42 Berlin!");
	printf("]\n\n");
	printf("--- Test 2: Empty String ---\n");
	printf("Expected: []\n");
	printf("Output  : [");
	fflush(stdout);
	ft_putstr("");
	printf("]\n\n");
	printf("--- Test 3: Newlines & Tabs ---\n");
	printf("Expected: [Line1\n\tLine2]\n");
	printf("Output  : [");
	fflush(stdout);
	ft_putstr("Line1\n\tLine2");
	printf("]\n");
	return (0);
}
