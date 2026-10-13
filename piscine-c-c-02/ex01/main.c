/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 11:56:00 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/09 12:10:09 by yvwilken         ###   ########.fr       */
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

int	main(void)
{
	char			*source;
	char			destination[50];
	unsigned int	n;
	char			*result;

	source = (char *)"Hello, 42 World!";
	n = 5;
	result = ft_strncpy(destination, source, n);
	ft_putstr("Source: ");
	ft_putstr(source);
	ft_putstr("\nDestination: ");
	ft_putstr(destination);
	ft_putstr("\nReturned Pointer: ");
	ft_putstr(result);
	ft_putstr("\n");
	return (0);
}
