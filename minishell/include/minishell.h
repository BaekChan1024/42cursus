#ifndef MINISHELL_H
# define MINISHELL_H

/* ****************************************** */
/*                   Header                   */
/* ****************************************** */

# include "libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <termios.h>

/* ****************************************** */
/*              Macro Definition              */
/* ****************************************** */

# define FILE -2
# define WORD -1
# define PIPE 0
# define REDIRECT1 1 /* > */
# define REDIRECT2 2 /* < */
# define REDIRECT3 3 /* >> */
# define REDIRECT4 4 /* << */

/* ****************************************** */
/*                 Structure                  */
/* ****************************************** */

/* t_lst : env setting                 */
/* key: command, value: arg of command */
typedef struct s_lst
{
	char			*key;
	char			*value;
	int				idx;
	struct s_lst	*next;
}	t_lst;

/* t_tocken : */
typedef struct s_token
{
	char			*content;
	int				type;
	struct s_token	*next;
}	t_token;

/* t_cmd : */
typedef struct s_cmd
{
	char			**argv;
	int				pipe[2];
	int				fd_in;
	int				fd_out;
	int				is_pipe;
	struct s_cmd	*next;
}	t_cmd;

/* ****************************************** */
/*              Gobal Variables               */
/* ****************************************** */

int	g_status;

/* ****************************************** */
/*                 Functions                  */
/* ****************************************** */

/* signal.c */
int		handle_signal(void);
int		handle_signal_child(void);

/* set_env.c */
int		init_env_lst(t_lst **env_lst, char *env[]);
char	**make_env_arr(t_lst *env_lst);

/* lst_utils.c */
t_lst	*env_lst_alloc(char *str, int lst_idx);
t_lst	*env_lst_new(char *key, char *value, int idx);
void	env_lst_add(t_lst **lst, t_lst *new);

/* tocken.c */
t_token	*tokenize(char *input);
void	set_token_type(t_token *tokens);

/* tocken_utils.c */
t_token	*token_new(char *content);
int		token_add(t_token **lst, t_token *new);

/* parsing.c */
t_cmd	*parsing(char *input, t_lst *env_lst);

/* quote_utils.c */
int		is_valid_quote(char *input);

/* parse_utils.c */
int		get_env_str_len(char *input, int *idx, t_lst *env_lst);

/* parse_doller.c */
int		len_doller(char *input, int *idx);
char	*parse_doller(char *input, int *i, t_lst *env_lst);

/* parse_quotes.c */
char	*parse_quote(char *input, int *i);
char	*parse_dquote(char *input, int *i, t_lst *env_lst);

/* parse_none.c */
char	*parse_none(char *input, int *i, t_lst *env_lst);

/* utils.c */
char	*cnt_join(char *s1, char *s2, int idx, int r_idx);
int		lst_len(t_lst *lst);
int		check_multi_n(char *str);

/* init_argv.c */
char	**init_argv(t_token *token);

/* init_cmd.c */
t_cmd	*init_cmd(t_token *tokens);

/* check_redirection.c */
void	check_redirection(t_token *tokens, int *in, int *out);

/* free.c */
void	free_token(t_token *token_list);
void	free_2_arr(char **str);
void	free_cmd(t_cmd *cmd);

/* parse_path.c */
char	**parse_path(char *arg, t_lst *env_list);

/* built_in.c */
int		is_built_in(char *argv[]);
void	set_redirect_and_pipe(t_cmd *cmd, t_cmd *prev);
void	exec_built_in(t_cmd *cmd, t_lst **env_lst, t_cmd *prev);

/* mini_echo.c */
int		mini_echo(char *argv[]);

/* mini_pwd.c */
int		mini_pwd(void);

/* mini_unset.c */
int		mini_unset(t_lst **env_lst, char *argv[]);

/* mini_export.c */
int		mini_export(t_lst **env_lst, char *argv[]);

/* mini_env.c */
int		mini_env(t_lst *env_lst);

/* mini_cd.c */
int		mini_cd(char **argv, t_lst *env_list);

/* mini_exit.c */
int		mini_exit(char **argv);

/* execute_func.c */
void	execute_path(t_cmd *cmd, t_cmd *prev, char **env_arr, char **path_arr);

#endif
