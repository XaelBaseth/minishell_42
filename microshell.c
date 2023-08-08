#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

/*
Run the program with < gcc microshell.c -lreadline >
Quit the program with Ctrl + C
*/

//As this command is not a system program, it is executed
//in the child process, but not the parent. To execute it
//in the parent process, we have to implement our own and 
//make sure that the process does not fork, but instead we
//wait for the next input.
int cd(char *path)
{
	return chdir(path);
}

char	**get_input(char *input)
{
	char **command = malloc(8 * sizeof(char *));
	if (command == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	char *separator = " ";
	char *parsed;
	int index = 0;

	parsed = strtok(input, separator);
	while (parsed != NULL)
	{
		command[index] = parsed;
		index++;
		parsed = strtok(NULL, separator);
	}
	command[index] = NULL;
	return command;
}

void	print_envp(char **envp)
{
	int	i = 0;
	int o = 0;

	while (envp[i])
	{
		o = 0;
		while (envp[i][o])
		{
			write(1, &envp[i][o], 1);
			o++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	print_comm(char **command)
{
	int i = 0;
	int o = 0;

	while (command[i])
	{
		o = 0;
		while (command[i][o])
		{
			write(1, &command[i][o], 1);
			o++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void execute_in_path(const char *program, char **args, char **envp)
{
	char *path = getenv("PATH");
 	char *token = strtok(path, ":");

	while (token != NULL) 
	{
		char full_path[1024];
		snprintf(full_path, sizeof(full_path), "%s/%s", token, program);
		if (access(full_path, X_OK) == 0) {
			printf("Executing %s from %s\n", program, token);
			execve(full_path, args, envp);
			// If execve returns, it means there was an error
			perror("execve");
			return;
		}
		token = strtok(NULL, ":");
	}
	// If the program is not found in any of the directories in PATH
	printf("%s not found in any directories in PATH\n", program);
	return;
}

int main(int argc, char **argv, char **envp)
{
	char *input;
	char **command;
	__pid_t child_pid;
	int stat_loc;

	(void)argc;
	(void)argv;
	//if (envp)
	//	print_envp(envp);
	while (1) 
	{
		input = readline("\033[32mmicroshell$\033[0m ");
		add_history(input);
		command = get_input(input);
		if (!command[0]) // Handle empty commands
		{
			free(input);
			free(command);
			continue;
		}
		if (strcmp(command[0], "cd") == 0)
		{
			if (cd(command[1]) < 0)
				perror(command[1]);
			// skip the fork
			continue;
		}
		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}
		if (child_pid == 0)
		{
			execute_in_path(command[0], command, envp);
			exit(1);
		}
		else
		{
			waitpid(child_pid, &stat_loc, WUNTRACED);
		}
		if (!input)
			free(input);
		if (!command)
			free(command);
	}
	return 0;
}
