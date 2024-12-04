/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:19:30 by maballet          #+#    #+#             */
/*   Updated: 2024/12/04 19:31:32 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	ssize_t	bytes_read;
	char	*line;
	char	*buffer;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		// ici, le buffer se rempli bien, mais bytes_read prends rien.
		// alors que read renvoi 5,
		if (bytes_read <= 0)
		{
			// ne passe pas ici
			free(buffer);
			return (NULL);
		}
		// ne passe pas la
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		break ;
	}
	free(buffer);
	return (line);
}
int	main(void)
{
	int	fd;
	fd = open("test.txt",  O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}