/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowfactor <yowfactor@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 10:30:41 by yowfactor         #+#    #+#             */
/*   Updated: 2026/10/11 12:00:09 by yowfactor        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* prototype print character */

void	ft_putchar(char c);

/* helper function for specific character */

static	void	ft_print_cell(int x, int y, int row, int col)
{
	int	edge_row;
	int	edge_col;

	edge_row = (row == 0 || row == y - 1);
	edge_col = (col == 0 || col == x - 1);
	if (edge_row && edge_col)
		ft_putchar('o');
	else if (edge_row)
		ft_putchar('-');
	else if (edge_col)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

/* y is row, x is column */

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (x <= 0 || y <= 0)
		return ;
	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			ft_print_cell(x, y, row, col);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
