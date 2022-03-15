/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:06:43 by bypark            #+#    #+#             */
/*   Updated: 2021/07/12 14:07:41 by byungwook        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_len(long long n)
{
	int			cnt;

	cnt = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		cnt += 1;
	}
	return (cnt);
}

static void	make_str(char *str, int n, int cnt)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	while (nbr)
	{
		*(str + cnt - 1) = nbr % 10 + '0';
		nbr /= 10;
		cnt--;
	}
}

char	*ft_itoa(int n)
{
	int			cnt;
	char		*ret;

	cnt = cnt_len(n) + (n <= 0);
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!ret)
		return (0);
	ret[cnt] = '\0';
	if (n < 0)
		*ret = '-';
	if (n == 0)
		*ret = '0';
	make_str(ret, n, cnt);
	return (ret);
}
