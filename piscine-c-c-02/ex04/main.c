/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:09:59 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/12 13:14:04 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* prototype source function */

int	ft_str_is_lowercase(char *str);

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
	if (ft_str_is_lowercase(str) == 1)
	{
		ft_putstr("PASSED (Only Alpha Lowercase or Empty)\n");
	}
	else
	{
		ft_putstr("FAILED (Contains Non-Alpha or Alpha Uppercase)\n");
	}
}

/* main function with different test strings */

int	main(void)
{
	test_string("hello", "Test 1 (Valid lowercase)");
	test_string("", "Test 2 (Empty string)");
	test_string("Hello", "Test 3 (Contains uppercase)");
	test_string("hello42", "Test 4 (Contains numbers)");
	test_string("hello world", "Test 5 (Contains spaces)");
	test_string("protocol!", "Test 6 (Contains punctuation)");
	return (0);
}
