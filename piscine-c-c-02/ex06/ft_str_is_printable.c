/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:15:32 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/12 15:27:05 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* loop through string with a counter */
/* if statement checking for a (non) printable character for every count*/
/* printable characters range from decimal 32 to 126 */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
