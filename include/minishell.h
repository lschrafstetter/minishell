/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:59:17 by lschrafs          #+#    #+#             */
/*   Updated: 2022/08/01 14:28:41 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

/* LIST STRUCTS */

typedef struct s_lst_env
{
	struct s_lst_env	*next;
	char				*name;
	char				*value;
}	t_lst_env;

typedef struct s_lst_str
{
	struct s_lst_str	*next;
	char				*str;
}	t_lst_str;

typedef struct s_lst_processes
{
	int					fdin;
	int					fdout;
	char				**cmd;
	char				*path;
	struct s_data		*data;
}	t_lst_processes;

/* GENERAL DATA STRUCT */

typedef struct s_data
{
	t_lst_env			**ls_env;
	t_lst_processes		*processes;
	char				*input;
	char				*prompt;
	int					n_processes;
	int					exit_code;
}	t_data;

/* INITIALIZATION */

void		signalhandler_init(void);
t_data		*datastruct_init(char **envp);

/* LISTS */

t_lst_env	*ls_env_new(char *name, char *value);
void		ls_env_addfront(t_lst_env **lst, t_lst_env *new);
void		ls_env_addback(t_lst_env **lst, t_lst_env *new);
void		ls_env_clear(t_lst_env **lst);

t_lst_str	*ls_str_new(char *str);
void		ls_str_addfront(t_lst_str **lst, t_lst_str *new);
void		ls_str_addback(t_lst_str **lst, t_lst_str *new);
void		ls_str_clear(t_lst_str **lst);

/* ENV */

char		*ms_getenv(t_data *data, char *name);

/* PARSING */

int			input_parse(t_data *data);

/* EXECUTING */

int			input_execute(t_data *data);

/* UTILS */

void		ms_quit(t_data *data, int err);
void		ms_exit(int err, char *message);
void		data_free(t_data *data);
void		free_str(char *str);
int			is_whitespace(int c);
int			is_history_command(char *str);
char		*prompt_get(t_data *data);

#endif