#include "pipex.h"

static char	*get_full_path(char *dir, char *file_name)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, file_name);
	free(tmp);
	if (!res)
		return (NULL);
	return (res);
}

char	**get_paths_array(char **envp)
{
	if (!envp)
		return (NULL);
	while (*envp)
	{
		if (*envp && ft_strlen(*envp) > 4 && !ft_strncmp(*envp, "PATH", 4))
		{
			return (ft_split(*envp + 5, ':'));
		}
		envp++;
	}
	return (NULL);
}

char	*find_executable(char **dirs, char *file_name)
{
	int		iter;
	char	*path;

	iter = 0;
	while (*(dirs + iter))
	{
		path = get_full_path(*(dirs + iter), file_name);
		if (!path)
			return (NULL);
		if (!access(path, 1))
			return (path);
		iter++;
		free(path);
	}
	return (NULL);
}
