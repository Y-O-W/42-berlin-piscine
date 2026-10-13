/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:55:48 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/12 13:00:44 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* prototype source function */

int	ft_str_is_numeric(char *str);

/* include print string */

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

/* helper function for test string */

void	test_string(char *str, char *test_name)
{
	ft_putstr(test_name);
	ft_putstr(": ");
	if (ft_str_is_numeric(str) == 1)
	{
		ft_putstr("PASSED (Only Numeric or Empty)\n");
	}
	else
	{
		ft_putstr("FAILED (Contains Non-Numeric)\n");
	}
}

/* main function with different test strings */

int	main(void)
{
	test_string("1234567890", "Test 1 (Valid digits only)");
	test_string("", "Test 2 (Empty string)");
	test_string("Hello42", "Test 3 (Contains alpha)");
	test_string("12345 67890", "Test 4 (Contains spaces)");
	test_string(".1234567890", "Test 5 (Contains punctuation)");
	return (0);
}
