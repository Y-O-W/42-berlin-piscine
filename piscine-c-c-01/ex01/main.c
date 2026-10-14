/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvwilken <yvwilken@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 11:54:41 by yvwilken          #+#    #+#             */
/*   Updated: 2026/10/08 12:18:21 by yvwilken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_ft(int *********nbr);

int	main(void)
{
	int		nbr;
	void	*arr[8];

	nbr = 0;
	arr[0] = &nbr;
	arr[1] = &arr[0];
	arr[2] = &arr[1];
	arr[3] = &arr[2];
	arr[4] = &arr[3];
	arr[5] = &arr[4];
	arr[6] = &arr[5];
	arr[7] = &arr[6];
	printf("Before: %d\n", nbr);
	ft_ultimate_ft((int *********)&arr[7]);
	printf("After: %d\n", nbr);
	return (0);
}
