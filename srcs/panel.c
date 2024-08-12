/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:47:03 by etien             #+#    #+#             */
/*   Updated: 2024/08/12 16:31:56 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_panel(t_fdf *fdf)
{
	int	x;
	int	x_indent;
	int	y;

	x = 15;
	x_indent = x + 50;
	y = 15;
	mlx_string_put(fdf->mlx, fdf->win, x, y, PANEL_TEXT, "Controls:");
	mlx_string_put(fdf->mlx, fdf->win, x, y, PANEL_TEXT, "Zoom: +/-");
	mlx_string_put(fdf->mlx, fdf->win, x, y, PANEL_TEXT, "Move: W A S D");
	mlx_string_put(fdf->mlx, fdf->win, x, y, PANEL_TEXT, "Rotate:");
	mlx_string_put(fdf->mlx, fdf->win, x_indent, y, PANEL_TEXT, "X-axis: 1/2");
	mlx_string_put(fdf->mlx, fdf->win, x_indent, y, PANEL_TEXT, "Y-axis: 3/4");
	mlx_string_put(fdf->mlx, fdf->win, x_indent, y, PANEL_TEXT, "Z-axis: 5/6");
	mlx_string_put(fdf->mlx, fdf->win, x, y, PANEL_TEXT, "Projection:");
	mlx_string_put(fdf->mlx, fdf->win, x_indent, y, PANEL_TEXT, "Isometric: I");
	mlx_string_put(fdf->mlx, fdf->win, x_indent, y, PANEL_TEXT, "Parallel: P");
}
