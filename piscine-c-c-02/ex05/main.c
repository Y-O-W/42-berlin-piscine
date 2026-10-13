/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:22:04 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/12 13:24:52 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* prototype source function */

int	ft_str_is_uppercase(char *str);

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
	if (ft_str_is_uppercase(str) == 1)
	{
		ft_putstr("PASSED (Only Alpha Uppercase or Empty)\n");
	}
	else
	{
		ft_putstr("FAILED (Contains Non-Alpha or Alpha Lowercase)\n");
	}
}

/* main function with different test strings */

int	main(void)
{
	test_string("HELLO", "Test 1 (Valid uppercase)");
	test_string("", "Test 2 (Empty string)");
	test_string("HeLLo", "Test 3 (Contains lowercase)");
	test_string("HELLO42", "Test 4 (Contains numbers)");
	test_string("HELLO WORLD", "Test 5 (Contains spaces)");
	test_string("PROTOCOL!", "Test 6 (Contains punctuation)");
	return (0);
}
