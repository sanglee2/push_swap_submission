/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:31:16 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/27 23:02:41 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stddef.h> // TODO: refactor//
// void push_bot_a(t_deq *deq_a, t_node *node)
// {
// 	// deq a가 비어있을 때.
// 	// top 과 bot 모두가 현재 노드를 가리킬 수 있도록.
// 	if (deq_a->a_size == 0)
// 	{
// 		deq_a->a_top = node;
// 		deq_a->a_bot = node;
// 	}
// 	else if (deq_a->a_size == 1)
// 	{
// 		deq_a->a_top->next = node;
// 		deq_a->a_bot = node;
// 		deq_a->a_bot->prev = deq_a->a_top;
// 	}
// 	else
// 	{
// 		deq_a->a_bot->next = node;
// 		node->prev = deq_a->a_bot;
// 		deq_a->a_bot = node;
// 	}
// 	deq_a->a_size++;
// }

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	word_count(char *str, char c)
{
	int	word_cnt;
	//size_t word_cnt;

	int	flag;

	word_cnt = 0;
	flag = 1;
	while (*str)
	{
		// 구분자 아니고 처음 들어가 flag가 1일 때만 단어개수 증가
		if (flag == 1 && *str != '\0' && *str != c)
		{
			word_cnt++;
			flag = 0;
		}
		else if (*str == '\0' || *str == c)
			flag = 1;
		str++;
	}
	return (word_cnt);
}

//문자열에서 구분자의 다음 주소(항목)를 가져오는 함수  
//word에 복사하는 함수
static char	*str_word_print(char *s, char c)
{
	char	*word;
	int		loc;
	int		i;

	loc = 0;
	i = 0;
	while (s[loc] != '\0' && s[loc] != c)
		loc++;
	word = (char *)malloc(sizeof(char) * (loc + 1));
	if (!word)
		return (0);
	while (s[i] != '\0' && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		len;

	len = word_count((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < len)
	{
		while (*s != '\0' && *s == c)
			s++;
		result[i] = str_word_print((char *)s, c);
		if (result[i] == 0)
		//if (result[i] == NULL)
		{
			while (--i >= 0)
				free(result[i]);
			free(result);
			return (0);
		}
		s = s + ft_strlen(result[i++]);
	}
	result[i] = NULL;
	return (result);
}

// t_deq* create()
// {
// 	t_deq *deq;
// 	deq = (t_deq *)malloc(sizeof(t_deq) * 1);

// 	return(deq);
// }

// void init_deq(t_deq *deq)
// {
// 	deq->a_top = 0;
// 	deq->a_bot = 0;
// 	deq->a_size = 0;
// 	deq->b_top = 0;
// 	deq->b_bot = 0;
// 	deq->b_size = 0;
// 	deq->arr = 0;
// }

// t_node* init_node(int arg)
// {
// 	t_node *node;
// 	node = (t_node *)malloc(sizeof(t_node) * 1);
// 	if (!node)
// 		return(0);
	
// 	node->prev = NULL;
// 	node->content = arg;
// 	node->index = 0;
// 	node->next = NULL;
// 	return (node);	
// }

t_deq *malloc_deq_a(void)
{
	t_deq* deq_a;

	deq_a = create();
	init_deq(deq_a);

	return(deq_a);
}

t_deq *malloc_deq_b(void)
{
	t_deq* deq_b;

	deq_b = create();
	init_deq(deq_b);

	return(deq_b);
}


// 실제 int값, 이중포인트 문자열을 넣어서 확인해줘봐.
t_deq *parse(int ac, char **av, int i) //i = 1, ac 개수 체크)
{
	char **temp;
	char **arr;
	int arg; // arg 지울 것
	t_node* node;
	t_deq* deq_a;

	// 세어주긴 세어주어야 하는 값?!

	//i = 1;

	// if (!*av[i])
	// {
	// 	printf("invalid input\n");
	// 	exit(0);
	// }
	
	deq_a = malloc_deq_a();
	while(i < ac)
	{

		arr = ft_split(av[i], ' ');
		temp = arr;
		// if(valid_input() == 0)
		// 	ft_error();
		while(*temp)
		{	
			// ft_atoi 내에서 먼저 유효성 검사
			arg = ft_atoi(*temp); //atoi로 정수로 바꾼 후 유효성 검사는 늦다!
			node = init_node(arg);
			push_bot_a(deq_a, node);	
			temp++;
		}
		//ft_free(temp);
		ft_free(arr);
		i++;
	}
	// ft_split에서 malloc해준 후에 free해주는 부분이 없지는 않은데..
	// arr malloc 부분이 필요는 한가?
	////free_all(arr);
	return(deq_a);
}

// int check_duplicate_arg(t_deq *deq)
// {
// 	t_node* temp1;
// 	t_node* temp2;
// 	temp1 = deq->a_top;

// 	while(temp1)
// 	{
// 		temp2 = temp1->next;
// 		while(temp2)
// 		{
// 			if (temp2->content == temp1->content)
// 				return(1);
// 			temp2 = temp2->next;
// 		}
// 		temp1 = temp1->next;
// 	}
// 	return (0);
// }

// int main(int ac, char *av[])
// {
//     // deq 구조체를 담는 변수 a, b 인스턴스화
//     // 어떤 자료구조 유리한지 - 선택이유
//     t_deq* deq_a;
//     t_deq* deq_b;

//     // argument 유효성 체크 부분
//     if (ac < 2)
//         return (0);
// 	deq_a = parse(ac,av,0);	
//     deq_b = NULL;

// 	if(check_duplicate_arg(deq_a) == 1)
// 	{
// 		ft_free(deq_a);
// 		return(0);
// 	}

//     // deq_a의 크기 구하기 <- 정렬 전.
//     deq_a->a_size = ft_deq_size(deq_a);
	
// 	// 이미 정렬이 되어있는지 아닌지 확인작업을 하는 부분.

//     // 정렬알고리즘 사용 정렬부분.
//     sort(deq_a, deq_b);

//     // deq을 free해주는 함수 - 동적메모리할당 했기 때문에 <- 논리적 이유.
//     free_deq(deq_a);
//     free_deq(deq_b);

//     return (0);
// }






// if(valid_input(av) == 0)
//     ft_error(); // error함수 호출
 
// // 두 deq 초기세팅
// // 초기화 <- 인수를 넣어 deq 구성한다는 의미
// deq_a = configuration_deq(ac, av);



// // save를 스택 초기화 할 때
// // save[i] 순회하면서 정수 -> stack.


// // save[j] - 배열에 대한 유효성 검사 필요!
// // 숫자, 숫자를 먼저 체크해야 하나? - 인자 유효성 검사 먼저 해줘야 하는가?

// int valid_input(char **arr)
// {
// 	// 유효성 체크
	




// 	// 숫자인지 체크해주는 부분.

// 	// 중복인지 아닌지 체크해주는 부분.
// 	if(check_duplicate_arg(av))
// 		return (0);

// }


