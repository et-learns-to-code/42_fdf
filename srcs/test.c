#include <fcntl.h>
#include <unistd.h>
#include "../includes/fdf.h"

void parse_line(char *line, t_map *map);

int main(int ac, char **av)
{
	int fd;
	int height;
	char *line;
	t_map *map = NULL;

	(void) ac;
	height = 0;

	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, map);
		height++;
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("Height: %d\n", height);
	close(fd);
	return (0);
}

void parse_line(char *line, t_map *map)
{
	char **unprocessed_arr;
	int	i;
	int width;
	int *z_arr;
	int *color_arr;

	(void) map;
	unprocessed_arr = ft_split(line, ' ');
	i = 0;
	while (unprocessed_arr[i])
	{
		ft_printf("%s", unprocessed_arr[i]);
		i++;
	}
	width = i;
	ft_printf("Width: %d\n", width);
}

void extract_z_and_color(char *unprocessed_str, int *z_arr, int *color_arr, int index)
{
	char *nbr;
	char *hex;
	int i = 0;
	int nbr_len = 0;

	while (unprocessed_str[i] == '-' || ft_isdigit(unprocessed_str[i]))
	{
		nbr_len++;
		i++;
	}
	nbr = ft_substr(unprocessed_str, 0, nbr_len);
	z_arr[index] = ft_atoi(nbr);
	free(nbr);
	if (unprocessed_str[i] == ',')
	{
		hex = ft_substr(unprocessed_str, i + 1, ft_strlen(unprocessed_str) - (i + 1));
		color_arr[index] = ft_atoi_base(hex, 16);
		free(hex);
	}
	else
		color_arr[index] = DEFAULT_COLOR;
}





// typedef struct s_map
// {
// 	int	width;
// 	int	height;
// 	int	*z_arr;
// 	int	*color_arr;
// }	t_map;
