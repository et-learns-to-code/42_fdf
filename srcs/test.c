#include <fcntl.h>
#include <unistd.h>
#include "../includes/fdf.h"

void	parse_line(char *line, t_map *map);
int		ft_atoi_base(const char *str, int str_base);
void	extract_z_and_color(char *unprocessed_str, int *z_arr, int *color_arr, int index);

int main(int ac, char **av)
{
	int fd;
	int height;
	char *line;
	t_map *map = NULL;
	int z_arr[10];
	int color_arr[10];

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
	ft_printf("%d\n", ft_atoi_base("0xFFFF", 16));
	ft_printf("%d\n", ft_atoi_base("12345435", 10));
	extract_z_and_color("20,0xFF0000", z_arr, color_arr, 1);
	ft_printf("Z: %d\n", z_arr[1]);
	ft_printf("Color: %d\n", color_arr[1]);
	close(fd);
	return (0);
}

void parse_line(char *line, t_map *map)
{
	char **unprocessed_arr;
	int	i;
	int width;
	// int *z_arr;
	// int *color_arr;

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
	z_arr[index] = ft_atoi_base(nbr, 10);
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

// This function will convert the given string to its decimal integer value
// based on the specified base.
// The if condition for base 16 will move the string pointer two spaces
// to move past its '0x' prefix.
int     ft_atoi_base(const char *str, int str_base)
{
	int sign = 1;
	int res = 0;
	int dec = 0;

	if (str_base == 16)
		str = str + 2;
	while (*str && str_base <= 16)
	{
		if (*str == '-')
			sign *= -1;
		else if (*str >= '0' && *str <= '9')
			dec = *str - '0';
		else if (*str >= 'A' && *str <= 'F')
			dec = *str - 'A' + 10;
		else if (*str >= 'a' && *str <= 'f')
			dec = *str - 'a' + 10;
		else
			break;
		res *= str_base;
		res += dec;
		str++;
	}
	return (res * sign);
}


// typedef struct s_map
// {
// 	int	width;
// 	int	height;
// 	int	*z_arr;
// 	int	*color_arr;
// }	t_map;
