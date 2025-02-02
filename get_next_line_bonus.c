/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:56:56 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/11/22 19:30:19 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*new_line;
	t_list		*list;
	t_list		*iteri;

	list = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (buffer[fd])
		ft_addnode(&list, buffer[fd]);
	iteri = list;
	while (!iteri || !ft_strchr(iteri->text))
	{
		iteri = ft_addnode(&list, ft_reader(fd));
		if (!iteri)
		{
			if (list)
				break ;
			return (NULL);
		}
	}
	new_line = ft_injector(&list, &buffer[fd]);
	return (ft_trimmer(new_line));
}

char	*ft_injector(t_list **list, char **buffer)
{
	char	*new_line;
	t_list	*iteri;

	iteri = *list;
	if (ft_memorymanager((void *)&new_line, (ft_listlen(*list) * BUFFER_SIZE)))
		return (NULL);
	if (ft_memorymanager((void **)&*buffer, BUFFER_SIZE))
		return (NULL);
	new_line[0] = '\0';
	while (iteri)
	{
		ft_strcpy(*buffer, ft_strcpy(new_line, iteri->text));
		iteri = iteri->next;
	}
	if (**buffer == '\0')
	{
		free(*buffer);
		*buffer = NULL;
	}
	ft_memorymanager((void **)&*list, 0);
	return (new_line);
}

char	*ft_reader(int fd)
{
	char	*new_line;
	int		readed;

	if (ft_memorymanager((void *)&new_line, BUFFER_SIZE))
		return (NULL);
	readed = read(fd, new_line, BUFFER_SIZE);
	if (readed < 1)
	{
		free(new_line);
		return (NULL);
	}
	new_line[BUFFER_SIZE] = '\0';
	return (new_line);
}

int	ft_memorymanager(void **value, int size)
{
	int		i;
	t_list	*iteri;

	if (size == 0)
	{
		while (*value)
		{
			iteri = *(t_list **)value;
			*(t_list **)value = iteri->next;
			free(iteri->text);
			free(iteri);
		}
		return (0);
	}
	i = 0;
	*value = malloc((size + 1) * sizeof(char));
	if (!*value)
		return (1);
	while (i < size)
	{
		((char *)*value)[i] = '\0';
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*next_line;
	int		fd;
	int		fd2;
	int		i;

	i = 1;
	if (argc > 2)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while (i < 1000)
		{
			next_line = get_next_line(fd);
			printf("\nfirst new line:%s$\n___________________\n\n", next_line);
			//if (!next_line)
			//	break ;
			free(next_line);
			next_line = get_next_line(fd2);
			printf("\nsecond new line:%s$\n___________________\n\n", next_line);
			//if (!next_line)
			//	break ;
			free(next_line);
			i++;
		}
		close(fd);
	}
	return (0);
}*/
