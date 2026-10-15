/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:34:17 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/14 13:35:36 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Preprocessor0

#include <stdio.h>

// Prototype

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

// Function - Helper - Test

void	run_custom_test(const char *init, char *src, unsigned int size, int test_num)
{
	char			dest_buffer[50];
	unsigned int	i;
	unsigned int	result;

	// Fill buffer with placeholders to track overflow safely
	i = 0;
	while (i < 50)
	{
		dest_buffer[i] = 'X';
		i++;
	}
	// Copy initial string into buffer
	i = 0;
	while (init[i] != '\0')
	{
		dest_buffer[i] = init[i];
		i++;
	}
	dest_buffer[i] = '\0';

	// Run your custom function
	result = ft_strlcat(dest_buffer, src, size);

	// Output results
	printf("Test %d | Size Cap: %u\n", test_num, size);
	printf("  Return Value: %u\n", result);
	printf("  Buffer State: \"%s\"\n\n", dest_buffer);
}

// Function - Main

int	main(void)
{
	// Test 1: Normal operations (Plenty of space to copy everything)
	run_custom_test("Hello ", "World", 20, 1);
	// Test 2: Buffer size too small (Bypass copy completely)
	run_custom_test("Hello ", "World", 3, 2);
	// Test 3: Buffer exactly matches destination length (No room to append)
	run_custom_test("Hello ", "World", 6, 3);
	// Test 4: Truncation check (Appends partially, leaves room for null-terminator)
	run_custom_test("Hello ", "World", 9, 4);
	// Test 5: Size is exactly 0
	run_custom_test("Hello ", "World", 0, 5);
	// Test 6: Empty source string
	run_custom_test("Hello ", "", 20, 6);
	return (0);
}
