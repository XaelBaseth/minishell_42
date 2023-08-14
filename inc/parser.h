/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:09:34 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/10 09:15:07 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_single_command
{
	char					**str;
	struct s_single_command	*previous;
	struct s_single_command	*next;
}				t_command;