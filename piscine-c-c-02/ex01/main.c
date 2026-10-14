/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 11:56:00 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/13 11:31:46 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

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

/* This prints a hidden string up to 'max' size to see embedded '\0' bytes */
void	ft_print_buffer(char *buffer, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (buffer[i] == '\0')
			write(1, "\\0", 2);
		else
			write(1, &buffer[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	char	dest1[20];
	char	dest2[20];
	char	dest3[20];
	int		i;

	/* Setup clean buffers filled with 'A's to easily spot the null-padding */
	i = 0;
	while (i < 20)
	{
		dest1[i] = 'A';
		dest2[i] = 'A';
		dest3[i] = 'A';
		i++;
	}
	/* Test 1: n is smaller than src string length (No null termination added) */
	ft_strncpy(dest1, "42Network", 4);
	ft_putstr("Test 1 (n < src): ");
	ft_print_buffer(dest1, 15);
	/* Test 2: n matches exactly src length (No extra null padding) */
	ft_strncpy(dest2, "Code", 4);
	ft_putstr("Test 2 (n == src): ");
	ft_print_buffer(dest2, 10);
	/* Test 3: n is much larger than src (Must fill remainder with \0) */
	ft_strncpy(dest3, "Hi", 8);
	ft_putstr("Test 3 (n > src): ");
	ft_print_buffer(dest3, 12);
	return (0);
}
