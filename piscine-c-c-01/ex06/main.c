/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:38:33 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/08 16:39:10 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	char	*test_str;
	int		length;

	test_str = "Hello 42";
	length = ft_strlen(test_str);
	printf("String: \"%s\"\n", test_str);
	printf("Length: %d\n", length);
	return (0);
}
