/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:17:48 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/12 16:25:16 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* prototype source function */

int	ft_str_is_printable(char *str);

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
	if (ft_str_is_printable(str) == 1)
	{
		ft_putstr("PASSED (Only Printable Characters or Empty)\n");
	}
	else
	{
		ft_putstr("FAILED (Contains Non-Printable Characters)\n");
	}
}

/* main function with different test strings */

int	main(void)
{
	test_string("Hello 42 Network!", "Test 1 (Valid printable)");
	test_string("", "Test 2 (Empty string)");
	test_string("Hello\nWorld", "Test 3 (Contains newline)");
	test_string("Hello\tWorld", "Test 4 (Contains tab)");
	return (0);
}
