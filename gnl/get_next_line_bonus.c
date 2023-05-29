/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:47:39 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/27 23:09:56 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//#include "push_swap.h"

t_list	*check_lst_storage(t_list *lst, char **ret, int fd)
{
	*ret = 0;
	while (fd != lst->fd)
	{
		if (lst->next == NULL)
		{
			lst->next = ft_lstnew(fd);
			if (!(lst -> next))
				return (NULL);
			(lst->next)->prev = (lst);
		}
		lst = lst->next;
	}
	// 저장되어있는 것도 update해주기. - lst의 storage에 있었던.
	if (lst->storage != NULL)
	{
		*ret = lst->storage;
		lst->storage = NULL;
	}
	return (lst);
}

int	check_ret(char **ret, t_list **lst, t_list **lst_fd, char **temp)
{
	*temp = ft_strchr(*ret, '\n');
	// 개행이 있으면,(개행까지 읽어오는 게 보통이니까)
	if (*temp)
	{
		// 개행 다음에 문자가 있는지, 없는지 체크
		if (*(++(*temp)))
		{
			// lst_fd->storage에 계속 붙여주는 작업.
			(*lst_fd)->storage = ft_strjoin((*lst_fd)->storage, *temp);
			if (!((*lst_fd)-> storage))
			{
				all_free(lst, ret);
				return (0);
			}
			**temp = '\0';
			// ret을 새로이 update 맨 뒤에 NULL을 붙여서
			*temp = ft_strjoin(*ret, NULL);
			if (!(*temp))
			{
				all_free(lst, ret);
				return (0);
			}
			free(*ret);
			*ret = *temp;
		}
		return (0);
	}
	// 개행이 없거나, 개행이 있었어도 그 다음 값이 없는 경우.
	return (1);
}

int	append_line(t_list **lst, char **ret, char *buf, ssize_t output)
{
	char	*addr;

	buf[output] = '\0';
	addr = ft_strjoin(*ret, buf);
	if (!addr)
	{
		all_free(lst, ret);
		return (1);
	}
	if (*ret)
		free(*ret);
	*ret = addr;
	return (0);
}

int	get_char(char **ret, t_list **lst_fd, int fd, t_list **lst)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	output;

	output = read(fd, buf, BUFFER_SIZE);
	if (output <= 0)
	{
		ft_free1(ret, lst_fd, output, lst);
		return (1);
	}
	else
		return (append_line(lst, ret, buf, output));
}

char	*get_next_line(int fd)
{
	// char* 에 하나하나씩 담는 역할.
	char			*ret;
	// static 정적변수의 역할
	// 문자열을 합치면서 저장할 포인터
	static t_list	*lst;
	t_list			*lst_fd;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	if (!lst)
	{
		lst = ft_lstnew(-1);
		if (!lst)
			return (NULL);
	}
	// fd에 맞는 lst찾는 작업.
	lst_fd = check_lst_storage(lst, &ret, fd);
	if (!(lst_fd))
	{
		// 있던 lst와 ret 전부 해제?
		all_free(&lst, &ret);
		return (NULL);
	}
	// temp들이 해주는 역할?, 역할?!
	while (check_ret(&ret, &lst, &lst_fd, &temp))
	{
		if (get_char(&ret, &lst_fd, fd, &lst))
			break ;
	}
	return (ret);
}

// int main(void)
// {
// 	char buf[BUFFER_SIZE + 1];
// 	char *save;
// 	int fd;
// 	int read_size;


// 	read_size = 0;
// 	fd = open("./test.txt", O_RDONLY);

// 	if (fd == -1)
// 		printf("error\n");
// 	else
// 	{
// 		read_size = read(fd, buf, BUFFER_SIZE);
// 		while(read_size > 0)
// 		{
// 			buf[read_size] = '\0';
// 			if(save == NULL)
// 				save = strdup(buf);
// 			else
// 				strcat(save, buf);
// 			read_size = read(fd, buf, BUFFER_SIZE);	
// 		}
// 		printf("%s", save);
// 		close(fd);
// 	}
// 	return (0);
// }
