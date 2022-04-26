#include "pipex.h"

static void	execute_child(t_cmd *cmd, int fields[2])
{
	dup2(cmd->input_fd, 0);
	dup2(fields[1], 1);
	close(cmd->input_fd);
	close(fields[0]);
	close(fields[1]);
	if (execve(cmd->exec_1, cmd->com_1, NULL))
	{
		perror(strerror(errno));
		exit(0);
	}
}

static void	execute_parent(t_cmd *cmd)
{
	int		fields[2];
	pid_t	pid;

	pipe(fields);
	pid = fork();
	if (pid == -1)
	{
		perror(strerror(errno));
		exit(1);
	}
	if (pid == 0)
		execute_child(cmd, fields);
	waitpid(pid, NULL, WNOHANG);
	dup2(fields[0], STDIN_FILENO);
	dup2(cmd->output_fd, STDOUT_FILENO);
	close(fields[0]);
	close(fields[1]);
	close(cmd->output_fd);
	if (execve(cmd->exec_2, cmd->com_2, NULL))
	{
		perror(strerror(errno));
		exit(0);
	}
}

static void	execute(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror(strerror(errno));
		return ;
	}
	if (pid == 0)
		execute_parent(cmd);
	waitpid(pid, NULL, WNOHANG);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;

	cmd = get_cmd(argc, argv, envp);
	if (!cmd)
		return (1);
	execute(cmd);
	destroy_cmd(cmd);
}
