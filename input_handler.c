#include "pipex.h"

static int	check_input_file(char *file_path)
{
	if (access(file_path, R_OK) == -1)
	{
		perror(strerror(errno));
		return (-1);
	}
	return (open(file_path, O_RDONLY));
}

static int	check_output_file(char *file_path, int input_fd)
{
	if (input_fd == -1)
		return (-1);
	if (!access(file_path, W_OK))
		return (open(file_path, O_WRONLY | O_TRUNC));
	else if (!access(file_path, F_OK))
	{
		perror(strerror(errno));
		return (-1);
	}
	return (open(file_path, O_WRONLY | O_CREAT, 0700));
}

void	destroy_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	destroy_strings_array(cmd->com_1);
	destroy_strings_array(cmd->com_2);
	free(cmd->exec_1);
	free(cmd->exec_2);
	free(cmd);
}

t_cmd	*get_cmd(int argc, char **argv, char **envp)
{
	char	**dirs;
	t_cmd	*res;

	if (argc != 5)
		return (NULL);
	dirs = get_paths_array(envp);
	if (!dirs)
		return (NULL);
	res = (t_cmd *)malloc(sizeof(t_cmd));
	if (!res)
		return (NULL);
	res->input_fd = check_input_file(argv[1]);
	res->output_fd = check_output_file(argv[4], res->input_fd);
	res->com_1 = ft_split(argv[2], ' ');
	res->com_2 = ft_split(argv[3], ' ');
	res->exec_1 = find_executable(dirs, res->com_1[0]);
	res->exec_2 = find_executable(dirs, res->com_2[0]);
	destroy_strings_array(dirs);
	if (!(res->input_fd == -1 || res->output_fd == -1 || !res->com_1
			|| !res->com_2 || !res->exec_1 || !res->exec_2))
		return (res);
	destroy_cmd(res);
	return (NULL);
}
