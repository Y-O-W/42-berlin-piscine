/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowfactor <yowfactor@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 15:33:20 by yowfactor         #+#    #+#             */
/*   Updated: 2026/10/11 15:41:22 by yowfactor        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);
void	rush(int x, int y);

/* error helper: prints "Error" and a newline */

static	void	ft_error(void)
{
	char	*msg;
	int		i;

	msg = "Error\n";
	i = 0;
	while (msg[i])
	{
		ft_putchar(msg[i]);
		i++;
	}
}

/* validity helper: optional sign, then 1 to 6 digits, nothing else */

static	int	ft_valid(char *s)
{
	int	i;
	int	start;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	start = i;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (s[i] == '\0' && i > start && i - start <= 6);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_valid(argv[1]) || !ft_valid(argv[2]))
	{
		ft_error();
		return (1);
	}
	rush(atoi(argv[1]), atoi(argv[2]));
	return (0);
}
