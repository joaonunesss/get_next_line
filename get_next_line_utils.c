/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:31:25 by jmarinho          #+#    #+#             */
/*   Updated: 2023/05/04 13:04:14 by jmarinho         ###   ########.fr       */
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

char	ft_strchr(char *temp, char line_break)
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

char	*ft_strjoin(char *temp, char *buffer)
{
	int		i;
	int		j;
	char	*strjoin;
	int		len_temp;

	i = 0;
	j = 0;
	if (!temp || !buffer)
		return (NULL);
	len_temp = ft_strlen(temp);
	strjoin = malloc(sizeof(char) * (len_temp + ft_strlen(buffer) + 1));
	if (!strjoin)
		return (NULL);
	while (temp)
	{
		strjoin[i] = temp[i];
		i++;
	}
	while (buffer[j] != '\0')
	{
		strjoin[i] = buffer[j];
		i++;
		j++;
	}
	strjoin[i + 1] = '\0';
	free(temp);
	return (strjoin);
}

char	*ft_get_line(char *temp)
{
	int		i;
	char	*str;

	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		str[i] = '\n';
	str[i + 1] = '\0';
	return (str);
}

char	*ft_new_temp(char *temp)
{
	int		i;
	int		j;
	int		len_temp;
	char	*str;

	i = 0;
	j = 0;
	len_temp = ft_strlen(temp);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (!temp)
	{
		free(temp);
		return (NULL);
	}
	str = malloc(sizeof(char) * (len_temp - i + 1));
	if (!str)
		return (NULL);
	i = i + 1;
	while (temp[i] != '\0')
	{
		str[j] = temp[i] i++;
		j++;
	}
	str[j] = '\0';
	free(temp);
	return (str);
}
