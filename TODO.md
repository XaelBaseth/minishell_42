<h2>Minishell has to:</h2>

- display a prompt

- have a working history

	Use `get_next_line` for this.

- search and launch the right executable (PATH/relative/absolute path)

- Use one global variable

- Not interpret unclosed " or special characters (\;)

- Handle ' to prevent the shell from interpreting meta characters in the quoted sentence

- Handle " to prevent the shell from interpreting meta characters except the $

- Implement redirections and pipes

- Handle environment variables and also $?

- Handle ctrl-C, ctrl-D, ctrl-\ which should respectively display a new prompt, exit the shell, do nothing.

- Implement the following builtins: echo -n, cd, pwd, export, unset, env, exit

- Implement && and || with parenthesis for priorities

- Wildcards * should work for current wd


<h2>Subject:</h2>

https://cdn.intra.42.fr/pdf/pdf/95920/fr.subject.pdf

<h2>Useful links:</h2>

https://achrafbelarif.medium.com/42cursus-minishell-29cd25f972e6

https://segfault42.github.io/posts/minishell/

https://www.lamsade.dauphine.fr/~bnegrevergne/ens/Unix/static/projet.pdf

https://carlagoeshacking.files.wordpress.com/2017/01/minisheel.pdf < il y a des tests de commandes avec explications, ca peut aider
