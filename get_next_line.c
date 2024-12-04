/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:19:30 by maballet          #+#    #+#             */
/*   Updated: 2024/12/04 18:38:30 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	ssize_t	bytes_read;
	char	*line;
	char	*buffer;
	
	fd = open("test", O_RDONLY);
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	buffer[BUFFER_SIZE + 1];
	
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		printf("check");
		buffer[BUFFER_SIZE] = '\0';
		line = ft_strjoin(line, buffer);
		break ;
	}
	close(fd);
	return (line);
}
int	main(void)
{
	printf("%s", get_next_line(1));
}