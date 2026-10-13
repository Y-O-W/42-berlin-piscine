/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:35:30 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/09 11:14:00 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src);

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
	char	*source;
	char	destination[50];
	char	*result;

	source = (char *)"Hello, 42 World!";
	result = ft_strcpy(destination, source);
	ft_putstr("Source: ");
	ft_putstr(source);
	ft_putstr("\nDestination: ");
	ft_putstr(destination);
	ft_putstr("\nReturned Pointer: ");
	ft_putstr(result);
	ft_putstr("\n");
	return (0);
}
