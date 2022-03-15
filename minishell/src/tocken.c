#include "minishell.h"

static int	is_operator(char c)
{
	if (c == ' ' || c == '>' || c == '<' || c == '|' || c == 0)
		return (1);
	else
		return (-1);
}

static void	quotes_row(char *input, int idx, int *len)
{
	if (input[idx + *len] == '\'')
	{
		(*len)++;
		while (input[idx + *len] != '\'')
			(*len)++;
		(*len)++;
	}
	else if (input[idx + *len] == '"')
	{
		(*len)++;
		while (input[idx + *len] != '"')
			(*len)++;
		(*len)++;
	}
}

void	make_token(char *input, int *idx, int *len, t_token **tokens)
{
	char	*content;
	t_token	*token;

	if (input[*idx] == ' ')
	{
		(*idx)++;
		*len = 0;
		return ;
	}
	if (*len == 0 && (input[*idx + *len] == '>' || \
	input[*idx + *len == '<'] || input[*idx + *len] == '|'))
	{
		while (input[*idx + *len] == '>')
			(*len)++;
		while (input[*idx + *len] == '<')
			(*len)++;
		while (input[*idx + *len] == '|')
			(*len)++;
	}
	content = ft_substr(input, *idx, *len);
	token = token_new(content);
	token_add(tokens, token);
	(*idx) += (*len);
	*len = 0;
}

t_token	*tokenize(char *input)
{
	int		idx;
	int		len;
	t_token	*tokens;

	idx = 0;
	len = 0;
	tokens = 0;
	while (input[idx])
	{
		if (is_operator(input[idx + len]) < 0)
		{
			if (input[idx + len] == '\'' || input[idx + len] == '"')
				quotes_row(input, idx, &len);
			else
				len++;
		}
		else
			make_token(input, &idx, &len, &tokens);
	}
	return (tokens);
}

void	set_token_type(t_token *tokens)
{
	t_token	*curr_token;
	t_token	*pre_token;

	curr_token = tokens;
	pre_token = 0;
	while (curr_token)
	{
		if (ft_strcmp(curr_token->content, ">") == 0)
			curr_token->type = REDIRECT1;
		else if (ft_strcmp(curr_token->content, "<") == 0)
			curr_token->type = REDIRECT2;
		else if (ft_strcmp(curr_token->content, ">>") == 0)
			curr_token->type = REDIRECT3;
		else if (ft_strcmp(curr_token->content, "<<") == 0)
			curr_token->type = REDIRECT4;
		else if (ft_strcmp(curr_token->content, "|") == 0)
			curr_token->type = PIPE;
		else
			curr_token->type = WORD;
		if (pre_token && pre_token->type > 0)
			curr_token->type = FILE;
		pre_token = curr_token;
		curr_token = curr_token->next;
	}
}
