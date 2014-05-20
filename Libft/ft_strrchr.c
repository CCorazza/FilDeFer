/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 05:43:36 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/20 05:16:55 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strrchr(const char *s, int c)
{
	char	a;
	int		i;

	i = 0;
	a = (char)c;
	while (s[i] != 0)
		i++;
	while ((s[i] != a) && i > 0)
		i--;
	if (s[i] == a)
		return ((char *)&s[i]);
	return (0);
}