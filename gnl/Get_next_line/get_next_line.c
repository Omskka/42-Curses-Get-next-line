/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:25:41 by marvin            #+#    #+#             */
/*   Updated: 2022/12/14 18:25:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*get_next_line(int fd)
{
	static char *Buffer;
	char *line;

	while (fd > 0 && BUFFER_SIZE > 0)
	{
		line = ft_read(fd,Buffer);
	}

}

char	*ft_read(int fd, char *Buffer)
{
	int count;
	char *buff;

	buff = malloc(BUFFER_SİZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	count = 1;
	count = read(fd, buff, BUFFER_SIZE);
	if (count == -1)
	{
		free(buff);
		return (NULL); 
	}
	buff[count] = '\0';
	buffer = ft_strjoin(buffer,buff);
	free (buff);
	return (buff);
}