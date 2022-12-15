/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okirca <okirca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:33:23 by okirca            #+#    #+#             */
/*   Updated: 2022/12/15 18:33:23 by okirca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 2

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_find(buffer);
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	int		count;
	char	*buff;

	count = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(buff, '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		//printf("%s",buff);
		if (count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[count] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0; 
	if (buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		i++;
	}
	if (buffer[i] == '\n')
		line = ft_substr(buffer, 0, i + 1);
	else
		line = ft_substr(buffer, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_find(char *buffer)
{
	char	*buff;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	buff = ft_substr(buffer, i, (ft_strlen(buffer) - i));
	if (!buff)
		return (NULL);
	free(buffer);
	return (buff);
}
#include <fcntl.h>
#include <_stdio.h>

int main(){
	char *line;
	int fd;
	int i;

	fd = open("b.txt", O_RDONLY, 0777);
	i = 0;
	while(i< BUFFER_SIZE)
	{
		line = get_next_line(fd);
		printf("%d",fd);
		printf("%s",line);
		i++;
	}
	line = get_next_line(fd);
	printf("%s",line);
}