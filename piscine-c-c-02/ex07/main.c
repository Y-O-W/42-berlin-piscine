/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:31:46 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/12 17:32:10 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str);

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

void	ft_init_str(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	main(void)
{
	char	str1[50];
	char	str2[50];
	char	str3[50];
	char	str4[50];

	ft_init_str(str1, "Hello 42 Network!");
	ft_init_str(str2, "");
	ft_init_str(str3, "HELLO WORLD");
	ft_init_str(str4, "hello world");
	ft_putstr("Test 1: ");
	ft_putstr(ft_strupcase(str1));
	ft_putstr("\n");
	ft_putstr("Test 2: ");
	ft_putstr(ft_strupcase(str2));
	ft_putstr("\n");
	ft_putstr("Test 3: ");
	ft_putstr(ft_strupcase(str3));
	ft_putstr("\n");
	ft_putstr("Test 4: ");
	ft_putstr(ft_strupcase(str4));
	ft_putstr("\n");
	return (0);
}
