#include "pipex.h"

void	destroy_strings_array(char **arr)
{
	char	**ptr;

	if (!arr)
		return ;
	ptr = arr;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(arr);
}

void	append_str(char **str, char *to_append_with)
{
	char	*res;

	if (!*str || !to_append_with)
		return ;
	res = ft_strjoin(*str, to_append_with);
	free(*str);
	*str = res;
}
