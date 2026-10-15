/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:17:52 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/14 17:19:29 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Preprocessor

#include <stdio.h>

// Prototype

int	ft_strlen(char *str);

// Function - Test

void	run_test(char *str, int test_num)
{
	int	result;

	result = ft_strlen(str);
	printf("Test %d | String: \"%s\"\n", test_num, str);
	printf("  Calculated Length: %d\n\n", result);
}

// Function - Main

int	main(void)
{
	// Test 1: Standard normal string
	run_test("Hello World", 1);
	// Test 2: Empty string (Length should be 0)
	run_test("", 2);
	// Test 3: String with numbers and special characters
	run_test("42 Berlin #1!", 3);
	// Test 4: Single character string
	run_test("A", 4);
	// Test 5: String containing spaces only
	run_test("    ", 5);
	return (0);
}
