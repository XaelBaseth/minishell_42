Minishell has to :

	- display a prompt

	- have a working history

	- search and launch the right executable (PATH/relative/absolute path)

	- Use one global variable

	- Not interpret unclosed " or special characters (\;)

	- Handle ' to prevent the shell from interpreting meta characters in the quoted sentence

	- Handle " to prevent the shell from interpreting meta characters except the $

	- Implement redirections and pipes

	- Handle environment variables and also $?

	- Handle ctrl-C, ctrl-D, ctrl-\ which should respectively display a new prompt, exit the shell, do nothing.

	-Implement the following builtins: echo -n, cd, pwd, export, unset, env, exit

	-Implement && and || with parenthesis for priorities

	-Wildcards * should work for current wd
