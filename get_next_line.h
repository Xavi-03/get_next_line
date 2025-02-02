/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:56:51 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/09 14:04:52 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>//Debugger

typedef struct s_list
{
	char			*text;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*ft_injector(t_list **list, char **buffer);
char	*ft_reader(int fd);
char	*ft_trimmer(char *str);
t_list	*ft_addnode(t_list **list, char *text);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strchr(char	*str);
int		ft_listlen(t_list *list);
int		ft_memorymanager(void **value, int size);

#endif
