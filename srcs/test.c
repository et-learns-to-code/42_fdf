
#include "../includes/fdf.h"

int main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_map	*map;
	int		index;
	// int		z_arr[10];
	// int		color_arr[10];

	(void) ac;
	map = map_init();
	get_map_height(av, map);
	get_map_width(av, map);
	ft_printf("Map height: %d\nMap width: %d\n", map->height, map->width);
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	// while (line)
	// {
	// 	parse_line(line, map);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	close(fd);
	return (0);
}

// ft_printf("%d\n", ft_atoi_base("0xFFFF", 16));
// ft_printf("%d\n", ft_atoi_base("12345435", 10));
// extract_z_and_color("20,0xFF0000", z_arr, color_arr, 1);
// ft_printf("Z: %d\n", z_arr[1]);
// ft_printf("Color: %d\n", color_arr[1]);
