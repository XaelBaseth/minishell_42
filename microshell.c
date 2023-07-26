/*
Run the program with < gcc microshell.c -lreadline >
Quit the program with Ctrl + C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <unistd.h>

int cd(char *path)
//As this command is not a system program, it is executed
//in the child process, but not the parent. To execute it
//in the parent process, we have to implement our own and 
//make sure that the process does not fork, but instead we
//wait for the next input.
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


int	main(void)
{
	char **command;
	char *input;
	__pid_t child_pid;
	int stat_loc;

	while (1)
	{
		input = readline("\033[32mmicroshell$\033[0m ");
		command = get_input(input);
		if (!command[0]) //Handle empty commands
		{
			free(input);
			free(command);
			continue;
		}
		if (strcmp(command[0], "cd") == 0)
		{
			if (cd(command[1]) < 0)
				perror(command[1]);
			//skip the fork
			continue;
		}
		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}
		//With the use of <fork()> we create a new branch in our 
		//program, a copy of the current process. After the success of
		//the <fork()>
		//call, both process runs at the same time.
		//The <fork()> system returns twice, once for each process.
		if (child_pid == 0)
		{
			//Never return if the calls is successful
			if (execvp(command[0], command) < 0)
			{
				perror(command[0]);
				exit(1);
			}
			//The <execvp> allows us to execute a program.
			//It provides an array of pointer to \0 strings that represent
			//the arguments lists available to the program.
			//the <execvp> duplicates the actions of shell in searching
			//for an executable file in the PATH env variables.
		}
		else
			waitpid(child_pid, &stat_loc, WUNTRACED);
			//The <waitpid> suspends execution of the calling process
			//until a child specified by pid argument has changed
			//state.
		if (!input)
			free(input);
		if (!command)
			free(command);
	}
	return (0);
}

