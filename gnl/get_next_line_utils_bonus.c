/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:41 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/27 23:09:54 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//#include "push_swap.h"

t_list	*ft_lstnew(int fd)
{
	t_list	*node;

	node = (t_list *)malloc(1 * sizeof(t_list));
	if (!node)
		return (0);

	//malloc과 동시에 초기화 해주는 코드 동시에 작성.	
	node->fd = fd;
	node->storage = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		conv_c;

	i = 0;
	conv_c = (char)c;
	while (s && s[i] != '\0')
	{
		if (s[i] == conv_c)
			return ((char *)&s[i]);
		i++;
	}
	if (conv_c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	while (s1 && s1[len1] != '\0')
		len1++;
	while (s2 && s2[len2] != '\0')
		len2++;
	arr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!arr)
		return (0);
	len1 = 0;
	while (s1 && *s1)
		arr[len1 ++] = *(s1 ++);
	while (s2 && *s2)
		arr[len1 ++] = *(s2 ++);
	arr[len1] = 0;
	return (arr);
}

void	ft_free1(char **ret, t_list **lst_fd, ssize_t output, t_list **lst)
{
	if ((*lst_fd)->prev)
		((*lst_fd)->prev)->next = (*lst_fd)->next;
	if ((*lst_fd)->next)
		((*lst_fd)->next)->prev = (*lst_fd)->prev;
	free(*lst_fd);
	(*lst_fd) = 0;
	if ((*lst)->next == NULL)
	{
		free(*lst);
		*lst = 0;
	}	
	if (output == -1 && (*ret))
	{
		free(*ret);
		*ret = 0;
	}
}

void	all_free(t_list	**lst, char **ret)
{
	t_list	*temp;

	if (*ret)
	{
		free(*ret);
		*ret = NULL;
	}
	while ((*lst))
	{
		if ((*lst)->storage)
		{
			free((*lst)->storage);
			(*lst)->storage = NULL;
		}
		temp = (*lst)->next;
		free((*lst));
		*lst = temp;
	}
}
