/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 11:43:14 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/13 11:54:56 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Two separate while loops that execute one after the other:
The first copies characters from src to dest until a null-terminator or index n.
The second loop pads the rest of the target buffer with \0 up to index n.
The second loop needs to pick up exactly where the first loop left off,
keeping the current state/value of i is required.
*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
