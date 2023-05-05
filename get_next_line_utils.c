/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:31:25 by jmarinho          #+#    #+#             */
/*   Updated: 2023/05/05 11:34:54 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *temp, char line_break)
{
	int	i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == line_break)
			return (&temp[i]);
		i++;
	}
	return (0);
}

/*Primeiro if inicializa na primeira passagem */

char	*ft_strjoin(char *temp, char *buffer)
{
	int		i;
	int		j;
	char	*strjoin;

	i = -1;
	j = 0;
	if (!temp)
	{
		temp = malloc(sizeof(char) * 1);
		temp[0] = '\0';
	}
	if (!temp || !buffer)
		return (NULL);
	strjoin = malloc(sizeof(char) *((ft_strlen(temp) + ft_strlen(buffer)) + 1));
	if (!strjoin)
		return (NULL);
	while (temp[++i])
		strjoin[i] = temp[i];
	while (buffer[j])
		strjoin[i++] = buffer[j++];
	strjoin[i] = '\0';
	free(temp);
	return (strjoin);
}

char	*ft_get_line(char *temp)
{
	int		i;
	char	*str;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_temp(char *temp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!str)
		return (NULL);
	i = i + 1;
	while (temp[i])
		str[j++] = temp[i++];
	str[j] = '\0';
	free(temp);
	return (str);
}
