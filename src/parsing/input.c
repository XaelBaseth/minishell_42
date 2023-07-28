/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:55 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/28 12:24:54 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//static char	validate_input(char *raw_input)
//{
//	Pass it throught the parser & lexer
//	That means : 	- get length of args
//					- get number of args
//					- get rid of whitespace (space or tabs)
//					- get operator and applies it.
//	GLHF :)
//}

/*	Returns the input of the user after validating it. */
char	*get_input(void)
{
	char *raw_input;
	//char *input;

	raw_input = readline("\033[32mminishell$\033[0m ");
	//input = validate_input(raw_input);
	//penser a changer le return en input
 	return (raw_input);
}

char	**get_command(char *input)
{
	char **command;	
	char *separator = " ";
	char *parsed;
	int index = 0;

	command = malloc(64 * sizeof(char *));
	if (!command)
		panic("Command mem allocation failed.");
	parsed = strtok(input, separator);
	while (parsed != NULL)
	{
		command[index] = parsed;
		index++;
		parsed = strtok(NULL, separator);
	}
	command[index] = NULL;
	return (command);
}
