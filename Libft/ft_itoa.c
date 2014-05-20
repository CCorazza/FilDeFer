/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 06:01:49 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/20 05:11:34 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_itoaextreme(char *str)
{
	int			n;
	int			i;

	n = 2147483647;
	i = 11;
	str = (char *)malloc(sizeof(char) * i);
	str[0] = '-';
	str[i--] = '\0';
	while (n != 0)
	{
		str[i--] = '0' + (n % 10);
		n = n / 10;
	}
	str[10]++;
	return (str);
}

char			*ft_itoa(int n)
{
	int			i;
	char		*str;
	int			temp;

	i = (n > 0) ? 0 : 1;
	str = (char *)malloc(sizeof(char) * i);
	if (n == -2147483648)
		return (ft_itoaextreme(str));
	temp = n;
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	str[0] = (n >= 0) ? '0' : '-';
	str[i--] = '\0';
	n = (n < 0) ? -n : n;
	while (n != 0)
	{
		str[i--] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}
