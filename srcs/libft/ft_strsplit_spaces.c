/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <rdu-toi@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:29:56 by rdu-toi           #+#    #+#             */
/*   Updated: 2019/09/14 12:01:37 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen_spaces(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && !ft_isspace(s[i]))
		i++;
	return (i);
}

static size_t	ft_strcount(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (!ft_isspace(s[i]))
		{
			i += ft_strlen_spaces(&s[i]) - 1;
			j++;
		}
		i++;
	}
	return (j);
}

char			**ft_strsplit_spaces(char const *s)
{
	size_t	i;
	size_t	len;
	size_t	k;
	char	**arr;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	len = ft_strcount(s);
	if (!(arr = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		if (!ft_isspace(s[i]))
		{
			arr[k++] = ft_strsub(s, i, ft_strlen_spaces(&s[i]));
			i += ft_strlen_spaces(&s[i]) - 1;
		}
		i++;
	}
	arr[k] = NULL;
	return (arr);
}
