<h2>Minishell has to:</h2>

- display a prompt. 

- have a working history.

- search and launch the right executable (PATH/relative/absolute path).

- Use one global variable.

- Not interpret unclosed `"` or special characters (`\;`).

- Handle `'` to prevent the shell from interpreting meta characters in the quoted sentence.

- Handle `"` to prevent the shell from interpreting meta characters except the `$`.

- Implement redirections and pipes.

- Handle environment variables and also `$?`

- Handle `ctrl-C`, `ctrl-D`, `ctrl-\` which should respectively display a new prompt, exit the shell, do nothing.

- Implement the following builtins: `echo -n`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.

- Implement `&&` and `||` with parenthesis for priorities.

- Wildcards `*` should work for current wd.


<h2>Subject:</h2>

https://cdn.intra.42.fr/pdf/pdf/95920/fr.subject.pdf

<h2>Useful links:</h2>

https://achrafbelarif.medium.com/42cursus-minishell-29cd25f972e6

https://segfault42.github.io/posts/minishell/

https://www.lamsade.dauphine.fr/~bnegrevergne/ens/Unix/static/projet.pdf

https://carlagoeshacking.files.wordpress.com/2017/01/minisheel.pdf < il y a des tests de commandes avec explications, ca peut aider

https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
Complet, mais ALED!

[Shell command language](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html) Tres complet ! Decrit une partie du fonctionnement du Shell.

[\[ChatGPT\] How to create the lexer. Useless?](https://chat.openai.com/share/321ad963-0231-4505-872b-b3a8d3420c61)

[\[ChatGPT\] Arrows handling on shell. Useless?](https://chat.openai.com/share/329b8e5a-0361-470d-bd06-d05f8358660c)

[PIPEX] https://github.com/jdecorte-be/42-Pipex

<h2>WorkFlow</h2>

https://github.com/maiadegraaf/minishell

- The Lexer: takes as the entered line as input. It then reads through the line word by word, using white space as delimiters. First it checks wether or not the word is a token, ie: |, <, <<, >, or >>, and otherwise it assumes it is a word.
- The Parser: The lexer then gets sent to the parser which then groups the different nodes together based on the tokens. Each group becomes a command. The first thing the parser does is loop through the lexer list until it encounters a pipe. It then takes all the nodes before the pipe as one command, and creates a node in the t_simple_cmds struct. If it doesn't find a pipe it takes all the (remaining) nodes as one command.
- Builtins: We handle builtins, as discussed above through storing a function pointer in the t_simple_cmds. We achieve this by sending the the first word of a command to a function builtin_arr which loops through a static array of the different builtin functions. If it finds a corresponding function it returns it to the parser, else it returns NULL.
- Executor: When the parser returns the t_simple_cmds list back to minishell_loop, a simple check is done to determine how many commands there are, as they are handled by different functions. However, with the exception of a few builtins, the commands are ultimately executed by the same function handle_cmd, which finds, and if successful, executes the command.