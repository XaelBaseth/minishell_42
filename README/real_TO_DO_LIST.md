- Handle `$?` <-- last command int return (errors, 0 = success). It's probably a variable only. Make every command return that int!

	`$?` should return an error, `echo $?` shouldn't!
	`$"f"` returns `minishell: f: error truc`
	`echo $"f"` returns `f`

- Execute commands like `/home/cpothin/Desktop/minishell` or `./minishell`.
- Handle `\"` that must show only `"`!