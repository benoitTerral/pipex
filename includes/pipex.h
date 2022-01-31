#ifndef PIPEX_H
# define PIPEX_H

/*ft_strlen*/
# include "libft/libft.h"

/*perror*/
# include <stdio.h>

/*open*/
#include <fcntl.h>

/*exit*/
# include <stdlib.h>

/*write*/
# include <unistd.h>

# define ARG_ERROR "Expected format error is: ./pipex file1 cmd1 cmd2 file2"
# define PIPE_ERROR "Pipe creation failed"
# define CMD_ERROR "Command not found"
# define PID_ERROR "Fail to create process"
# define FAIL_PATHS "Could not retrieve the PATH variable correctly"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		channel;
	int		fd[2];
	char	**paths;
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

/*Error functions*/
int		return_error(char *err_msg);
void	perror_exit(char *error_msg);

/*children processes*/
char	**get_paths(char **envp);
char	*get_cmd(t_pipex	*pipex);
void	execute_second_command(t_pipex *pipex, char **argv, char **envp);
void	execute_commands(t_pipex *pipex, char **argv, char **envp);

#endif