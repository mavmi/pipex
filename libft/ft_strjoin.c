#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		counter;
	char	*result;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = (char *)malloc(s1_size + s2_size + 1);
	if (!result)
	{
		return (NULL);
	}
	counter = 0;
	while (*s1)
	{
		result[counter++] = *s1++;
	}
	while (*s2)
	{
		result[counter++] = *s2++;
	}
	result[counter] = '\0';
	return (result);
}
