#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				result;
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		result = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (result != 0)
		{
			return (result);
		}
		if (s1[i] == 0 || s2[i] == 0)
		{
			return (0);
		}
		i++;
	}
	return (0);
}
