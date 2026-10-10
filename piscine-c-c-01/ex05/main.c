/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:31:43 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/08 15:33:16 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);

int	main(void)
{
	char	*test_string;

	test_string = "Hello, 42 Network!";
	ft_putstr(test_string);
	ft_putstr("\n");
	return (0);
}
