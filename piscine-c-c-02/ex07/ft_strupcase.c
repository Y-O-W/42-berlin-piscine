/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:57:46 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/12 17:01:46 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* loop through string with a counter */
/* if statement converting alpha to upcase */
/* using the ASCII caluclation -32 */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
