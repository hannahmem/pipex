/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:06:01 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/28 13:14:58 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		i++;
	}
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	int	len;
	int	j;

	len = ft_strlen(s1);
	while (len > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[len - 1] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	int		len;
	char	*result;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	len = end - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (start < end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
	char *s1 = "asdHallos World!sas";
	char *set = "asd";
	char *trim;

	trim = ft_strtrim(s1, set);
	printf("%s\n", trim);
	free(trim);
	return (0);
}*/