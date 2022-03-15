#include "minishell.h"

static int	syntax_error(t_token *token_list, int *in)
{
	t_token	*cursor;

	cursor = token_list;
	while (cursor)
	{
		if (cursor->type == REDIRECT1 || cursor->type == REDIRECT2 || \
		cursor->type == REDIRECT3 || cursor->type == REDIRECT4)
		{
			if (!cursor->next)
			{
				*in = -1;
				write(2, "minishell: systax error near \
unexpected token 'newline'\n", 60);
				g_status = 258;
				return (1);
			}
		}
		cursor = cursor->next;
	}
	return (0);
}

static void	validate_file(t_token *file, int in)
{
	if (in < 0)
	{
		write(2, "minishell: ", 12);
		write(2, file->next->content, ft_strlen(file->content));
		write(2, " : No such file or directory\n", 29);
		g_status = 1;
		return ;
	}
	g_status = 0;
	return ;
}

static void	excute_heredoc(t_token *token, int *in)
{
	int		temp_pipe[2];
	char	*input;

	if (*in != 0)
		close(*in);
	pipe(temp_pipe);
	input = readline("> ");
	while (input && ft_strcmp(input, token->next->content) != 0)
	{
		write(temp_pipe[1], input, ft_strlen(input));
		write(temp_pipe[1], "\n", 1);
		input = readline("> ");
	}
	close(temp_pipe[1]);
	*in = temp_pipe[0];
}

static void	check_type_connect_redirection(t_token *token, int *in, int *out)
{
	if (token->type == REDIRECT1)
	{
		if (*out != 1)
			close(*out);
		*out = open(token->next->content, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	}
	else if (token->type == REDIRECT2)
	{
		if (*in != 0)
			close(*in);
		*in = open(token->next->content, O_RDONLY);
		validate_file(token, *in);
	}
	else if (token->type == REDIRECT3)
	{
		if (*out != 1)
			close(*out);
		*out = open(token->next->content, O_WRONLY | O_APPEND | O_CREAT, 0644);
	}
	else if (token->type == REDIRECT4)
		excute_heredoc(token, in);
}

void	check_redirection(t_token *token_list, int *in, int *out)
{
	t_token	*cursor;

	cursor = token_list;
	if (syntax_error(cursor, in) == 1)
		return ;
	while (cursor && cursor->type != PIPE)
	{
		check_type_connect_redirection(cursor, in, out);
		cursor = cursor->next;
	}
}
