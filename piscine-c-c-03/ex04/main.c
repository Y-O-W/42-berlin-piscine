/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:18:53 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/14 12:23:12 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Preprocessor */

#include <stdio.h>
#include <string.h>

/* Prototype */

char	*ft_strstr(char *str, char *to_find);

/* helper function test */

void	run_test(char *haystack, char *needle, int test_num)
{
	char	*sys_res;
	char	*ft_res;

	sys_res = strstr(haystack, needle);
	ft_res = ft_strstr(haystack, needle);
	printf("Test %d | Haystack: \"%s\" | Needle: \"%s\"\n", test_num, haystack, needle);
	printf("  Standard strstr: %s (Address: %p)\n", sys_res, (void *)sys_res);
	printf("  Your ft_strstr:  %s (Address: %p)\n", ft_res, (void *)ft_res);
	if (sys_res == ft_res)
		printf("  Result: SUCCESS\n\n");
	else
		printf("  Result: FAIL\n\n");
}

/* main function */

int	main(void)
{
	char	str1[] = "Forty Two is awesome";
	char	str2[] = "Hello World";
	char	str3[] = "banana";

	// Test 1: Substring exists in the middle
	run_test(str1, "Two", 1);
	// Test 2: Substring exists at the very beginning
	run_test(str1, "Forty", 2);
	// Test 3: Substring exists at the very end
	run_test(str1, "awesome", 3);
	// Test 4: Substring does not exist
	run_test(str2, "42", 4);
	// Test 5: Empty needle (Should return full haystack)
	run_test(str2, "", 5);
	// Test 6: Identical haystack and needle
	run_test(str3, "banana", 6);
	// Test 7: Case sensitivity check
	run_test(str1, "two", 7);
	return (0);
}
