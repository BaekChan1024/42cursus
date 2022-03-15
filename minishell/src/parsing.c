#include "minishell.h"

static int	is_valid_print(int c)
{
	if (c >= 0 && c <= 126)
		return (1);
	return (0);
}

void	change_env_and_quote(t_token *token, t_lst *env_lst)
{
	char	*content;
	int		idx;
	char	*temp;

	content = token->content;
	idx = 0;
	temp = 0;
	while (content[idx])
	{
		if (content[idx] == '\'')
			temp = cnt_join(temp, parse_quote(content, &idx), 0, 0);
		else if (content[idx] == '"')
			temp = cnt_join(temp, parse_dquote(content, &idx, env_lst), 0, 0);
		else
			temp = cnt_join(temp, parse_none(content, &idx, env_lst), 0, 0);
		idx++;
	}
	free(token->content);
	token->content = temp;
}

static void	tocken_converting(t_token **tokens, t_lst *env_lst)
{
	t_token	*token;

	token = *tokens;
	while (token)
	{
		change_env_and_quote(token, env_lst);
		token = token->next;
	}
}

t_cmd	*parsing(char *input, t_lst *env_lst)
{
	t_token	*tokens;
	t_cmd	*cmd;

	if (!input[0] || !is_valid_print(input[0]))
		return (0);
	if (!is_valid_quote(input))
	{
		printf("quote error\n");
		return (0);
	}
	tokens = 0;
	tokens = tokenize(input);
	tocken_converting(&tokens, env_lst);
	set_token_type(tokens);
	cmd = init_cmd(tokens);
	free_token(tokens);
	return (cmd);
}
