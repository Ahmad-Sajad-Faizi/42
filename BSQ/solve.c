#include "bsq.h"

void	solve_map(t_map *map)
{
	int	*dp;
	int	i;
	int	max_size;
	int	max_r;
	int	max_c;
	int	map_start;
	int	r;
	int	prev;
	int	c;
	int	temp;
	int	idx;
	int	min;

	dp = malloc(map->cols * sizeof(int));
	if (!dp)
	{
		ft_puterror();
		return ;
	}
	i = 0;
	while (i < map->cols)
	{
		dp[i] = 0;
		i++;
	}
	max_size = 0;
	max_r = 0;
	max_c = 0;
	map_start = map->first_line_len + 1;
	r = 0;
	while (r < map->rows)
	{
		prev = 0;
		c = 0;
		while (c < map->cols)
		{
			temp = dp[c];
			idx = map_start + r * (map->cols + 1) + c;
			if (map->buffer[idx] == map->obs)
				dp[c] = 0;
			else
			{
				if (r == 0 || c == 0)
					dp[c] = 1;
				else
				{
					min = dp[c];
					if (dp[c - 1] < min)
						min = dp[c - 1];
					if (prev < min)
						min = prev;
					dp[c] = 1 + min;
				}
				if (dp[c] > max_size)
				{
					max_size = dp[c];
					max_r = r;
					max_c = c;
				}
			}
			prev = temp;
			c++;
		}
		r++;
	}
	free(dp);
	if (max_size > 0)
	{
		r = max_r - max_size + 1;
		while (r <= max_r)
		{
			c = max_c - max_size + 1;
			while (c <= max_c)
			{
				idx = map_start + r * (map->cols + 1) + c;
				map->buffer[idx] = map->full;
				c++;
			}
			r++;
		}
	}
	write(1, map->buffer, map->buffer_size);
}
