/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:43:29 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/12 12:53:54 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* loop through string with a counter */
/* Verify against the ASCII digit range */
/* The character limits are between '0' and '9' */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
