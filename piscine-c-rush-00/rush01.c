/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowfactor <yowfactor@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 14:30:56 by yowfactor         #+#    #+#             */
/*   Updated: 2026/10/11 15:25:34 by yowfactor        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* prototype print character */

void	ft_putchar(char c);

/* test "top" before "bottom", and "left" before "right" */

/* function print corner*/

static	void	ft_print_cell_corner(int x, int y, int row, int col)
{
	int	top_left;
	int	top_right;
	int	bottom_left;
	int	bottom_right;

	top_left = (row == 0 && col == 0);
	top_right = (row == 0 && col == x - 1);
	bottom_left = (row == y - 1 && col == 0);
	bottom_right = (row == y - 1 && col == x - 1);
	if (top_left)
		ft_putchar('/');
	else if (top_right)
		ft_putchar('\\');
	else if (bottom_left)
		ft_putchar('\\');
	else if (bottom_right)
		ft_putchar('/');
}

/* function print edge or interior */

static	void	ft_print_cell(int x, int y, int row, int col)
{
	int	edge_row;
	int	edge_col;

	edge_row = (row == 0 || row == y - 1);
	edge_col = (col == 0 || col == x - 1);
	if (edge_row && edge_col)
		ft_print_cell_corner(x, y, row, col);
	else if (edge_row || edge_col)
		ft_putchar('*');
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
