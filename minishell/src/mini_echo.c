#include "minishell.h"

static void	print_echo(char **str, int flag)
{
    int     idx;
    int     len;

    idx = 0;
    while (str[idx])
    {
        len = ft_strlen(str[idx]);
        write(1, str[idx], len);
        if (str[idx + 1])
            write(1, " ", 1);
        idx++;
    }
    if (flag == 0)
        printf("\n");
}

static char    **process_split(char **split, int *flag)
{
    char    **av;

    if (!split)
        return (0);
    if (ft_strcmp(split[1], "-n") == 0 || check_multi_n(split[1]) == 1)
    {
        *flag = 1;
        av = &split[2];
    }
    else
    {
        av = &split[1];
    }
    return (av);
}

int	mini_echo(char *argv[])
{
    char    **split_str;
    int     n_flag;
    char    **real_av;

    n_flag = 0;
    split_str = ft_split(argv[0], ' ');
    if (argv[1] == 0)
    {
        if (!split_str[1])
            return (0);
        else
            real_av = process_split(split_str, &n_flag);
    }
    else
    {
		if (ft_strcmp(argv[0], "echo") != 0)
            real_av = process_split(split_str, &n_flag);
        else
            real_av = process_split(argv, &n_flag);
    }
    print_echo(real_av, n_flag);
    free_2_arr(split_str);
    return (0);
}