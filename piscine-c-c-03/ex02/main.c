/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:08:34 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/13 16:08:37 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* prototype */

char	*ft_strcat(char *dest, char *src);

/* print string */

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

/* test function */

void	ft_run_tests(char *dest1, char *dest2)
{
	char	*res;

	dest1[0] = 'H';
	dest1[1] = 'e';
	dest1[2] = 'l';
	dest1[3] = 'l';
	dest1[4] = 'o';
	dest1[5] = ' ';
	res = ft_strcat(dest1, "World!");
	ft_putstr("T1: ");
	ft_putstr(res);
	ft_putstr("\n");
	res = ft_strcat(dest2, "42 Berlin");
	ft_putstr("T2: ");
	ft_putstr(res);
	ft_putstr("\n");
}

/* main function */

int	main(void)
{
	char	dest1[50];
	char	dest2[50];
	int		i;

	i = 0;
	while (i < 50)
	{
		dest1[i] = '\0';
		dest2[i] = '\0';
		i++;
	}
	ft_run_tests(dest1, dest2);
	return (0);
}
