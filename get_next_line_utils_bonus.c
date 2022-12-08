/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrivino <ctrivino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:57:57 by ctrivino          #+#    #+#             */
/*   Updated: 2022/12/08 17:10:11 by ctrivino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*pt;
	char	cst;

	if (s == NULL)
		return (0);
	pt = (char *)s;
	cst = (char )c;
	if (pt != NULL)
	{
		while (*pt)
		{
			if (*pt == cst)
				return (pt);
			pt++;
		}
		if (*pt == cst)
			return (pt);
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*strcp;
	size_t	lg;
	size_t	i;

	i = 0;
	lg = ft_strlen(s);
	strcp = malloc((lg * sizeof(*strcp)) + sizeof(*strcp));
	if (!(strcp))
	{
		return (NULL);
	}
	while (i < lg)
	{
		strcp[i] = s[i];
		i++;
	}
	strcp[lg] = '\0';
	return (strcp);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*strcp;
	size_t	i;
	size_t	lg;

	i = 0;
	lg = ft_strlen(s);
	if ((lg - start) < len && (lg - start) > 0)
		len = (lg - start);
	if (lg < len)
		len = lg;
	strcp = malloc((len * sizeof(*strcp)) + sizeof(*strcp));
	if (!(strcp))
		return (NULL);
	if (start < lg)
	{
		while (i < len && s[start + i])
		{
			strcp[i] = s[start + i];
			i++;
		}
	}
	strcp[i] = '\0';
	return (strcp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	if (s1 && s2)
		len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str = malloc(len * sizeof(*str));
	if (!(str) || ((!(s1)) && (!(s2))))
		return (NULL);
	while (s1 != NULL && *s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (s2 != NULL && *s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
