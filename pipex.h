#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <sys/errno.h>
# include "libft/libft.h"

typedef struct s_cmd
{
	int		input_fd;
	int		output_fd;
	char	**com_1;
	char	**com_2;
	char	*exec_1;
	char	*exec_2;
}			t_cmd;

t_cmd	*get_cmd(int argc, char **argv, char **envp);
void	destroy_cmd(t_cmd *cmd);

void	destroy_strings_array(char **arr);
void	append_str(char **str, char *to_append_with);

char	**get_paths_array(char **envp);
char	*find_executable(char **dirs, char *file_name);

#endif